//
// Created by angelica on 07/10/17.
//

#include <string>

using namespace std;

#include "LargeMon.h"

#ifndef LARGEMON_FIRELM_H
#define LARGEMON_FIRELM_H


class FireLM: public LargeMon {
public:
    FireLM(const double *, const double *, const double*, std::string* type);
    std::string getCounterLM();
};


#endif //LARGEMON_FIRELM_H
