//
// Created by angelica on 11/11/17.
//

#ifndef LARGEMON_FileWriterObserver_H
#define LARGEMON_FileWriterObserver_H

#include <iostream>
#include <fstream>
#include "Observer.h"

class FileWriterObserver : public Observer{
public:
    FileWriterObserver(LargeMon *);


    void writeToFile() const;

    virtual ~FileWriterObserver();
    void update() const;
private:
    //int health = 0;
    string name;
    int health;
    ofstream outLogFile;

};


#endif //LARGEMON_FileWriterObserver_H
