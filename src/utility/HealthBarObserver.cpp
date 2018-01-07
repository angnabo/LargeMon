//
// Created by angelica on 05/01/18.
//

#include "HealthBarObserver.h"

HealthBarObserver::HealthBarObserver(BattleInstance * btl) : ContrObserver(btl){

}

void HealthBarObserver::update(Largemon * lm, vector<string>/*unused*/) const {

}

int HealthBarObserver::getHealth(Largemon * lm) const {
    return lm->getCurrentHp();
}