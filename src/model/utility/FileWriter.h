//
// Created by angelica on 04/01/18.
//

#include "ContrObserver.h"
#include "../largemon/Largemon.h"

using namespace std;
#ifndef LARGEMON_FILEWRITER_H
#define LARGEMON_FILEWRITER_H



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

    string DIR_PATH = "../game_logs/";

};


#endif //LARGEMON_FILEWRITER_H
