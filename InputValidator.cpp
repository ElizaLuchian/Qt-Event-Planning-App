//
// Created by 40745 on 26/04/2024.
//

#include "InputValidator.h"
#include "ValidatorExceptions.h"

void InputValidator::isNonNegative(int number) {
    if(number<0)
        throw ValidationsExceptions("This is not a positive value. Try again");

}

void InputValidator::isMonth(int month) {
    if(month < 1 || month >12)
        throw ValidationsExceptions("This is not a valid month. Try again");

}

void InputValidator::isDay(int day) {
    if(day<1 || day>31)
        throw ValidationsExceptions("This is not a valid day. Try again");

}

void InputValidator::isNonEmptyString(std::string string) {
    if(string == "")
        throw ValidationsExceptions("Empty string is not allowed. Try again");

}

void InputValidator::isTitle(std::string string) {
    if(string[0]<'A' || string[0]>'Z')
        throw ValidationsExceptions("Title must begin with uppercase letter. Try again");

}

void InputValidator::isHour(int hour) {
    if(hour>24 || hour<1)
        throw ValidationsExceptions("Not a valid hour. Try again");

}

void InputValidator::isMinutes(int minutes) {
    if(minutes<0 || minutes>60)
        throw ValidationsExceptions("Not valid minutes value. Try again");

}


