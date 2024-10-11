//
// Created by 40745 on 24/03/2024.
//

#ifndef OOP_A4_5_ELIZALUCHIAN_EVENT_H
#define OOP_A4_5_ELIZALUCHIAN_EVENT_H
#pragma once

#include <string>
#include "DateTime.h"
#include <iostream>

class Event {

private:
    std::string title, description, link;
    int number_of_people;
    DateTime date_time;

public:
    Event();
    Event(const std::string& title, const std::string& description, int number_of_people, const std::string& link, int day, int month, int year, int minutes, int hours);

    static bool TitleEqual(Event event, std::string title);


    std::string getTitle()const;
    std::string getDescription()const;
    std::string getLink()const;
    int getNumberOfPeople()const;
    DateTime getDate()const;
    void setDescription(const std::string &newDescription);
    void setLink(const std::string &newLink);
    void setNPeople(const int number);

    int getDay()const;
    int getMonth()const;
    int getYear()const;
    int getMinutes()const;
    int getHours()const;
    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newYear);
    void setMinutes(int newMinutes);
    void setHours(int newHours);
    void setTitle(const std::string &title);
    friend std::istream &operator>>(std::istream& is, Event& event);
    friend std::ostream &operator<<(std::ostream& os, const Event& event);
};


#endif //OOP_A4_5_ELIZALUCHIAN_EVENT_H
