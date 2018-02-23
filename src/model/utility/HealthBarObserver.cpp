//
// Created by angelica on 11/11/17.
//


#include "HealthBarObserver.h"

HealthObserver::HealthObserver(Largemon *lm, LargemonMainView * viewPtr) : Observer(lm) {
    view = viewPtr;
}

void HealthObserver::update() const {
    if(largeMon->isPlayer()){
        view->updatePlayerHealthBar(largeMon->getCurrentHpPercent(), to_string(largeMon->getCurrentHp()));
    } else {
        view->updateEnemyHealthBar(largeMon->getCurrentHpPercent(), to_string(largeMon->getCurrentHp()));
    }
}


