//
// Created by angelica on 09/11/17.
//

#include "WaterLM.h"

WaterLM::WaterLM(const int *hp, const int *damage, const int *size, const string * name)
: LargeMon(hp, damage, size, name) {

}

int WaterLM::specialAttack() const {
    return damage*1.40;//damage against fire types is 40% more effective
}

string WaterLM::getType() const {
    return "water";
}

