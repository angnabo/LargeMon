//
// Created by angelica on 09/11/17.
//

#ifndef LARGEMON_WOODLM_H
#define LARGEMON_WOODLM_H


#include "Largemon.h"


class WoodLM : public Largemon {
public:
    WoodLM(const int *, const int *, const int *, const string *);
    Type getType() const;
};


#endif //LARGEMON_WOODLM_H
