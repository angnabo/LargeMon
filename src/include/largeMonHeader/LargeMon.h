#include <string>
#include <vector>
#include "../Observer.h"

using namespace std;

#ifndef LARGEMON_LARGEMON_H
#define LARGEMON_LARGEMON_H

class LargeMon {
public:
    LargeMon(const int *, const int *, const int *, const string *);

    LargeMon(LargeMon const &) = default;
    LargeMon(LargeMon&&) = default;
    LargeMon& operator=(const LargeMon&) = default;
    LargeMon& operator=(LargeMon&&) = default;

    ~LargeMon();

    string getName() const;
    void takeDamage(int);
    void defend();
    virtual int specialAttack() const = 0;
    virtual string getType() const = 0;
    int getDamage(){ return damage; }
    int getHp(){ return hp; }
    int getCurrentHp(){ return currentHp; }
    int getSize() { return size; }
    //string getType() { return type; }

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
    vector<class Observer *> views;
};


#endif
