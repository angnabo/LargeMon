//
// Created by angelica on 11/11/17.
//

#include "HealthBarObserver.h"

HealthBarObserver::HealthBarObserver(Largemon *lm, LargemonMainView *viewPtr, BattleInstance * battle) : Observer(lm) {
    view = viewPtr;
    this->battle=battle;
}

/**
 * Updates the view's health bars and shielded/stunned/ignited sprite effects
 */
void HealthBarObserver::update() const {
    if (largeMon->isPlayer()) {
        view->updateHealthBar(*view->getPlayerHealthbar(), *view->getPlayerHpText(), largeMon->getCurrentHpPercent(), to_string(largeMon->getCurrentHp()));
        view->updateSprites(*view->getPlayerSprite(), getState(largeMon), true);
        view->updateSprites(*view->getEnemySprite(), getState(battle->getEnemyOf(largeMon)), false);
    } else {
        view->updateHealthBar(*view->getEnemyHealthbar(), *view->getEnemyHpText(), largeMon->getCurrentHpPercent(), to_string(largeMon->getCurrentHp()));
        view->updateSprites(*view->getEnemySprite(), getState(largeMon), false);
        view->updateSprites(*view->getPlayerSprite(), getState(battle->getEnemyOf(largeMon)), true);
    }
}

/**
 * Get any buffs/debuffs of a largemon
 * @param lm
 * @return state it's in
 */
string HealthBarObserver::getState(Largemon * lm) const{
    string state = "normal";
    if(lm->isStunned()){
        state = "stunned";
    }
    if(lm->isTakingTickDamage()){
        state = "tick";
    }
    if(lm->getType() == Type::water){
        auto *wlm = dynamic_cast<WaterLM *> (lm);
        if(wlm->isShielded()){
            state = "shielded";
        }
    }
    return state;
}