//
// Created by angelica on 09/11/17.
//

#include "Firemon.h"

Firemon::Firemon(const int *hp, const int *damage, const int *size, const string * name)
        : Largemon(hp, damage, size, name) {

}

int Firemon::specialAttack() const {
    return (int)damage*1.40;
}

string Firemon::getType() const {
    return "fire";
}

//Damage over time ability that can be applied to any type
int Firemon::specialAbility() const {
    return 0;
}


