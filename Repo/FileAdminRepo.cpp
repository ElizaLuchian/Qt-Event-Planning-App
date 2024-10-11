//
// Created by 40745 on 24/03/2024.
//

#include <algorithm>
#include <stdexcept>
#include "FileAdminRepo.h"
#include "RepositoryExceptions.h"
#include "FileExceptions.h"

#include <fstream>
#include <utility>

int FileAdminRepo::get_size_repo() const {
    return events.size();
}

void FileAdminRepo::addRepo(const Event &event) {
    auto iterator = search_n(events.begin(), events.end(), 1, event.getTitle(), Event::TitleEqual);
    if (iterator != events.end())
       throw AlreadyExists();
    this->events.push_back(event);
    this->writeToFile();
}

void FileAdminRepo::deleteRepo(const std::string &title) {
    auto iterator = search_n(events.begin(), events.end(), 1, title, Event::TitleEqual);
    if (iterator == events.end())
        throw NotFound();
    this->events.erase(iterator);
    this->writeToFile();
}

vector<Event> FileAdminRepo::getAllElements() const {

    return events;
}

FileAdminRepo::FileAdminRepo() : events(0) {
}

void FileAdminRepo::updateRepo(const std::string &title, const Event &event) {

    auto iterator = search_n(events.begin(), events.end(), 1, title, Event::TitleEqual);
    if (iterator == events.end())
        throw NotFound();
    *iterator = event;
    this->writeToFile();

}


Event FileAdminRepo::getElemwithTitle(const std::string &title) const {
    auto iterator = search_n(events.begin(), events.end(), 1, title, Event::TitleEqual);
    if (events.end() == iterator)
        throw  NotFound();
    return *iterator;


}

void FileAdminRepo::readFromFile() {
    ifstream filename(fileName + ".txt");
    if (!filename.is_open())
        throw FileExceptions();
    Event event;
    events.clear();
    while (filename >> event)
        events.push_back(event);
    filename.close();

}

void FileAdminRepo::writeToFile() {
    ofstream filename(fileName + ".txt");
    if (!filename.is_open())
        throw FileExceptions();
    Event event;
    for (auto &elem: events)
        filename << elem;

    filename.close();
}

FileAdminRepo::FileAdminRepo(string fileName) : fileName{std::move(fileName)} {

}

std::string FileAdminRepo::generateCommand() {
    return std::string();
}












