//
// Created by angelica on 11/11/17.
//

#include "largeMonHeader/LargeMon.h"
#include "ViewObserver.h"

#ifndef LARGEMON_CONTROLLERBATTLEINSTANCE_H
#define LARGEMON_CONTROLLERBATTLEINSTANCE_H


class ControllerBattleInstance {
public:
    ControllerBattleInstance();
    void fight();
    string action(int *);
    string enemyMove();
    int randomInRange(int, int);
    bool determineCounter(string *, string *);
    bool isGameOver();
    bool isEnemyDead();
    bool isPlayerDead();
    int getPlayerCurrentHp();
    int getEnemyCurrentHp();
    float getEnemyLargeMonCurrentHpPercent();
    float getPlayerLargeMonCurrentHpPercent();
    string getEnemyLargeMonName();
    string getPlayerLargeMonName();
    string getWinner();
    virtual ~ControllerBattleInstance();
private:
    LargeMon * player;
    LargeMon * enemy;
    int playerSpecAttkCount;
    int enemySpecAttkCounter;
    ViewObserver * playerView;
    ViewObserver * enemyView;
    //LargeMon * playerPtr;
    bool isOver;

};


#endif //LARGEMON_BATTLEINSTANCE_H

