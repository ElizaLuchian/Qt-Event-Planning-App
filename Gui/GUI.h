//
// Created by 40745 on 10/05/2024.
//

#ifndef OOP_A6_7_ELIZALUCHIAN_GUI_H
#define OOP_A6_7_ELIZALUCHIAN_GUI_H


#include <QtWidgets/QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QStackedLayout>
#include "Controller/Controller.h"
#include "AdminWidget.h"
#include "UserWidget.h"

class GUI : public QWidget {
private:
    Controller* controller;
    int choice;
    QStackedLayout *mainLayout;


    AdminWidget *adminWidget;
    UserWidget *userWidget;



    void buildGui();


public:

    GUI();

    void HTMLController();

    void CSVController();

    void AdminMode();

    void UserMode();

    void startApp();
    //void listApp();
};


#endif //OOP_A6_7_ELIZALUCHIAN_GUI_H
