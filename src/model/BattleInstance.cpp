//
// Created by angelica on 11/11/17.
//

#include "BattleInstance.h"
#include <iostream>
#include <random>
#include "LargeMonGenerator.h"
#include "../utility/FileWriter.h"
#include "../utility/HealthObserver.h"
#include <unistd.h>

ControllerBattleInstance::ControllerBattleInstance() {
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

//to do: make in seperate class
int ControllerBattleInstance::randomInRange(int min, int max){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max);
    return (int) distr(eng);
}

string ControllerBattleInstance::enemyMove() {
    delay(600);
    string move = "";
    if(!isGameOver() && !enemy->isStunned()) {
        int random = randomInRange(1, 6);
        switch (random) {
            case 1: //Defend
                enemy->defend();
                move = "The enemy healed for 20 hp.";
                enemyArgs[1] = "Defend";
                break;
            case 2: //Special Attack
            {
                string playerType = player->getType();
                string enemyType = enemy->getType();
                if (determineCounter(&enemyType, &playerType)) {
                    if (enemySpecAttkCounter == 0) {
                        player->takeDamage(enemy->specialAttack());
                        move = "The enemy used the special attack for: " + to_string(enemy->specialAttack());
                        enemyArgs[1] = "Special Attack";
                        enemySpecAttkCounter++;
                    }
                } else {
                    player->takeDamage(enemy->getDamage());
                    enemyArgs[1] = "Attack";
                    move = "The enemy attacked for " + to_string(enemy->getDamage());
                }
            }
                break;
            case 3: //special ability
            {
                move = specialAbility(enemy);
                playerArgs[1] = "Stunned";
            } break;
            default: //Attack
                player->takeDamage(enemy->getDamage());
                if (isPlayerDead()) {
                    move = "";
                } else {
                    move = "The enemy attacked for " + to_string(enemy->getDamage());
                    enemyArgs[1] = "Attack";
                }
                break;
        }
    } else {
        finishTurn(enemy);
    }
    return move;
}

string ControllerBattleInstance::action(int * actionID) {
    string action = "";
    if(!isGameOver() && !player->isStunned()) {
        switch (*actionID) {
            case 0: //attack
                enemy->takeDamage(player->getDamage());
                action = "Player dealt " + to_string(player->getDamage()) + " to the enemy. ";
                playerArgs[1] = "Attack";
                break;
            case 1: //defend
                player->defend();
                action = "Player healed for 20hp. ";
                playerArgs[1] = "Defend";
                break;
            case 2: //special attack 1
            {
                if (playerSpecAttkCount == 0) {
                    string playerType = player->getType();
                    string enemyType = enemy->getType();
                    if (determineCounter(&playerType, &enemyType)) {
                        enemy->takeDamage(player->specialAttack());
                        action = "Player used special attack for " + to_string(player->specialAttack()) + " damage. ";
                        playerArgs[1] = "Special Attack";
                        playerSpecAttkCount++;
                    } else {
                        action = "LargeMon is not a counter";
                    }
                } else {
                    action = "Special Attack was already used";
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
    }else {
        finishTurn(player);
    }

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

void ControllerBattleInstance::specialAttack(LargeMon * lm) {

}

void ControllerBattleInstance::finishTurn(LargeMon * lm){
    lm->decrementStun();
    LargeMon * en = getEnemyOf(lm);
    if(en->isTakingTickDamage()){
        en->applyTickDamage(10);
    }
    if(lm->getType() == "water"){
        dynamic_cast<WaterLM*>(lm)->decrementShield();
        cout << "cast to watermon";
    }
}

string ControllerBattleInstance::specialAbility(LargeMon * lm) {
    string action;
    string type = lm->getType();
    LargeMon * en = getEnemyOf(lm);
    if(type == "fire"){
        en->takeTickDamage(3);
        action = lm->isPlayer() ? "Your largemon is damaging enemy over time. " : "You are being damaged over time. ";
    } else if(type == "water"){
        WaterLM * wlm = dynamic_cast<WaterLM*> (lm);
        wlm->shield(3);
        cout << "cast to watermon: " << lm->getType();
        action = lm->isPlayer() ? "Your largemon shielded. " : "Enemy largemon shielded. ";
    } else if(type == "wood"){
        en->stun(2);
        action = lm->isPlayer() ? "Enemy largemon was stunned. " : "Your largemon was stunned. ";
    }
    return action;
}




bool ControllerBattleInstance::determineCounter(string * playerType, string * enemyType) {
    bool isCounter = false;
    if(*playerType == "water" && *enemyType == "fire") {
        isCounter = true;
    } else if (*playerType == "fire" && *enemyType == "wood") {
        isCounter = true;
    } else if (*playerType == "wood" && *enemyType == "water") {
        isCounter = true;

    }
    return isCounter;
}

LargeMon * ControllerBattleInstance::getEnemyOf(LargeMon * lm) {
    if(lm == player){
        return enemy;
    } else {
        return player;
    }
}



string ControllerBattleInstance::getEnemyLargeMonName(){
    string name = enemy->getName();
    return name;
}

string ControllerBattleInstance::getPlayerLargeMonName(){
    string name = player->getName();
    return name;
}

float ControllerBattleInstance::getEnemyLargeMonCurrentHpPercent(){
    float hpPercent = (float)enemy->getCurrentHp()/(float)enemy->getHp();
    return hpPercent;
}

float ControllerBattleInstance::getPlayerLargeMonCurrentHpPercent(){
    float hpPercent = (float)player->getCurrentHp()/(float)player->getHp();//25/50*100
    return hpPercent;
}

int ControllerBattleInstance::getPlayerCurrentHp(){
    return player->getCurrentHp();
}
int ControllerBattleInstance::getEnemyCurrentHp() {
    return enemy->getCurrentHp();
}

ControllerBattleInstance::~ControllerBattleInstance() {

}

bool ControllerBattleInstance::isGameOver() {
    return isPlayerDead() || isEnemyDead();
}

bool ControllerBattleInstance::isPlayerDead() {
    return player->getCurrentHp() <= 0;
}

bool ControllerBattleInstance::isEnemyDead() {
    return enemy->getCurrentHp() <= 0;
}

string ControllerBattleInstance::getWinner() {
    return (isEnemyDead() ? "Player Won!" : "Enemy Won!");
}

void ControllerBattleInstance::attach(class ContrObserver * obs) {
    views.push_back(obs);
}

void ControllerBattleInstance::notify(LargeMon * lm, vector<string> args) {
    for (int i = 0; i < views.size(); i++) {
        views[i]->update(lm, args);
    }
}

int ControllerBattleInstance::getRound() {
    return round;
}

LargeMon * ControllerBattleInstance::getPlayerPtr() {
    return player;
}

LargeMon * ControllerBattleInstance::getEnemyPtr() {
    return enemy;
}






