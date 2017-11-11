//
// Created by angelica on 12/10/17.
//
#include <string>
#include <vector>

using namespace std;

#ifndef LARGEMON_LMDESCRIPTGEN_H
#define LARGEMON_LMDESCRIPTGEN_H

class DescriptGen {
public:
    DescriptGen( string, int);
    string getDescription();
private:
    string description;
    vector<string> form;
};

//A large/small fire/water/wood dragon/furry/lizard/etc largemon, with a powerful watershot/firebalst/smash attack
#endif //LARGEMON_LMDESCRIPTGEN_H
