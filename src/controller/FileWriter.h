//
// Created by angelica on 04/01/18.
//

#include "ContrObserver.h"
#include "../largemon/LargeMon.h"

using namespace std;
#ifndef LARGEMON_FILEWRITER_H
#define LARGEMON_FILEWRITER_H



class FileWriter : public ContrObserver{
public:
    explicit FileWriter(ControllerBattleInstance *);


    void writeToFile() const;
    void update(LargeMon *, string, string) const ;
private:
    //int health = 0;
    string name;
    int health;
    ofstream outLogFile;
    string filePath;

};


#endif //LARGEMON_FILEWRITER_H
