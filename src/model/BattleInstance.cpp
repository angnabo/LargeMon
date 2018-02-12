//
// Created by angelica on 11/11/17.
//

#include "BattleInstance.h"
#include <iostream>
#include <random>
#include "LargeMonGenerator.h"
#include "utility/FileWriter.h"
#include "utility/HealthObserver.h"
#include <unistd.h>

BattleInstance::BattleInstance() {
    LargeMonGenerator generator;

    playerSpecAttkCount = 0;
    enemySpecAttkCounter = 0;
    player = generator.generateLargeMon();
    enemy = generator.generateLargeMon();

    player->setAsPlayer();

    playerArgs.push_back("Player");
    enemyArgs.push_back("Enemy");
    playerArgs.push_back("");
    enemyArgs.push_back("");
    round = 0;
    isOver = false;
}


inline void delay( unsigned long ms )
{
    usleep( ms * 1000 );
}

string BattleInstance::enemyMove() {
    delay(600);
    string move = "";
    if(!isGameOver() && !enemy->isStunned()) {
        int random = RandomNumber::randomInRange(1, 6);
        switch (random) {
            case 1: //Defend
                move = defend(enemy);
                break;
            case 2: //Special Attack
            {
                if (determineCounter(enemy, player)) {
                    if (enemySpecAttkCounter == 0) {
                        player->takeDamage(enemy->specialAttack());
                        move = "The enemy used the special attack for: " + to_string(enemy->specialAttack());
                        enemyArgs[1] = "Special Attack";
                        enemySpecAttkCounter++;
                    }
                } else {
                    move = attack(enemy);
                }
            }
                break;
            case 3: //special ability
            {
                move = specialAbility(enemy);
                playerArgs[1] = "Stunned";
            } break;
            default: //Attack
                move = attack(enemy);
                break;
        }
    }
    finishTurn(enemy);
    return move;
}

string BattleInstance::action(int * actionID) {
    string action = "";
    if(!isGameOver() && !player->isStunned()) {
        switch (*actionID) {
            case 0: //attack
                action = attack(player);
                playerArgs[1] = "Attack";
                break;
            case 1: //defend
                action = defend(player);
                break;
            case 2: //special attack 1
            {
                if (playerSpecAttkCount == 0) {
                    if (determineCounter(player, enemy)) {
                        enemy->takeDamage(player->specialAttack());
                        action = "Player used special attack for " + to_string(player->specialAttack()) + " damage. ";
                        playerArgs[1] = "Special Attack";
                        playerSpecAttkCount++;
                    } else {
                        action = "LargeMon is not a counter";
                    }
                } else {
                    action = "Special Attack was already used";
                    attack(player);
                }
            }
                break;
            case 3: //special ability
            {
                action = specialAbility(player);
                enemyArgs[1] = "Stunned";
            }
            default:
                break;
        }
    }

    finishTurn(player);

    action += enemyMove();
    if(isEnemyDead()){
        playerArgs[1] = "Fainted";
    }else if(isPlayerDead()){
        playerArgs[1] = "Fainted";
    }
    round++;
    notify(player, playerArgs);
    notify(enemy, enemyArgs);
    return (action.empty() ? getWinner() : action);
}

void BattleInstance::specialAttack(LargeMon * lm) {

}

void BattleInstance::finishTurn(LargeMon * lm){
    lm->decrementStun();
    LargeMon * en = getEnemyOf(lm);
    en->applyTickDamage(10);
    if(lm->getType() == Type::water){
        dynamic_cast<WaterLM*>(lm)->decrementShield();
    }
}

string BattleInstance::specialAbility(LargeMon * lm) {
    string action;
    Type largemon = lm->getType();
    LargeMon * en = getEnemyOf(lm);

    switch(largemon){
        case Type::fire :
            en->takeTickDamage(3);
            action = lm->isPlayer() ? "Your largemon is damaging enemy over time. " : "You are being damaged over time. ";
        break;
        case Type::water : {
            WaterLM *wlm = dynamic_cast<WaterLM *> (lm);
            wlm->shield(3);
            action = lm->isPlayer() ? "Your largemon shielded. " : "Enemy largemon shielded. ";
        }
        break;
        case Type::wood :
            en->stun(2);
            action = lm->isPlayer() ? "Enemy largemon was stunned. " : "Your largemon was stunned. ";
        break;
    }
    return action;
}
/**
 * Damages the given largemon's enemy
 * @param lm the largemon attacking
 */
string BattleInstance::attack(LargeMon * lm){
    LargeMon * en = getEnemyOf(lm);
    en->takeDamage(lm->getDamage());
    string action;
    if(lm->isPlayer()){
        action = "Player attacked the enemy for " + to_string(lm->getDamage()) + " damage. ";
        playerArgs[1] = "Attack";
    } else {
        action = "Enemy dealt " + to_string(lm->getDamage()) + " to your largemon. ";
        enemyArgs[1] = "Attack";
    }
    return action;
}

string BattleInstance::defend(LargeMon * lm) {
    lm->defend();
    string action;
    if(lm->isPlayer()){
        action = "Player healed for 20 hp. ";
        playerArgs[1] = "Defend";
    } else {
        action = "Enemy healed for 20 hp. ";
        enemyArgs[1] = "Defend";
    }
    return action;
}

bool BattleInstance::determineCounter(LargeMon * lm, LargeMon * lmEnemy) {
    Type largemon = lm->getType();
    Type enemy = lmEnemy->getType();

    bool counter;
    switch(largemon){
        case Type::water :
            if(enemy == Type::fire)
                counter = true;
        case Type::fire :
            if(enemy == Type::wood)
                counter = true;
        case Type::wood :
            if(enemy == Type::water)
                counter = true;
    }

    return counter;
}

LargeMon * BattleInstance::getEnemyOf(LargeMon * lm) {
    if(lm == player){
        return enemy;
    } else {
        return player;
    }
}



string BattleInstance::getEnemyLargeMonName(){
    string name = enemy->getName();
    return name;
}

string BattleInstance::getPlayerLargeMonName(){
    string name = player->getName();
    return name;
}

float BattleInstance::getEnemyLargeMonCurrentHpPercent(){
    float hpPercent = (float)enemy->getCurrentHp()/(float)enemy->getHp();
    return hpPercent;
}

float BattleInstance::getPlayerLargeMonCurrentHpPercent(){
    float hpPercent = (float)player->getCurrentHp()/(float)player->getHp();//25/50*100
    return hpPercent;
}

int BattleInstance::getPlayerCurrentHp(){
    return player->getCurrentHp();
}
int BattleInstance::getEnemyCurrentHp() {
    return enemy->getCurrentHp();
}

BattleInstance::~BattleInstance() {

}

bool BattleInstance::isGameOver() {
    return isPlayerDead() || isEnemyDead();
}

bool BattleInstance::isPlayerDead() {
    return player->getCurrentHp() <= 0;
}

bool BattleInstance::isEnemyDead() {
    return enemy->getCurrentHp() <= 0;
}

string BattleInstance::getWinner() {
    return (isEnemyDead() ? "Player Won!" : "Enemy Won!");
}

void BattleInstance::attach(class ContrObserver * obs) {
    views.push_back(obs);
}

void BattleInstance::notify(LargeMon * lm, vector<string> args) {
    for (int i = 0; i < views.size(); i++) {
        views[i]->update(lm, args);
    }
}

int BattleInstance::getRound() {
    return round;
}

LargeMon * BattleInstance::getPlayerPtr() {
    return player;
}

LargeMon * BattleInstance::getEnemyPtr() {
    return enemy;
}


