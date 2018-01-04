//
// Created by angelica on 07/10/17.
//


#include "../largemon/LargeMon.h"
#include "../largemon/WaterLM.h"
#include "../largemon/FireLM.h"
#include "../largemon/WoodLM.h"
#include <string>
#include <vector>

using namespace std;

#ifndef LARGEMON_LARGEMONGENERATOR_H
#define LARGEMON_LARGEMONGENERATOR_H


class LargeMonGenerator {
public:
    LargeMonGenerator();
    LargeMon * generateLargeMon();
    int randomInRange(int, int);
    string generateName();
private:
    const int MIN_HEALTH = 200;
    const int MAX_HEALTH = 400;
    vector<string> largeMonNames = {"Fire Doge", "Water Doge", "Wood Doge"};
};


#endif //LARGEMON_LARGEMONGENERATOR_H
