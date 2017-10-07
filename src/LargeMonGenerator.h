//
// Created by angelica on 07/10/17.
//


#include "LargeMon.h"
#include <string>
#include <vector>

using namespace std;

#ifndef LARGEMON_LARGEMONGENERATOR_H
#define LARGEMON_LARGEMONGENERATOR_H


class LargeMonGenerator {
public:
    LargeMonGenerator();
    LargeMon generateLargeMon();
    double randomInRange(int, int);
    string generateType();
private:
    const int MIN_HEALTH = 200;
    const int MAX_HEALTH = 400;
    std::vector<std::string> largeMonTypes = {"fire", "water", "wood"};
};


#endif //LARGEMON_LARGEMONGENERATOR_H
