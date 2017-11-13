//
// Created by angelica on 09/11/17.
//

#ifndef LARGEMON_WOODLM_H
#define LARGEMON_WOODLM_H


#include "LargeMon.h"


class WoodLM: public LargeMon {
public:
    WoodLM(const int *, const int *, const int *, const string *);

    int specialAttack() const;
    string getType() const;

};


#endif //LARGEMON_WOODLM_H
