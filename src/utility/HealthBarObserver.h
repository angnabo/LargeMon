//
// Created by angelica on 05/01/18.
//

#ifndef LARGEMON_HEALTHBAROBSERVER_H
#define LARGEMON_HEALTHBAROBSERVER_H


#include "ContrObserver.h"

class HealthBarObserver : public ContrObserver {
public:
    HealthBarObserver(BattleInstance *);

    void update(Largemon *, vector<string>) const ;
private:
    int currentHealth;

    int getHealth() const;

    int getHealth(Largemon *lm) const;
};


#endif //LARGEMON_HEALTHBAROBSERVER_H
