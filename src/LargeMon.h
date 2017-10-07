//
// Created by angelica on 07/10/17.
//

#include <string>

using namespace std;

#ifndef LARGEMON_LARGEMON_H
#define LARGEMON_LARGEMON_H


class LargeMon {
public:
    //virtual LargeMon(const double *, const double *, const double*, const char* type);
    double attack();
    void defend();

    virtual std::string getCounterLM() = 0;

    ~LargeMon();

protected:
    double hp;
    double damage;
    double size;
    std::string type;
    double couterLM;
};


#endif //LARGEMON_LARGEMON_H
