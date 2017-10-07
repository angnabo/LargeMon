//
// Created by angelica on 07/10/17.
//

#include <iostream>
#include <random>
#include "LargeMonGenerator.h"

LargeMonGenerator::LargeMonGenerator() = default;

LargeMon LargeMonGenerator::generateLargeMon() {

    //health
     // define the range

    double health = randomInRange(MIN_HEALTH, MAX_HEALTH);

    //damage
    double damage = 0;
    if (health < 300){
        damage = randomInRange(50, 80);
    } else {
        damage = randomInRange(30, 55);
    }

    double size = randomInRange(1, 10);;

    string type = generateType();

    LargeMon l(&health, &damage, &size, type);

    return l;

}

double LargeMonGenerator::randomInRange(int min, int max){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max);
    return distr(eng);
}

string LargeMonGenerator::generateType() {
    return largeMonTypes[randomInRange(0, largeMonTypes.size()-1)];
}
