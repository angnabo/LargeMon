//
// Created by angelica on 09/11/17.
//

#ifndef LARGEMON_FIRELM_H
#define LARGEMON_FIRELM_H


#include "Largemon.h"


class Firemon: public Largemon {
public:
    Firemon(const int *, const int *, const int *, const string *);

    int specialAttack() const;
    int specialAbility() const;
    string getType() const;

};


#endif //LARGEMON_FIRELM_H
