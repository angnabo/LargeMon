//
// Created by angelica on 09/11/17.
//

#include "WaterLM.h"

WaterLM::WaterLM(const int *hp, const int *damage, const int *size, const string * name)
: Largemon(hp, damage, size, name) {

}

int WaterLM::specialAttack() const {
    return damage*1.40;//damage against fire types is 40% more effective
}


Type WaterLM::getType() const {
    return Type::water;
}
//bubble shield which shields a portion of the damage
int WaterLM::specialAbility() const {
    return 0;
}

bool WaterLM::isShielded() {
    return (shieldCount > 0);
}

void WaterLM::shield(int count) {
    shieldCount = count;
}

void WaterLM::decrementShield() {
    if(shieldCount > 0){
        shieldCount--;
    }
}

