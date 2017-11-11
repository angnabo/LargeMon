//
// Created by angelica on 09/11/17.
//

#include "../../include/largeMonHeader/WaterLM.h"

WaterLM::WaterLM(const int *hp, const int *damage, const int *size)
: LargeMon(hp, damage, size) {

}

int WaterLM::specialAttack() const {
    return damage*1.40;//damage against fire types is 40% more effective
}

string WaterLM::getType() const {
    return "water";
}
