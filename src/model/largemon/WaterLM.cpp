//
// Created by angelica on 09/11/17.
//

#include "WaterLM.h"

WaterLM::WaterLM(const int *hp, const int *damage, const int *size, const string *name)
        : Largemon(hp, damage, size, name) {

}

Type WaterLM::getType() const {
    return Type::water;
}

bool WaterLM::isShielded() {
    return (shieldCount > 0);
}

void WaterLM::shield(int count) {
    shieldCount = count;
}

void WaterLM::decrementShield() {
    if (shieldCount > 0) {
        shieldCount--;
    }
}

