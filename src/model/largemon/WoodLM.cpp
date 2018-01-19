//
// Created by angelica on 09/11/17.
//

#include "WoodLM.h"

WoodLM::WoodLM(const int *hp, const int *damage, const int *size, const string * name)
        : LargeMon(hp, damage, size, name) {

}

int WoodLM::specialAttack() const {
    return damage*1.40;//damage against fire types is 40% more effective
}

string WoodLM::getType() const {
    return "wood";
}
//stun ability which stuns the opponent for 2 turns and deals half of the base damage.
int WoodLM::specialAbility() const {
    return 0;
}
