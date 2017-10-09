//
// Created by angelica on 07/10/17.
//

#include <iostream>
#include "LargeMonGenerator.h"
#include "LargeMon.h"
#include "BattleInstance.h"
BattleInstance::BattleInstance() = default;

void BattleInstance::fight() {
    LargeMonGenerator generator;
    LargeMon player = generator.generateLargeMon();
    LargeMon computer = generator.generateLargeMon();

    cout << "Player: health: " << player.getHp() << ", Damage: " <<
         player.getDamage() << ", Size: " << player.getSize() << ", Type: " << player.getType() << endl;
    cout << "Computer: health: " << computer.getHp() << ", Damage: " <<
         computer.getDamage() << ", Size: " << computer.getSize() << ", Type: " << computer.getType() << endl;

    while((player.getHp() > 0 && computer.getHp() > 0)){
        cout << "Enter command." << endl;
        int command;
        cin >> command;
        if (command != 1 && command != 2){
            cout << "Enter command." << endl;
            cin >> command;
        }
        switch(command){
            case 1: //attack
                computer.recieveDamage(player.getDamage());
                cout << "Player dealt " << player.getDamage() << " to the enemy." << endl;
                cout << "Enemy health: " << computer.getHp() << endl;
                break;
            case 2: //defend
                player.defend();
                cout << "Player healed for 20hp" << endl;
                break;
            default:
                break;
        }
        if(computer.getHp() <= 0){
            cout << "Player wins.";
        }
    }
}