//
// Created by angelica on 11/11/17.
using namespace std;
#ifndef LARGEMON_CONTROLLERBATTLEINSTANCE_H
#define LARGEMON_CONTROLLERBATTLEINSTANCE_H

#include <string>
#include <vector>
#include "largemon/LargeMon.h"


class BattleInstance {
public:
    BattleInstance();
    string action(int *);
    string enemyMove();
    int randomInRange(int, int);
    bool determineCounter(LargeMon *, LargeMon *);
    bool isGameOver();
    bool isEnemyDead();
    bool isPlayerDead();
    int getPlayerCurrentHp();
    int getEnemyCurrentHp();
    int getRound();
    float getEnemyLargeMonCurrentHpPercent();
    float getPlayerLargeMonCurrentHpPercent();
    string getEnemyLargeMonName();
    string getPlayerLargeMonName();
    string getWinner();
    virtual ~BattleInstance();

    void specialAttack(LargeMon *);
    string specialAbility(LargeMon *);

    void finishTurn(LargeMon *lm);

    LargeMon * getPlayerPtr();
    LargeMon * getEnemyPtr();

    LargeMon * getEnemyOf(LargeMon *);

    void attach(class ContrObserver *);
    void notify(LargeMon *, vector<string>);
private:
    LargeMon * player;
    LargeMon * enemy;
    int playerSpecAttkCount;
    int enemySpecAttkCounter;
    int round;
    vector<string> playerArgs;
    vector<string> enemyArgs;
    //FileWriter * playerWriter;
    //FileWriterObserver * enemyWriter;
    //LargeMon * playerPtr;
    bool isOver;
    vector<class ContrObserver *> views;

    string defend(LargeMon *lm);

    string attack(LargeMon *lm);
};


#endif

