//
// Created by angelica on 12/10/17.
//

#include "DescriptGen.h"

DescriptGen::DescriptGen(string type, int size) {
    string sizeStr;
    if (size < 5){
        sizeStr = "small";
    } else {
        sizeStr = "large";
    }
    string attack;
    if(type == "fire"){
        attack = "Fireblast";
    } else if (type == "water"){
        attack = "Watershot";
    } else {
        attack = "Smash";
    }

    description = "A " + sizeStr + " " + type + " Largemon, with a " + attack + " " + "attack";
}

string DescriptGen::getDescription() {
    return description;
}