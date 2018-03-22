//
// Created by angelica on 04/01/18.
//

#include "ContrObserver.h"

ContrObserver::ContrObserver(BattleInstance *b) {
    battle = b;
    battle->attach(this);
}

ContrObserver::~ContrObserver() = default;

