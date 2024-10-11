//
// Created by 40745 on 25/03/2024.
//

#ifndef OOP_A4_5_ELIZALUCHIAN_UI_H
#define OOP_A4_5_ELIZALUCHIAN_UI_H


#include "Controller/Controller.h"
using namespace std;
class ui {
private:
    Controller controller;
    //string input;
public:
    ui();
    void admin_menu();
    void start();
    void addAdmin();
    void deleteAdmin();
    void displayAdmin();
    void generateDatabase();
    void updateAdmin();
    void user_menu();
    //void add_user();
    void remove_user();
    void displayPersonalEventlist();

};


#endif //OOP_A4_5_ELIZALUCHIAN_UI_H
