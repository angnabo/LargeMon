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
    computerSpecAttkCounter = 0;
    player = generator.generateLargeMon();
    computer = generator.generateLargeMon();

//    ViewObserver playerView(player);
//    ViewObserver enemyView(computer);

    playerView = new ViewObserver(player);
    enemyView = new ViewObserver(computer);

    isOver = false;
}

void ControllerBattleInstance::fight() {
//
//    ViewObserver playerView(player);
//    ViewObserver enemyView(computer);
//
//    cout << "Player: health: " << player->getHp() << ", Damage: " <<
//         player->getDamage() << ", Size: " << player->getSize() <<
//         ", Type: " << player->getType() << endl;
//    cout << "Computer: health: " << computer->getHp() << ", Damage: " <<
//         computer->getDamage() << ", Size: " << computer->getSize() <<
//         ", Type: " << computer->getType() << endl;
//
//    while((player->getHp() > 0 && computer->getHp() > 0)){
//        cout << "Enter command." << endl;
//        int command;
//        cin >> command;
//        if (command != 1 && command != 2 && command != 3){
//            cout << "Enter command." << endl;
//            cin >> command;
//        }
//        switch(command){
//            case 1: //attack
//                computer->takeDamage(player->getDamage());
//                cout << "Player dealt " << player->getDamage() << " to the enemy." << endl;
//                //cout << "Enemy health: " << computer->getHp() << endl;
//                break;
//            case 2: //defend1
//                player->defend();
//                cout << "Player healed for 20hp" << endl;
//                break;
//            case 3: //special attack
//                if(playerSpecAttkCount == 0) {
//                    string playerType = player->getType();
//                    string computerType = computer->getType();
//                    if (determineCounter(&playerType, &computerType)) {
//                        computer->takeDamage(player->specialAttack());
//                        cout << "Player used special attack for " << player->specialAttack() << endl;
//                        playerSpecAttkCount++;
//                    } else {
//                        cout << "LargeMon is not a counter" << endl;
//                    }
//                } else {
//                    cout << "Special Attack was already used" << endl;
//                }
//                break;
//        }
//        computerMove();
//        if(computer->getHp() <= 0){
//            cout << "Player wins.";
//        }
//        if(player->getHp() <= 0){
//            cout << "Enemy wins.";
//        }
//    }
}

//to do: make in seperate class
int ControllerBattleInstance::randomInRange(int min, int max){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max);
    return (int) distr(eng);
}

string ControllerBattleInstance::computerMove() {
    string move = "";
    int random = randomInRange(1, 4);
    if (random == 1){
        computer->defend();
        move = "The enemy healed for 20 hp. Enemy hp is: " + to_string(computer->getCurrentHp());
        cout << "The enemy healed for 20 hp. Enemy hp is: " << computer->getHp() << endl;
    } else if (random == 2) {
        string playerType = player->getType();
        string computerType = computer->getType();
        if(determineCounter(&computerType, &playerType)) {
            if (computerSpecAttkCounter == 0) {
                player->takeDamage(computer->specialAttack());
                move = "The enemy used the special attack for: " + to_string(computer->specialAttack());
                cout << "The enemy used the special attack for: " << computer->specialAttack() << endl;
                //cout << "The player hp is: " << player->getHp() << endl;
                computerSpecAttkCounter++;
            }
        } else {
            player->takeDamage(computer->getDamage());
            move = "The enemy attacked for " + to_string(computer->getDamage());
            cout << "The enemy attacked for " << computer->getDamage() << endl;
            //cout << "Player hp is: " << player->getHp() << endl;
        }
    } else {
        player->takeDamage(computer->getDamage());
        move = "The enemy attacked for " + to_string(computer->getDamage()) + ". The player hp is: " + to_string(playerView->getCurrentHp());
        cout << "The enemy attacked for " << computer->getDamage() << endl;
        //cout << "Player hp is: " << player->getHp() << endl;
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
    string name = computer->getName();
    return name;
}

string ControllerBattleInstance::getPlayerLargeMonName(){
    string name = player->getName();
    return name;
}

float ControllerBattleInstance::getEnemyLargeMonCurrentHpPercent(){
    float hpPercent = playerView->getCurrentHp()/player->getHp();
    cout << "enemy percent " << to_string(hpPercent);
    return hpPercent;
}

float ControllerBattleInstance::getPlayerLargeMonCurrentHpPercent(){
    float hpPercent = (float)playerView->getCurrentHp()/(float)player->getHp();//25/50*100
    cout << "hp " << player->getHp();
    cout << "current hp" << playerView->getCurrentHp();


    cout << "player percent " << hpPercent;
    return hpPercent;
}

ControllerBattleInstance::~ControllerBattleInstance() {

}

string ControllerBattleInstance::action(int * actionID) {

    if(!isGameOver()) {

        string action = "";

//        cout << "Player Type: " << player->getType() << ", Health: " << playerView->getCurrentHp()
//             << ", Damage: " << player->getDamage() << ", Size: " << player->getSize() << endl << "\n";
//        cout << "Enemy Type: " << computer->getType() << ", Health: " << enemyView->getCurrentHp()
//             << ", Damage: " << computer->getDamage() << ", Size: " << computer->getSize() << endl << "\n";
//        cout << "Enter command." << endl;
//        int command;
//        cin >> command;
//        if (command != 1 && command != 2 && command != 3){
//            cout << "Enter command." << endl;
//            cin >> command;
//        }
        if (player->getCurrentHp() <= 0) {
            cout << "Enemy wins.";
            action = "Enemy wins!";
            isOver = true;
            return action;
        }
        switch (*actionID) {
            case 0: //attack
                action = "Player dealt " + to_string(player->getDamage()) + " to the enemy. " + computerMove();
                cout << "Player dealt " << player->getDamage() << " to the enemy." << endl << "\n";
                computer->takeDamage(player->getDamage());

                break;
            case 1: //defend1
                player->defend();
                action = "Player healed for 20hp. " + computerMove();
                cout << "Player healed for 20hp" << endl << "\n";
                computerMove();
                break;
            case 2: {//special attack
                if (playerSpecAttkCount == 0) {
                    string playerType = player->getType();
                    string computerType = computer->getType();
                    if (determineCounter(&playerType, &computerType)) {
                        computer->takeDamage(player->specialAttack());
                        action = "Player used special attack for " + to_string(player->specialAttack()) + " damage. " + computerMove();
                        cout << "Player used special attack for " << player->specialAttack() << endl << "\n";;
                        playerSpecAttkCount++;
                        computerMove();
                    } else {
                        action = "LargeMon is not a counter";
                        cout << "LargeMon is not a counter" << endl << "\n";
                        break;
                    }
                } else {
                    action = "Special Attack was already used";
                    cout << "Special Attack was already used" << endl << "\n";
                    break;
                }
                break;
            }
            default:break;
        }
        if (computer->getCurrentHp() <= 0) {
            cout << "Player wins.";
            action = "Player wins!";
            isOver = true;
            return action;
        }

        return action;
    }
}

bool ControllerBattleInstance::isGameOver() {
    return isOver;
}



