//
// Created by angelica on 04/01/18.
//

#include "FileWriter.h"

/**
 * Constructor. Will create a directory for game logs if it doesn't exist.
 * @param btl
 */
FileWriter::FileWriter(BattleInstance *btl) : ContrObserver(btl) {
    struct stat info;
    if(stat( DIR_PATH.c_str(), &info ) != 0) {
        string path = "mkdir -p " + DIR_PATH;
        const char *p = path.c_str();
        const int dir = system(p);
        if (dir < 0) {
            cout << "Could not create directory";
        } else {
            cerr << "Directory Created: " << DIR_PATH;
        }
    }
    filePath = DIR_PATH + currentDateTime() + "-log.txt";
    ofstream outLogFile(filePath, ios::app);
    if(!outLogFile) {
        cerr << "File could not be opened: " << filePath << endl;
        exit(1);
    }
}

/**
 * Get current date and time
 * @return
 */
const std::string FileWriter::currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}

/**
 * Update the game log
 * @param lm
 * @param args
 */
void FileWriter::update(Largemon * lm, vector<string> args) const {
    if(!args.empty()) {
        ofstream outLogFile(filePath, ios::app);
        if (!outLogFile) {
            cerr << "File could not be opened: " << filePath << endl;
            exit(1);
        }
        outLogFile << "Turn: " << battle->getRound() << ". " << args[0] << " Largemon: " << lm->getName()
                   << ". Action: " << args[1] << ". Health: " << lm->getCurrentHp() << endl;
    }
}