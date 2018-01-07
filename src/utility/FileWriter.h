//
// Created by angelica on 04/01/18.
//



using namespace std;
#ifndef LARGEMON_FILEWRITER_H
#define LARGEMON_FILEWRITER_H

#include "ContrObserver.h"
#include "../model/largemon/Largemon.h"

class FileWriter : public ContrObserver{
public:
    explicit FileWriter(BattleInstance *);


    void writeToFile() const;
    void update(Largemon *, vector<string>) const ;
private:
    //int health = 0;
    string name;
    int health;
    ofstream outLogFile;
    string filePath;

};


#endif //LARGEMON_FILEWRITER_H
