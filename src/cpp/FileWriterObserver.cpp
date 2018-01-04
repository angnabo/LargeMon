//
// Created by angelica on 11/11/17.
//


#include "../include/FileWriterObserver.h"

FileWriterObserver::FileWriterObserver(LargeMon *lm) : Observer(lm) {
    ofstream outLogFile("/home/angelica/Development/CLion/LargeMon/log.txt", ios::out);
    if(!outLogFile)
    {
        cerr << "File could not be opened" << endl;
        exit(1);
    }
    //largeMon->attach(this);
    name = largeMon->getName();
    health = largeMon->getCurrentHp();
}

FileWriterObserver::~FileWriterObserver() {

}

void FileWriterObserver::update() const {
    ofstream outLogFile("/home/angelica/Development/CLion/LargeMon/log.txt", ios::app);
    if(!outLogFile)
    {
        cerr << "File could not be opened" << endl;
        exit(1);
    }
    outLogFile << "LargeMon: " << largeMon->getName() << " Action: " << largeMon->getLastAction() <<

                                                      " Health: " << largeMon->getCurrentHp() << endl;
}

void FileWriterObserver::writeToFile() const {

}

