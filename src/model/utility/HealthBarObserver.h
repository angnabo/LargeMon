//
// Created by angelica on 11/11/17.
//

#ifndef LARGEMON_HEALTHOBSERVER_H
#define LARGEMON_HEALTHOBSERVER_H

#include <iostream>
#include <fstream>
#include "Observer.h"
#include "../../view/LargemonMainView.h"

class HealthBarObserver : public Observer {
public:
    HealthBarObserver(Largemon *, LargemonMainView *);
    //virtual ~HealthBarObserver() = default;

    void update() const override;

private:
    //int health = 0;
    string name;
    int health;
    ofstream outLogFile;
    LargemonMainView *view;
    float hpPercent;
};

#endif //LARGEMON_HealthBarObserver_H
