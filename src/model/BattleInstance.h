//
// Created by angelica on 11/11/17.
#include "../utility/FileWriter.h"
using namespace std;
#ifndef LARGEMON_BATTLEINSTANCE_H
#define LARGEMON_BATTLEINSTANCE_H
#include <iostream>
#include <random>
#include "../utility/LargemonGenerator.h"

#include <unistd.h>
#include <string>
#include <vector>
#include "largemon/Largemon.h"

class BattleInstance {
public:
    BattleInstance();
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
    int getTurns();
    float getEnemyLargemonCurrentHpPercent();
    float getPlayerLargemonCurrentHpPercent();
    string getEnemyLargemonName();
    string getPlayerLargemonName();
    void specialAbility(Largemon * dealer, Largemon * taker);
    string getWinner();
    virtual ~BattleInstance();

    void attach(class ContrObserver *);
    void notify(Largemon *, vector<string>);
private:
    Largemon * player;
    Largemon * enemy;
    int playerSpecAttkCount;
    int enemySpecAttkCounter;
    int turns;
    vector<string> playerArgs;
    vector<string> enemyArgs;
    //FileWriter * playerWriter;
    //FileWriterObserver * enemyWriter;
    //Largemon * playerPtr;
    bool isOver;
    vector<class ContrObserver *> views;

};


#endif

