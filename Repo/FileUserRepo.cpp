//
// Created by 40745 on 06/04/2024.
//

#include <stdexcept>
#include <algorithm>
#include "FileUserRepo.h"
#include "RepositoryExceptions.h"
#include "FileExceptions.h"

#include <iostream>
#include <fstream>
#include <utility>

FileUserRepo::FileUserRepo() {
}

vector<Event> FileUserRepo::getEventList() const {
    return eventlist;
}


void FileUserRepo::addEventUser(Event event) {
    auto iterator = search_n(eventlist.begin(), eventlist.end(), 1, event.getTitle(), Event::TitleEqual);
    if(iterator!=eventlist.end())
       throw AlreadyExists();
    this->eventlist.push_back(event);
    this->writeToFile();


}

void FileUserRepo::removeEventUser(std::string title) {
    auto iterator = search_n(eventlist.begin(), eventlist.end(), 1, title, Event::TitleEqual);
    if(iterator==eventlist.end())
        throw NotFound();
    eventlist.erase(iterator);
    this->writeToFile();

}
void FileUserRepo::readFromFile() {
    ifstream file(fileName  + ".txt");
    if(!file.is_open())
        throw FileExceptions();
    eventlist.clear();
    Event event;
    while(file>>event)
        eventlist.push_back(event);
    file.close();
}

void FileUserRepo::writeToFile() {
    ofstream filename(fileName + ".txt");
    if(!filename.is_open())
        throw FileExceptions();
    Event event;
    for(auto &elem:eventlist )
        filename<<elem;

    filename.close();



}



FileUserRepo::FileUserRepo(string fileName) : fileName{std::move(fileName)} {

}

std::string FileUserRepo::generateCommand() {
    return std::string();
}





