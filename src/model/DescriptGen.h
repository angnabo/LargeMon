/**
 * Generates a description of largemon
 *
 * Created by angelica on 12/10/17.
 */
#include <string>
#include <vector>
#include "largemon/Largemon.h"

#ifndef LARGEMON_DESCRIPTGEN_H
#define LARGEMON_DESCRIPTGEN_H

using namespace std;

class DescriptGen {
public:
    DescriptGen();

    string getAbility(Type type);

    string getAttack(Type type);

    string getDescription(Largemon *lm);
};

#endif //LARGEMON_DESCRIPTGEN_H