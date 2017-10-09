//
// Created by angelica on 07/10/17.
//

#include <string>

using namespace std;

#ifndef LARGEMON_LARGEMON_H
#define LARGEMON_LARGEMON_H


class LargeMon {
public:
    LargeMon(const double *hp, const double *damage, const double *size, string type);

    void recieveDamage(double);
    double dealDamage();
    void defend();

    double getDamage(){ return damage; }
    double getHp(){ return hp; }
    double getSize() { return size; }
    string getType() { return type; }


    ~LargeMon();

private:
    double hp{};
    double damage{};
    double size{};
    string type; //make Type into class
    double couterLM{};
};


#endif //LARGEMON_LARGEMON_H
