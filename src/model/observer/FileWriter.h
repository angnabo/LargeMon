//
// Created by angelica on 04/01/18.
//

#include "ContrObserver.h"
#include "../largemon/Largemon.h"
#include <ctime>
#include <cstdlib>
#include <sys/stat.h>

#ifndef LARGEMON_FILEWRITER_H
#define LARGEMON_FILEWRITER_H

using namespace std;

class FileWriter : public ContrObserver {
public:
    explicit FileWriter(BattleInstance *);

    void update(Largemon *, vector<string>) const override;

private:
    string filePath;
    string DIR_PATH = "../game_logs/";

    const string currentDateTime();
};


#endif //LARGEMON_FILEWRITER_H
