//
// Created by angelica on 11/11/17.
using namespace std;
#ifndef LARGEMON_CONTROLLERBATTLEINSTANCE_H
#define LARGEMON_CONTROLLERBATTLEINSTANCE_H

#include <string>
#include <vector>
#include "largemon/Largemon.h"

class BattleInstance {
public:
    BattleInstance();

    string action(int);

    string enemyMove();

    int randomInRange(int, int);

    bool determineCounter(Largemon *, Largemon *);

    bool isGameOver();

    bool isEnemyDead();

    bool isPlayerDead();

    int getPlayerCurrentHp();

    int getEnemyCurrentHp();

    int getRound();

    float getEnemyLargemonCurrentHpPercent();

    float getPlayerLargemonCurrentHpPercent();

    string getEnemyLargemonName();

    string getPlayerLargemonName();

    string getWinner();

    virtual ~BattleInstance();

    vector<string> *getPlayerArgs();

    vector<string> *getEnemyArgs();

    string defend(Largemon *lm);

    string attack(Largemon *lm);

    int applyShield(int damage);

    string specialAttack(Largemon *);

    string specialAbility(Largemon *);

    void finishTurn(Largemon *lm);

    Largemon *getPlayerPtr();

    Largemon *getEnemyPtr();

    Largemon *getEnemyOf(Largemon *);

    void attach(class ContrObserver *);

    void notify(Largemon *, vector<string>);

    string attackWaterLm(Largemon *to, int damage);

    bool isSpecAttack(Largemon *lm);

    string setSpecAttackArgs(Largemon *lm);

private:
    Largemon *player;
    Largemon *enemy;
    int playerSpecAttkCount;
    int enemySpecAttkCount;
    int round;
    vector<string> playerArgs;
    vector<string> enemyArgs;
    vector<class ContrObserver *> views;

    string move(Largemon *lm, int move);

    string setAttackArgs(Largemon *lm);
};


#endif

