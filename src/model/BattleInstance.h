//
// Created by angelica on 11/11/17.
using namespace std;
#ifndef LARGEMON_CONTROLLERBATTLEINSTANCE_H
#define LARGEMON_CONTROLLERBATTLEINSTANCE_H

#include <string>
#include <vector>
#include "largemon/LargeMon.h"

class ControllerBattleInstance {
public:
    ControllerBattleInstance();
    string action(int *);
    string enemyMove();
    int randomInRange(int, int);
    bool determineCounter(string *, string *);
    bool isGameOver();
    bool isEnemyDead();
    bool isPlayerDead();
    int getPlayerCurrentHp();
    int getEnemyCurrentHp();
    int getTurns();
    float getEnemyLargeMonCurrentHpPercent();
    float getPlayerLargeMonCurrentHpPercent();
    string getEnemyLargeMonName();
    string getPlayerLargeMonName();
    string getWinner();
    virtual ~ControllerBattleInstance();

    void attach(class ContrObserver *);
    void notify(LargeMon *, vector<string>);
private:
    LargeMon * player;
    LargeMon * enemy;
    int playerSpecAttkCount;
    int enemySpecAttkCounter;
    int turns;
    vector<string> playerArgs;
    vector<string> enemyArgs;
    //FileWriter * playerWriter;
    //FileWriterObserver * enemyWriter;
    //LargeMon * playerPtr;
    bool isOver;
    vector<class ContrObserver *> views;
};


#endif

