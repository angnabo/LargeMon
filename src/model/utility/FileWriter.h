//
// Created by angelica on 04/01/18.
//

#include "ContrObserver.h"
#include "../largemon/Largemon.h"

using namespace std;
#ifndef LARGEMON_FILEWRITER_H
#define LARGEMON_FILEWRITER_H

class FileWriter : public ContrObserver {
public:
    explicit FileWriter(BattleInstance *);

    void update(Largemon *, vector<string>) const;

private:
    string filePath;
    string DIR_PATH = "../game_logs/";

    const string currentDateTime();
};


#endif //LARGEMON_FILEWRITER_H
