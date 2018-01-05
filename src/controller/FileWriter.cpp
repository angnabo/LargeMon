//
// Created by angelica on 04/01/18.
//

#include "FileWriter.h"
#include <ctime>


const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

FileWriter::FileWriter(ControllerBattleInstance *lm) : ContrObserver(lm) {
    filePath = "/home/angelica/Development/CLion/LargeMon/game_logs/" + currentDateTime() + "log.txt";
    ofstream outLogFile(filePath, ios::app);
    if(!outLogFile)
    {
        cerr << "File could not be opened" << endl;
        exit(1);
    }
}


void FileWriter::update(LargeMon * lm, string player, string action) const {
    ofstream outLogFile(filePath, ios::app);
    if(!outLogFile)
    {
        cerr << "File could not be opened" << endl;
        exit(1);
    }
    outLogFile << "Turn: " << battle->getTurns() << ". " << player << " LargeMon: " << lm->getName() << " Action: " << action <<

               " Health: " << lm->getCurrentHp() << endl;
}

void FileWriter::writeToFile() const {

}


