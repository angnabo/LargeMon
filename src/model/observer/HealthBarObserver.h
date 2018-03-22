//
// Created by angelica on 11/11/17.
//

#ifndef LARGEMON_HEALTHBAROBSERVER_H
#define LARGEMON_HEALTHBAROBSERVER_H

#include <iostream>
#include <fstream>
#include "Observer.h"
#include "../../view/MainView.h"

class HealthBarObserver : public Observer {
public:
    HealthBarObserver(Largemon *, LargemonMainView *, BattleInstance * battle);
    void update() const override;
private:
    LargemonMainView *view;

    string getState(Largemon *lm) const;

    BattleInstance * battle;
};

#endif //LARGEMON_HealthBarObserver_H