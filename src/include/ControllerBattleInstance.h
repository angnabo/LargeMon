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
    void computerMove();
    int randomInRange(int, int);
    bool determineCounter(string *, string *);
    string getEnemyLargeMonName();
    virtual ~ControllerBattleInstance();
private:
    LargeMon * player;
    LargeMon * computer;
    int playerSpecAttkCount;
    int computerSpecAttkCounter;
    ViewObserver * playerView;
    ViewObserver * enemyView;
    //LargeMon * playerPtr;
};


#endif //LARGEMON_BATTLEINSTANCE_H

