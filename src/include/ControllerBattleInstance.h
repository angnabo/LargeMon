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
    string computerMove();
    int randomInRange(int, int);
    bool determineCounter(string *, string *);
    bool isGameOver();
    float getEnemyLargeMonCurrentHpPercent();
    float getPlayerLargeMonCurrentHpPercent();
    string getEnemyLargeMonName();
    string getPlayerLargeMonName();
    virtual ~ControllerBattleInstance();
private:
    LargeMon * player;
    LargeMon * computer;
    int playerSpecAttkCount;
    int computerSpecAttkCounter;
    ViewObserver * playerView;
    ViewObserver * enemyView;
    //LargeMon * playerPtr;
    bool isOver;
};


#endif //LARGEMON_BATTLEINSTANCE_H

