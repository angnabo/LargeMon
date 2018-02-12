//
// Created by angelica on 05/01/18.
//

#ifndef LARGEMON_HEALTHBAROBSERVER_H
#define LARGEMON_HEALTHBAROBSERVER_H


#include "ContrObserver.h"
#include "../../view/LargeMonMainView.h"

class HealthBarObserver : public ContrObserver {
public:
    HealthBarObserver(BattleInstance *, LargeMonMainView *);

    void update(LargeMon *, vector<string>) const ;
private:
    int currentHealth;

    int getHealth() const;

    int getHealth(LargeMon *lm) const;

    LargeMonMainView * view;
};


#endif //LARGEMON_HEALTHBAROBSERVER_H
