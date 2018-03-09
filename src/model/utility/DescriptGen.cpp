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
    string attack = getAttack(lm);
    string ability = getAbility(lm);
    string name = lm->getName();

    if (lm->getSize() < 5){
        size = "small";
    } else {
        size = "large";
    }


    description = "A " + size + " " + name + " largemon with a " + attack + " attack and a " + ability + " ability appears!";
    return description;
}

string DescriptGen::getAttack(Largemon * lm) {
    int i = (int)lm->getType();
    string attack;
    switch(i) {
        case 0 :
            attack = "fireball";
        case 1 :
            attack = "blast";
        case 2 :
            attack = "tree throw";
    }
    return attack;
}

string DescriptGen::getAbility(Largemon * lm) {
    string ability = "FIREEEEEEE";
    switch(lm->getType()){
        case Type::fire :
            ability = "ignite";
        case Type::water :
            ability = "bubble shield";
        case Type::wood :
            ability = "stun";
    }
    return ability;
}