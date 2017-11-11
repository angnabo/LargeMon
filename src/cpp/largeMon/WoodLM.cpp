//
// Created by angelica on 09/11/17.
//

#include "../../include/largeMonHeader/WoodLM.h"

WoodLM::WoodLM(const int *hp, const int *damage, const int *size)
        : LargeMon(hp, damage, size) {

}

int WoodLM::specialAttack() const {
    return damage*1.40;//damage against fire types is 40% more effective
}

string WoodLM::getType() const {
    return "wood";
}
