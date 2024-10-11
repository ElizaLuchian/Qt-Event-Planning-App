//
// Created by 40745 on 29/04/2024.
//

#include <fstream>
#include "CsvUserFile.h"
#include "FileExceptions.h"

void CsvUserFile::writeToFile() {
    FileUserRepo::writeToFile();
    vector<Event> eventList=getEventList();
    ofstream filename(fileName + ".csv");
    if (!filename.is_open())
        throw FileExceptions();
    Event event;
    for (auto &elem : eventList)
        filename << elem;

    filename.close();

}

CsvUserFile::CsvUserFile(const std::string &filename) : FileUserRepo(filename) {

}

std::string CsvUserFile::generateCommand() {
    return "notepad.exe " + fileName + ".csv";
}
