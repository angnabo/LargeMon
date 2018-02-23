//
// Created by angelica on 09/11/17.
//

#ifndef LARGEMON_FIRELM_H
#define LARGEMON_FIRELM_H

#include "Largemon.h"

class FireLM: public Largemon {
public:
    FireLM(const int *, const int *, const int *, const string *);

    int specialAttack() const;
    int specialAbility() const;
    Type getType() const;

};


#endif //LARGEMON_FIRELM_H
