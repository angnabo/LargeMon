//
// Created by angelica on 05/01/18.
//

#include "HealthBarObserver.h"

HealthBarObserver::HealthBarObserver(ControllerBattleInstance * btl) : ContrObserver(btl){

}

void HealthBarObserver::update(LargeMon * lm, vector<string>/*unused*/) const {

}

int HealthBarObserver::getHealth(LargeMon * lm) const {
    return lm->getCurrentHp();
}