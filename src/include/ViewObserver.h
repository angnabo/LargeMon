//
// Created by angelica on 11/11/17.
//

#ifndef LARGEMON_VIEWOBSERVER_H
#define LARGEMON_VIEWOBSERVER_H


#include "Observer.h"

class ViewObserver : public Observer{
public:
    ViewObserver(LargeMon *);

    //ViewObserver();
    string getName() const;

    int getCurrentHp() const;

    virtual ~ViewObserver();
    void update() const;
private:
    //int health = 0;

};


#endif //LARGEMON_VIEWOBSERVER_H
