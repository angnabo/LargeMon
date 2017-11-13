//
// Created by angelica on 09/11/17.
//

#ifndef LARGEMON_FIRELM_H
#define LARGEMON_FIRELM_H


#include "LargeMon.h"


class FireLM: public LargeMon {
public:
    FireLM(const int *, const int *, const int *, const string *);

    int specialAttack() const;
    string getType() const;

};


#endif //LARGEMON_FIRELM_H
