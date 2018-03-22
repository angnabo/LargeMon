//
// Created by angelica on 11/11/17.
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include "largemon/Largemon.h"
#include "LargemonGenerator.h"

#ifndef LARGEMON_CONTROLLERBATTLEINSTANCE_H
#define LARGEMON_CONTROLLERBATTLEINSTANCE_H

using namespace std;

class BattleInstance {
public:
    BattleInstance();

    string playerMove(int);

    string enemyMove();

    bool determineCounter(Largemon *, Largemon *);

    bool isGameOver();

    bool isEnemyDead();

    bool isPlayerDead();

    int getPlayerCurrentHp();

    int getEnemyCurrentHp();

    int getRound();

    string getEnemyLargemonName();

    string getPlayerLargemonName();

    string getWinner();

    virtual ~BattleInstance();

    string defend(Largemon *lm);

    string normalAttack(Largemon *lm);

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

    string move(Largemon *lm, int move);

    string setAttackArgs(Largemon *lm);

    string playerOrEnemy(Largemon *lm, string args);

    void incrCounter(Largemon *lm, string count);

    void setArgsOfLargemon(Largemon *lm, string arg);

private:
    Largemon *player;
    Largemon *enemy;
    int playerSpecAttkCount;
    int enemySpecAttkCount;
    int playerStunCount;
    int enemyStunCount;
    int round;
    vector<string> playerArgs;
    vector<string> enemyArgs;
    vector<class ContrObserver *> views;
    int MAX_STUN_TUNRS = 2;
    int MAX_TICK_TURNS = 3;
    int MAX_SHIELD_TURNS = 3;
    int TICK_DAMAGE_PER_TURN = 10;


    bool isStun(Largemon *lm);
};


#endif

