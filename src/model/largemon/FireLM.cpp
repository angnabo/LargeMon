//
// Created by angelica on 09/11/17.
//

#include "FireLM.h"

FireLM::FireLM(const int *hp, const int *damage, const int *size, const string * name)
        : Largemon(hp, damage, size, name) {

}

int FireLM::specialAttack() const {
    return (int)damage*1.40;
}

Type FireLM::getType() const {
    return Type::fire;
}

//Damage over time ability that can be applied to any type
int FireLM::specialAbility() const {
    return 0;
}


