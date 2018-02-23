
using namespace std;
#ifndef LARGEMON_LARGEMON_H
#define LARGEMON_LARGEMON_H
#include <string>
#include <vector>
#include "Type.h"

class Largemon {
public:
    Largemon(const int *, const int *, const int *, const string *);

    Largemon(Largemon const &) = default;
    Largemon(Largemon&&) = default;
    Largemon& operator=(const Largemon&) = default;
    Largemon& operator=(Largemon&&) = default;

    ~Largemon();

    string getName() const;
    void takeDamage(int);
    void defend();
    virtual int specialAttack() const = 0;
    virtual int specialAbility() const = 0;
    virtual Type getType() const = 0;
    int getDamage();
    int getHp(){ return hp; }
    int getCurrentHp(){ return currentHp; }
    int getSize() { return size; }
    std::string getLastAction();
    void stun(int);
    void decrementStun();
    void unstun();
    bool isStunned();
    bool isPlayer();

    void takeTickDamage(int);
    void decrementTickCount();
    bool isTakingTickDamage();
    void applyTickDamage(int damage);

    void setAsPlayer();
    //string getType() { return type; }
    float getCurrentHpPercent();

    void attach(class Observer *);
    void notify();


protected:
    string name;
    int currentHp;
    int hp;
    int damage;
    int size;
    //string type; //make Type into class
    int couterLM;
    string description;
    string lastAction;
    bool isLmPlayer;
    vector<class Observer *> views;
    int tickDmgCount;
    int stunCount;


};

#endif