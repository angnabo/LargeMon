//
// Created by angelica on 04/01/18.
//

#include "Test.h"

void Test::test(){

    wr = new FileWriter(&battle);

    int i = 0;
    while(!battle.isGameOver()){
        battle.playerMove(i);
    }
}