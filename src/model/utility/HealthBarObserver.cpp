//
// Created by angelica on 11/11/17.
//

#include "HealthBarObserver.h"

HealthBarObserver::HealthBarObserver(Largemon *lm, LargemonMainView *viewPtr) : Observer(lm) {
    view = viewPtr;
}

void HealthBarObserver::update() const {
    if (largeMon->isPlayer()) {
        view->updatePlayerHealthBar(largeMon->getCurrentHpPercent(), to_string(largeMon->getCurrentHp()));
    } else {
        view->updateEnemyHealthBar(largeMon->getCurrentHpPercent(), to_string(largeMon->getCurrentHp()));
    }
}