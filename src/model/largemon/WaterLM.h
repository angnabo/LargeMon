//
// Created by angelica on 09/11/17.
//

#ifndef LARGEMON_WATERLM_H
#define LARGEMON_WATERLM_H


#include "LargeMon.h"


class WaterLM: public LargeMon {
public:
    WaterLM(const int *hp, const int *damage, const int *size, const string *);

    int specialAttack() const;
    int specialAbility() const;
    Type getType() const;


    void decrementShield();
    void shield(int);
    bool isShielded();

private:
    int shieldCount;

};


#endif //LARGEMON_WATERLM_H
