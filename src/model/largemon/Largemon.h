/**
 * Defines a largemon
 */
#ifndef LARGEMON_LARGEMON_H
#define LARGEMON_LARGEMON_H

#include <string>
#include <vector>
#include "Type.h"

using namespace std;

class Largemon {
public:
    Largemon(const int *, const int *, const int *, const string *);

    Largemon(Largemon const &) = default;

    Largemon(Largemon &&) = default;

    Largemon &operator=(const Largemon &) = default;

    Largemon &operator=(Largemon &&) = default;

    ~Largemon();

    string getName() const;

    void takeDamage(int);

    void defend();

    int specialAttack();

    virtual Type getType() const = 0;

    int attack();

    int getHp() { return maxHp; }

    int getCurrentHp() { return currentHp; }

    int getSize() { return size; }

    void stun(int);

    void decrementStun();

    bool isStunned();

    bool isPlayer();

    void takeTickDamage(int);

    void decrementTickCount();

    bool isTakingTickDamage();

    void applyTickDamage(int damage);

    void setAsPlayer();

    float getCurrentHpPercent();

    void attach(class Observer *);

    void notify();
protected:
    string name;
    int currentHp;
    int maxHp;
    int damage;
    int size; // how big the largemon is
    bool isLmPlayer;
    vector<class Observer *> views;
    int tickDmgCount = 0;
    int stunCount = 0;
};

#endif