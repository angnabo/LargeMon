//
// Created by angelica on 12/10/17.
//

#include "DescriptGen.h"
#include "../largemon/Largemon.h"

DescriptGen::DescriptGen() {
}

string DescriptGen::getDescription(Largemon * lm) {

    string description;
    string size;
    Type type = lm->getType();
    string attack = getAttack(lm->getType());
    string ability = getAbility(lm->getType());
    string name = lm->getName();

    if (lm->getSize() < 5){
        size = "small";
    } else {
        size = "large";
    }


    description = "A " + size + " " + name + " with a " + attack + " attack and a " + ability + " ability appears!";
    return description;
}

string DescriptGen::getAttack(Type type) {
    string attack;
    switch(type){
        case Type::fire :
            attack = "fireball";
            break;
        case Type::water :
            attack = "blast";
            break;
        case Type::wood :
            attack = "tree throw";
            break;
    }
    return attack;
}

string DescriptGen::getAbility(Type type) {
    string ability;
    switch(type){
        case Type::fire :
            ability = "ignite";
            break;
        case Type::water :
            ability = "bubble shield";
            break;
        case Type::wood :
            ability = "stun";
            break;
    }
    return ability;
}