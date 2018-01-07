//
// Created by angelica on 07/10/17.
//

#include <iostream>
#include <random>
#include "LargeMonGenerator.h"

LargeMonGenerator::LargeMonGenerator() = default;



LargeMon * LargeMonGenerator::generateLargeMon() {

    int health = randomInRange(MIN_HEALTH, MAX_HEALTH);

    //damage
    int damage = 0;
    if (health < 300){
        damage = (int) randomInRange(50, 80);
    } else {
        damage = (int) randomInRange(30, 55);
    }

    int size = (int) randomInRange(1, 10);;


    int randType = randomInRange(0, 2);
    switch (randType){
        case 0 : {
            string name = generateName(randType);
            auto * lm = new FireLM(&health, &damage, &size, &name);
            return lm;
        }
        case 1 : {
            string name = generateName(randType);
            auto * lm = new WaterLM(&health, &damage, &size, &name);
            return lm;
        }
        case 2 : {
            string name = generateName(randType);
            auto * lm = new WoodLM(&health, &damage, &size, &name);
            return lm;
        }
        default:break;
    }
}

int LargeMonGenerator::randomInRange(int min, int max){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max);
    return (int) distr(eng);
}

string LargeMonGenerator::generateName(int type) {
    string name;
    switch(type){
        case 0:
            name = fireNames[randomInRange(0, fireNames.size()-1)];
            break;
        case 1:
            name = waterNames[randomInRange(0, waterNames.size()-1)];
            break;
        case 2:
            name = woodNames[randomInRange(0, woodNames.size()-1)];
            break;
        default:break;
    }
    return name;
}
