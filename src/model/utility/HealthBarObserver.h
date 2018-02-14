//
// Created by angelica on 11/11/17.
//

#ifndef LARGEMON_HEALTHOBSERVER_H
#define LARGEMON_HEALTHOBSERVER_H

#include <iostream>
#include <fstream>
#include "Observer.h"
#include "../../view/LargeMonMainView.h"

class HealthObserver : public Observer{
public:
    HealthObserver(LargeMon *, LargeMonMainView *);
    //virtual ~HealthObserver() = default;

    void update() const override;
private:
    //int health = 0;
    string name;
    int health;
    ofstream outLogFile;
    LargeMonMainView * view;
    float hpPercent;
};


#endif //LARGEMON_HealthObserver_H
