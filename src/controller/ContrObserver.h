//
// Created by angelica on 04/01/18.
//
#include <iostream>
#include <fstream>
#include <string>
#include "ControllerBattleInstance.h"

using namespace std;
#ifndef LARGEMON_CONTROBSERVER_H
#define LARGEMON_CONTROBSERVER_H


class ContrObserver {
public:
    explicit ContrObserver(ControllerBattleInstance *);

    ContrObserver() = default;

    virtual ~ContrObserver();

    virtual void update(LargeMon *, string, string) const = 0;
    ControllerBattleInstance *battle;
};


#endif
