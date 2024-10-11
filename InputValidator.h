//
// Created by 40745 on 26/04/2024.
//

#ifndef OOP_A6_7_ELIZALUCHIAN_INPUTVALIDATOR_H
#define OOP_A6_7_ELIZALUCHIAN_INPUTVALIDATOR_H


#include <string>

class InputValidator {

public:
    static void isNonNegative(int number);
    static void isMonth(int month);
    static void isDay(int day);
    static void isNonEmptyString(std::string string );
    static void isTitle(std:: string string);
    static void isHour(int hour);
    static void isMinutes(int minutes);


};


#endif //OOP_A6_7_ELIZALUCHIAN_INPUTVALIDATOR_H
