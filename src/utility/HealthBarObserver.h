//
// Created by angelica on 05/01/18.
//

#ifndef LARGEMON_HEALTHBAROBSERVER_H
#define LARGEMON_HEALTHBAROBSERVER_H


#include "ContrObserver.h"

class HealthBarObserver : public ContrObserver {
public:
    HealthBarObserver(ControllerBattleInstance *);

    void update(LargeMon *, vector<string>) const ;
private:
    int currentHealth;

    int getHealth() const;

    int getHealth(LargeMon *lm) const;
};


#endif //LARGEMON_HEALTHBAROBSERVER_H
