//
// Created by angelica on 11/11/17.
//

#include "BattleInstance.h"
#include <iostream>
#include <random>
#include "LargemonGenerator.h"
#include "utility/FileWriter.h"
#include "utility/HealthBarObserver.h"
#include <unistd.h>

BattleInstance::BattleInstance() {
    LargemonGenerator generator;

    playerSpecAttkCount = 0;
    enemySpecAttkCount = 0;
    player = generator.generateLargemon();
    enemy = generator.generateLargemon();

    player->setAsPlayer();

    playerArgs.push_back("Player");
    enemyArgs.push_back("Enemy");
    playerArgs.push_back("");
    enemyArgs.push_back("");
    round = 0;
}


inline void delay( unsigned long ms )
{
    usleep( ms * 1000 );
}

string BattleInstance::enemyMove() {
    delay(600);
    int actionID = RandomNumber::randomInRange(0, 6);
    if(enemy->getCurrentHpPercent()*100 < 35){
        actionID = RandomNumber::randomInRange(0, 1);
    }
    string action = move(enemy, actionID);
    finishTurn(enemy);
    return action;
}

string BattleInstance::move(Largemon * lm, int move){
    string action;
    if(!isGameOver() && !lm->isStunned()) {
        switch (move) {
            case 0: //attack
                action = attack(lm);
                setAttackArgs(lm);
                break;
            case 1: //defend
                action = defend(lm);
                break;
            case 2: //special attack
                action = specialAttack(lm);
                break;
            case 3: //special ability
                action = specialAbility(lm);
                enemyArgs[1] = "Stunned";
            default:
                action = attack(lm);
                setAttackArgs(lm);
        }
    }
    return action;
}

string BattleInstance::action(int actionID) {
    string action = move(player, actionID);
    action += enemyMove();
    finishTurn(player);

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

/*
 * Do a special attack for the given largemon
 */
string BattleInstance::specialAttack(Largemon * lm) {
    string action;
    Largemon * en = getEnemyOf(lm);
    if (isSpecAttack(lm)) {
        if (determineCounter(lm, en)) {
            en->takeDamage(lm->specialAttack());
            action = setSpecAttackArgs(lm);
        } else {
            action = lm->isPlayer() ? "Your largemon doesn't counter the enemy. It did a normal attack. "
                                    : "";
            attack(lm);
        }
    } else {
        action = lm->isPlayer() ? "Your largemon is exhausted. It did a normal attack. "
                                : "";
        attack(lm);
    }
    return action;
}

/*
 * Set the player or enemy arguments for special attack and return a message to display.
 */
string BattleInstance::setSpecAttackArgs(Largemon * lm){
    string action;
    if(lm->isPlayer()){
        action = "You used a powerful attack for " + to_string(player->specialAttack()) + " damage. ";
        playerArgs[1] = "Special Attack";
        playerSpecAttkCount++;
    } else {
        action = "Enemy used a powerful attack for " + to_string(enemy->specialAttack()) + " damage. ";
        enemyArgs[1] = "Special Attack";
        enemySpecAttkCount++;
    }
    return action;
}

/*
 * Sets the player or enemy arguments and return a message to display.
 */
string BattleInstance::setAttackArgs(Largemon * lm){
    string action;
    if(lm->isPlayer()){
        action = "You attacked for " + to_string(player->specialAttack()) + " damage. ";
        playerArgs[1] = "Attack";
    } else {
        action = "Enemy attacked for " + to_string(enemy->specialAttack()) + " damage. ";
        enemyArgs[1] = "Attack";
    }
    return action;
}

/*
 * Determine if the largemon can perform a special attack.
 */
bool BattleInstance::isSpecAttack(Largemon * lm){
    if(lm->isPlayer()){
        return playerSpecAttkCount == 0;
    } else {
        return enemySpecAttkCount == 0;
    }
}

void BattleInstance::finishTurn(Largemon * lm){
    lm->decrementStun();
    Largemon * en = getEnemyOf(lm);
    en->applyTickDamage(10);
    if(lm->getType() == Type::water){
        dynamic_cast<WaterLM*>(lm)->decrementShield();
    }
}

/*
 * Does the special attack for a given largemon against it's enemy.
 */
string BattleInstance::specialAbility(Largemon * lm) {
    string action;
    Type largemon = lm->getType();
    Largemon * en = getEnemyOf(lm);

    switch(largemon){
        case Type::fire :
            en->takeTickDamage(3);
            action = lm->isPlayer() ? "Your largemon is damaging enemy over time. " : "You are being damaged over time. ";
        break;
        case Type::water : {
            auto *wlm = dynamic_cast<WaterLM *> (lm);
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
/*
 * Damage the given largemon's enemy
 */
string BattleInstance::attack(Largemon * lm){
    string shieldAction;
    string action;
    Largemon * en = getEnemyOf(lm);
    if(en->getType() == Type::water){
        shieldAction = attackWaterLm(en, lm->getDamage());
    } else{
        en->takeDamage(lm->getDamage());
    }

    return setAttackArgs(lm) + shieldAction;
}
/*
 * Calc the shield amount.
 */
int BattleInstance::applyShield(int damage){
    return (damage/10);
}
/*
 * Attack a shielded water largemon
 */
string BattleInstance::attackWaterLm(Largemon * lm, int damage){
    string damageTaken = "";
    auto * waterlm = dynamic_cast<WaterLM *> (lm);
    if(waterlm->isShielded()){
        waterlm->takeDamage((damage-applyShield(damage)));
        damageTaken = waterlm->getName() + " shielded for " + to_string(applyShield(damage)) + " damage. ";
    } else{
        lm->takeDamage(damage);
    }
    return damageTaken;
}

/*
 * Defend the largemon by healing 20 hp.
 */
string BattleInstance::defend(Largemon * lm) {
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


/**
 * Determine if the largemon is a counter to the enemy.
 * @param lm
 * @param lmEnemy
 * @return
 */
bool BattleInstance::determineCounter(Largemon * lm, Largemon * lmEnemy) {
    Type largemon = lm->getType();
    Type enemy = lmEnemy->getType();
    bool counter = false;
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

Largemon * BattleInstance::getEnemyOf(Largemon * lm) {
    if(lm == player){
        return enemy;
    } else {
        return player;
    }
}

vector<string> * BattleInstance::getPlayerArgs(){
    return &playerArgs;
}

vector<string> * BattleInstance::getEnemyArgs(){
    return &enemyArgs;
}


string BattleInstance::getEnemyLargemonName(){
    string name = enemy->getName();
    return name;
}

string BattleInstance::getPlayerLargemonName(){
    string name = player->getName();
    return name;
}

float BattleInstance::getEnemyLargemonCurrentHpPercent(){
    float hpPercent = (float)enemy->getCurrentHp()/(float)enemy->getHp();
    return hpPercent;
}

float BattleInstance::getPlayerLargemonCurrentHpPercent(){
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

void BattleInstance::notify(Largemon * lm, vector<string> args) {
    for (int i = 0; i < views.size(); i++) {
        views[i]->update(lm, args);
    }
}

int BattleInstance::getRound() {
    return round;
}

Largemon * BattleInstance::getPlayerPtr() {
    return player;
}

Largemon * BattleInstance::getEnemyPtr() {
    return enemy;
}


