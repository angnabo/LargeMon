//
// Created by angelica on 12/10/17.
//
#include <string>
#include <vector>
#include "../largemon/Largemon.h"

using namespace std;

#ifndef LARGEMON_LMDESCRIPTGEN_H
#define LARGEMON_LMDESCRIPTGEN_H

class DescriptGen {
public:
    DescriptGen();

    string getAbility(Type type);

    string getAttack(Type type);

    string getDescription(Largemon *lm);

private:
    vector<string> form;

    string getAttack(Largemon *lm);

    string getAbility(Largemon *lm);
};

//A large/small fire/water/wood dragon/furry/lizard/etc largemon, with a powerful watershot/firebalst/smash attack
#endif //LARGEMON_LMDESCRIPTGEN_H
