//
// Created by angelica on 04/01/18.
//

#include "Test.h"

void Test::test(){

    wr = new FileWriter(&battle);
    Largemon * player = battle.getPlayerPtr();
    Largemon * enemy = battle.getEnemyPtr();

    int i = 0;
    while(!battle.isGameOver()){
        battle.playerMove(i);
    }

    battle.playerMove(1);
    if(enemy->getCurrentHp() == (enemy->getHp()-player->attack())){
        cout << "Passed test 1.";
    } else {
        cout << "Failed test 1";
    }


}