//
// Created by angelica on 11/11/17.
//


#include "FileWriterObserver.h"

FileWriterObserver::FileWriterObserver(Largemon *lm) : Observer(lm) {
    ofstream outLogFile("/home/angelica/Development/CLion/Largemon/log.txt", ios::out);
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
    ofstream outLogFile("/home/angelica/Development/CLion/Largemon/log.txt", ios::app);
    if(!outLogFile)
    {
        cerr << "File could not be opened" << endl;
        exit(1);
    }
    outLogFile << "Largemon: " << largeMon->getName() << " Action: " << largeMon->getLastAction() <<

                                                      " Health: " << largeMon->getCurrentHp() << endl;
}


