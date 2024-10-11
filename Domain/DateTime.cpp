//
// Created by 40745 on 24/03/2024.
//

#include "DateTime.h"
//DateTime::DateTime():day{0}, month{0}, year{0}, minutes{0}, hours{0} {}

DateTime::DateTime(int day, int month, int year, int minutes, int hours):day{day}, month{month}, year{year}, minutes{minutes}, hours{hours} {}

int DateTime::getDay()const {
    return this->day;
}

int DateTime::getMonth() const{
   return  this->month;
}

int DateTime::getYear() const{
   return this->year;
}

void DateTime::setDay(int newDay) {
 this->day=newDay;
}

void DateTime::setMonth(int newMonth) {
this->month=newMonth;
}

void DateTime::setYear(int newYear) {
this->year=newYear;
}

void DateTime::setMinutes(int newMinutes) {
this->minutes=newMinutes;
}

int DateTime::getMinutes() const {
    return this->minutes;
}

int DateTime::getHours() const {
    return this->hours;
}

void DateTime::setHours(int newHours) {
this->hours=newHours;
}



