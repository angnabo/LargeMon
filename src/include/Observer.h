//
// Created by angelica on 10/11/17.
//

#ifndef LARGEMON_OBSERVER_H
#define LARGEMON_OBSERVER_H


#include "largeMonHeader/LargeMon.h"

class Observer {
public:
    Observer(LargeMon *);

//    Observer();

    virtual ~Observer();

    virtual void update() const = 0;
    LargeMon *largeMon;

};


#endif //LARGEMON_OBSERVER_H
