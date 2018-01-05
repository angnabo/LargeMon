//
// Created by angelica on 11/11/17.
//

#include "ControllerBattleInstance.h"
#include <iostream>
#include <random>
#include "../utility/LargeMonGenerator.h"
#include "FileWriter.h"
#include <unistd.h>

ControllerBattleInstance::ControllerBattleInstance() {
    LargeMonGenerator generator;

    playerSpecAttkCount = 0;
    enemySpecAttkCounter = 0;
    player = generator.generateLargeMon();
    enemy = generator.generateLargeMon();
    playerArgs.push_back("Player");
    enemyArgs.push_back("Enemy");
    playerArgs.push_back("");
    enemyArgs.push_back("");


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
    string move = "";
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
    return move;
}

string ControllerBattleInstance::action(int * actionID) {
    string action = "";
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
            case 2: //special attack
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
            } break;

            default: break;
        }


    action += enemyMove();
    if(isEnemyDead()){
        playerArgs[1] = "Fainted";
    }else if(isPlayerDead()){
        playerArgs[1] = "Fainted";
    }
    turns++;
    notify(enemy, enemyArgs);
    notify(player, playerArgs);
    return (action.empty() ? getWinner() : action);
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

int ControllerBattleInstance::getTurns() {
    return turns;
}




