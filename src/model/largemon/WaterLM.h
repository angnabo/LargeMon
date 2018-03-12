//
// Created by angelica on 09/11/17.
//

#ifndef LARGEMON_WATERLM_H
#define LARGEMON_WATERLM_H


#include "Largemon.h"


class WaterLM : public Largemon {
public:
    WaterLM(const int *hp, const int *damage, const int *size, const string *);

    Type getType() const;

    void decrementShield();

    void shield(int);

    bool isShielded();

private:
    int shieldCount;


};


#endif //LARGEMON_WATERLM_H
