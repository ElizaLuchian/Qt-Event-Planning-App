//
// Created by 40745 on 29/04/2024.
//

#include <fstream>
#include "CsvAdminFile.h"
#include "FileExceptions.h"

CsvAdminFile::CsvAdminFile(const std::string &filename) : FileAdminRepo(filename) {

}

void CsvAdminFile::writeToFile() {
    FileAdminRepo::writeToFile();
    vector<Event> eventList=getAllElements();
    ofstream filename(fileName + ".csv");
    if (!filename.is_open())
        throw FileExceptions();
    Event event;
    for (auto &elem : eventList)
        filename << elem;

    filename.close();
}

std::string CsvAdminFile::generateCommand() {
    return "notepad.exe " + fileName + ".csv";
}
