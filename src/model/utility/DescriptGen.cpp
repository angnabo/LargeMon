//
// Created by angelica on 12/10/17.
//
#include "DescriptGen.h"

DescriptGen::DescriptGen() {
}

string DescriptGen::getDescription(Largemon *lm) {

    string description;
    string size;
    Type type = lm->getType();
    string attack = getAttack(type);
    string ability = getAbility(type);
    string name = lm->getName();

    if (lm->getSize() < 5) {
        size = "small";
    } else {
        size = "large";
    }
    description = "A " + size + " " + name + " with a " + attack + " attack and a " + ability + " ability appears!";
    return description;
}

string DescriptGen::getAttack(Type type) {
    string attack;
    switch (type) {
        case Type::fire :
            attack = "Fireball";
            break;
        case Type::water :
            attack = "Blast";
            break;
        case Type::wood :
            attack = "Tree throw";
            break;
    }
    return attack;
}

string DescriptGen::getAbility(Type type) {
    string ability;
    switch (type) {
        case Type::fire :
            ability = "Ignite";
            break;
        case Type::water :
            ability = "Bubble shield";
            break;
        case Type::wood :
            ability = "Stun";
            break;
    }
    return ability;
}