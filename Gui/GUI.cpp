//
// Created by 40745 on 10/05/2024.
//

#include <QHBoxLayout>
#include <QLabel>
#include "GUI.h"
#include "AdminWidget.h"
#include "UserWidget.h"

#include <QLineEdit>
#include <QStackedWidget>
#include <QStackedLayout>


GUI::GUI() {
    controller = new Controller();
    this->buildGui();
    //this->populateList();
    //QObject::connect(this->addButton, &QPushButton::clicked, this, &GUI::addButtonHandler);

}

void GUI::buildGui()
{
     mainLayout= new QStackedLayout{this};
    QWidget* chooseLayout=new QWidget;
    QGridLayout* choosingLayout= new QGridLayout{chooseLayout};
    QPushButton* htmlbutton = new QPushButton("HTML");
    QPushButton* csvbutton = new QPushButton("CSV");
    QPushButton* adminbutton = new QPushButton("ADMIN");
    QPushButton* userbutton = new QPushButton("USER");
    QPushButton* startAppButton = new QPushButton("StartApp");


    choosingLayout->addWidget(htmlbutton, 0, 0);
    choosingLayout->addWidget(csvbutton, 0, 1);
    choosingLayout->addWidget(adminbutton, 1, 0);
    choosingLayout->addWidget(userbutton, 1, 1);
    choosingLayout->addWidget(startAppButton, 2, 0);

    QObject::connect(htmlbutton, &QPushButton::clicked, this, &GUI::HTMLController);
    QObject::connect(csvbutton, &QPushButton::clicked, this, &GUI::CSVController);
    QObject::connect(adminbutton, &QPushButton::clicked, this, &GUI::AdminMode);
    QObject::connect(userbutton, &QPushButton::clicked, this, &GUI::UserMode);
    QObject::connect(startAppButton, &QPushButton::clicked, this, &GUI::startApp);


    mainLayout->addWidget(chooseLayout);
    mainLayout->setCurrentIndex(0);


    adminWidget = new AdminWidget(this->controller);

   QWidget* adminInterface= (QWidget*) adminWidget;
    userWidget = new UserWidget(this->controller);
    QWidget* userInterface=(QWidget*)userWidget;

    mainLayout->addWidget(adminInterface);
    mainLayout->addWidget(userInterface);


}

void GUI::HTMLController() {
    this->controller=new Controller("html");
    adminWidget->updateController(this->controller);
    userWidget->updateController(this->controller);

}

void GUI::CSVController() {
    this->controller=new Controller("csv");
    adminWidget->updateController(this->controller);
    userWidget->updateController(this->controller);


}

void GUI::startApp() {
    mainLayout->setCurrentIndex(choice);



}

void GUI::AdminMode() {
choice=1;

}

void GUI::UserMode() {
choice=2;
}

