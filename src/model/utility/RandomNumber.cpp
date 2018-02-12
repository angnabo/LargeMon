//
// Created by angelica on 12/02/18.
//

#include <random>
#include "RandomNumber.h"

int RandomNumber::randomInRange(int min, int max){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max);
    return (int) distr(eng);
}