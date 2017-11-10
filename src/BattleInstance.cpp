//
// Created by angelica on 07/10/17.
//

#include <iostream>
#include <random>
#include "LargeMonGenerator.h"
#include "BattleInstance.h"
BattleInstance::BattleInstance() {
    LargeMonGenerator generator;

    playerSpecAttkCount = 0;
    computerSpecAttkCounter = 0;
    player = generator.generateLargeMon();
    computer = generator.generateLargeMon();
}

void BattleInstance::fight() {

    cout << "Player: health: " << player->getHp() << ", Damage: " <<
         player->getDamage() << ", Size: " << player->getSize() <<
         ", Type: " << player->getType() << endl;
    cout << "Computer: health: " << computer->getHp() << ", Damage: " <<
         computer->getDamage() << ", Size: " << computer->getSize() <<
         ", Type: " << computer->getType() << endl;

    while((player->getHp() > 0 && computer->getHp() > 0)){
        cout << "Enter command." << endl;
        int command;
        cin >> command;
        if (command != 1 && command != 2 && command != 3){
            cout << "Enter command." << endl;
            cin >> command;
        }
        switch(command){
            case 1: //attack
                computer->takeDamage(player->getDamage());
                cout << "Player dealt " << player->getDamage() << " to the enemy." << endl;
                cout << "Enemy health: " << computer->getHp() << endl;
                break;
            case 2: //defend1
                player->defend();
                cout << "Player healed for 20hp" << endl;
                break;
            case 3: //special attack
                if(playerSpecAttkCount == 0) {
                    string playerType = player->getType();
                    string computerType = computer->getType();
                    if (determineCounter(&playerType, &computerType)) {
                        computer->takeDamage(player->specialAttack());
                        cout << "Player used special attack for " << player->specialAttack() << endl;
                        playerSpecAttkCount++;
                    } else {
                        cout << "LargeMon is not a counter" << endl;
                    }
                } else {
                    cout << "Special Attack was already used" << endl;
                }
                break;
        }
        computerMove();
        if(computer->getHp() <= 0){
            cout << "Player wins.";
        }
        if(player->getHp() <= 0){
            cout << "Enemy wins.";
        }
    }
}

//to do: make in seperate class
int BattleInstance::randomInRange(int min, int max){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max);
    return (int) distr(eng);
}

void BattleInstance::computerMove() {
    int random = randomInRange(1, 4);
    if (random == 1){
        computer->defend();
        cout << "The enemy healed for 20 hp. Enemy hp is: " << computer->getHp() << endl;
    } else if (random == 2) {
        string playerType = player->getType();
        string computerType = computer->getType();
        if(determineCounter(&computerType, &playerType)) {
            if (computerSpecAttkCounter == 0) {
                player->takeDamage(computer->specialAttack());
                cout << "The enemy used the special attack for: " << computer->specialAttack() << endl;
                cout << "The player hp is: " << player->getHp() << endl;
                computerSpecAttkCounter++;
            }
        } else {
            player->takeDamage(computer->getDamage());
            cout << "The enemy attacked for " << computer->getDamage() << endl;
            cout << "Player hp is: " << player->getHp() << endl;
        }
    } else {
        player->takeDamage(computer->getDamage());
        cout << "The enemy attacked for " << computer->getDamage() << endl;
        cout << "Player hp is: " << player->getHp() << endl;
    }
}

bool BattleInstance::determineCounter(string * playerType, string * enemyType) {
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

BattleInstance::~BattleInstance() {

}



