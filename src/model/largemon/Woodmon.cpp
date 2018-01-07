//
// Created by angelica on 09/11/17.
//

#include "Woodmon.h"

WoodLM::WoodLM(const int *hp, const int *damage, const int *size, const string * name)
        : Largemon(hp, damage, size, name) {

}

int WoodLM::specialAttack() const {
    return damage*1.40;//damage against fire types is 40% more effective
}

string WoodLM::getType() const {
    return "wood";
}
//stun ability which stuns the opponent for 1 turn
int WoodLM::specialAbility() const {
    return 0;
}
