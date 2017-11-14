//
// Created by angelica on 11/11/17.
//

#include "../include/ControllerBattleInstance.h"
#include <iostream>
#include <random>
#include "../include/LargeMonGenerator.h"


ControllerBattleInstance::ControllerBattleInstance() {
    LargeMonGenerator generator;

    playerSpecAttkCount = 0;
    enemySpecAttkCounter = 0;
    player = generator.generateLargeMon();
    enemy = generator.generateLargeMon();

    playerView = new ViewObserver(player);
    enemyView = new ViewObserver(enemy);

    isOver = false;
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
    if (random == 1){
        enemy->defend();
        move = "The enemy healed for 20 hp. Enemy hp is: " + to_string(enemy->getCurrentHp());
    } else if (random == 2) {
        string playerType = player->getType();
        string enemyType = enemy->getType();
        if(determineCounter(&enemyType, &playerType)) {
            if (enemySpecAttkCounter == 0) {
                player->takeDamage(enemy->specialAttack());
                move = "The enemy used the special attack for: " + to_string(enemy->specialAttack());
                enemySpecAttkCounter++;
            }
        } else {
            player->takeDamage(enemy->getDamage());
            move = "The enemy attacked for " + to_string(enemy->getDamage());
        }
    } else {
        player->takeDamage(enemy->getDamage());
        if(isPlayerDead()){
            move = getWinner();
        } else {
            move = "The enemy attacked for " + to_string(enemy->getDamage()) + ". The player hp is: " + to_string(playerView->getCurrentHp());
        }
    }
    return move;
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
    float hpPercent = (float)enemyView->getCurrentHp()/(float)enemy->getHp();
    return hpPercent;
}

float ControllerBattleInstance::getPlayerLargeMonCurrentHpPercent(){
    float hpPercent = (float)playerView->getCurrentHp()/(float)player->getHp();//25/50*100
    return hpPercent;
}

int ControllerBattleInstance::getPlayerCurrentHp(){
    return playerView->getCurrentHp();
}
int ControllerBattleInstance::getEnemyCurrentHp() {
    return enemyView->getCurrentHp();
}

ControllerBattleInstance::~ControllerBattleInstance() {

}

string ControllerBattleInstance::action(int * actionID) {

    string action = "";

    if(!isGameOver()) {
        switch (*actionID) {
            case 0: //attack
                enemy->takeDamage(player->getDamage());
                if(isEnemyDead()){
                    return getWinner();
                } else {
                    action = "Player dealt " + to_string(player->getDamage()) + " to the enemy. " + enemyMove();
                }
                break;
            case 1: //defend1
                player->defend();
                action = "Player healed for 20hp. " + enemyMove();
                break;
            case 2: {//special attack
                if (playerSpecAttkCount == 0) {
                    string playerType = player->getType();
                    string enemyType = enemy->getType();
                    if (determineCounter(&playerType, &enemyType)) {
                        enemy->takeDamage(player->specialAttack());
                        action = "Player used special attack for " + to_string(player->specialAttack()) + " damage. " + enemyMove();
                        playerSpecAttkCount++;
                        enemyMove();
                    } else {
                        action = "LargeMon is not a counter";
                    }
                } else {
                    action = "Special Attack was already used";
                }
                break;
            }
            default:break;
        }
    }
    return (action.empty() ? getWinner() : action);
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




