//
// Created by 40745 on 24/03/2024.
//

#ifndef OOP_A4_5_ELIZALUCHIAN_DATETIME_H
#define OOP_A4_5_ELIZALUCHIAN_DATETIME_H



#pragma once

    class DateTime {
    private:
        int day, month, year, minutes, hours;
    public:
        //DateTime();
        DateTime(int day, int month, int year, int  minutes, int hours);
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
    };




#endif //OOP_A4_5_ELIZALUCHIAN_DATETIME_H
