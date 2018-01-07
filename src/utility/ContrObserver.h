//
// Created by angelica on 04/01/18.
//
#include "../model/BattleInstance.h"
using namespace std;
#ifndef LARGEMON_CONTROBSERVER_H
#define LARGEMON_CONTROBSERVER_H

#include <iostream>
#include <fstream>
#include <string>


class ContrObserver {
public:
    explicit ContrObserver(BattleInstance * btl);

    ContrObserver() = default;

    virtual ~ContrObserver();

    virtual void update(Largemon *, vector<string>) const = 0;
protected:
    BattleInstance *battle;
};


#endif
