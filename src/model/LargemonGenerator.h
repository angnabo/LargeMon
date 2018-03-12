//
// Created by angelica on 07/10/17.
//

#ifndef LARGEMON_LARGEMONGENERATOR_H
#define LARGEMON_LARGEMONGENERATOR_H

#include "largemon/Largemon.h"
#include "largemon/WaterLM.h"
#include "largemon/FireLM.h"
#include "largemon/WoodLM.h"
#include "utility/RandomNumber.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class LargemonGenerator {
public:
    LargemonGenerator();

    Largemon *generateLargemon();

    string generateName(Type);

    int getDamage(int health);

private:
    const int MIN_HEALTH = 200;
    const int MAX_HEALTH = 400;
    const int MIN_DMG_IF_HEALTH_LOW = 50;
    const int MIN_DMG_IF_HEALTH_HIGH = 30;
    const int MAX_DMG_IF_HEALTH_LOW = 80;
    const int MAX_DMG_IF_HEALTH_HIGH = 55;
    const int MIN_SIZE = 1;
    const int MAX_SIZE = 10;
    const int DAMAGE_FACTOR = 300;
    vector<string> fireNames = {"fire troll"};
    vector<string> waterNames = {"water troll"};
    vector<string> woodNames = {"wood troll"};
};


#endif //LARGEMON_LARGEMONGENERATOR_H
