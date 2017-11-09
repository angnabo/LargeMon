//
// Created by angelica on 07/10/17.
//

#include <iostream>
#include <random>
#include "LargeMonGenerator.h"
#include "WaterLM.h"
#include "FireLM.h"
#include "WoodLM.h"

LargeMonGenerator::LargeMonGenerator() = default;

//LargeMon * LargeMonGenerator::generateLargeMon(LargeMon *largeMon) {
//
//    //health
//    // define the range
//
//    int health = randomInRange(MIN_HEALTH, MAX_HEALTH);
//
//    //damage
//    int damage = 0;
//    if (health < 300){
//        damage = (int) randomInRange(50, 80);
//    } else {
//        damage = (int) randomInRange(30, 55);
//    }
//
//    int size = (int) randomInRange(1, 10);;
//
//    string type = generateType();
//
//    int randType = randomInRange(0, 2);
//    switch (randType){
//        case 0 : {
//            WaterLM lm(&health, &damage, &size);
//            largeMon = &lm;
//            break;
//        }
//        case 1 : {
//            FireLM lm(&health, &damage, &size);
//            largeMon = &lm;
//            break;
//        }
//        case 2 : {
//            WoodLM lm(&health, &damage, &size);
//            largeMon = &lm;
//            break;
//        }
//        default: {
//            WoodLM lm(&health, &damage, &size);
//            largeMon = &lm;
//            break;
//        }
//    }
//
//}

LargeMon * LargeMonGenerator::generateLargeMon() {

    //LargeMon * largeMon;
    //health
     // define the range

    int health = randomInRange(MIN_HEALTH, MAX_HEALTH);

    //damage
    int damage = 0;
    if (health < 300){
        damage = (int) randomInRange(50, 80);
    } else {
        damage = (int) randomInRange(30, 55);
    }

    int size = (int) randomInRange(1, 10);;

    string type = generateType();

    //WaterLM wlm(&health, &damage, &size);
    //largeMon = &wlm;

    int randType = randomInRange(0, 2);
    switch (randType){
        case 0 : {
            auto * lm = new WaterLM(&health, &damage, &size);
            return lm;
        }
        case 1 : {
            auto * lm = new FireLM(&health, &damage, &size);
            return lm;
        }
        case 2 : {
            auto * lm = new WoodLM(&health, &damage, &size);
            return lm;
        }
        default: {
            auto * lm = new WoodLM(&health, &damage, &size);
            return lm;
        }
    }

    //LargeMon l(&health, &damage, &size);

    //return &wlm;

}

//WaterLM LargeMonGenerator::generateWaterLM() {
//
//    LargeMon largeMon;
//
//    //health
//    // define the range
//
//    int health = randomInRange(MIN_HEALTH, MAX_HEALTH);
//
//    //damage
//    int damage = 0;
//    if (health < 300){
//        damage = (int) randomInRange(50, 80);
//    } else {
//        damage = (int) randomInRange(30, 55);
//    }
//
//    int size = (int) randomInRange(1, 10);;
//
//    string type = generateType();
//
//    WaterLM l(&health, &damage, &size);
//
//    return l;
//
//}

int LargeMonGenerator::randomInRange(int min, int max){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max);
    return (int) distr(eng);
}

string LargeMonGenerator::generateType() {
    return largeMonTypes[randomInRange(0, largeMonTypes.size()-1)];
}
