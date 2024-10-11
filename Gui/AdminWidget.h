//
// Created by 40745 on 13/05/2024.
//

#ifndef OOP_A6_7_ELIZALUCHIAN_ADMINWIDGET_H
#define OOP_A6_7_ELIZALUCHIAN_ADMINWIDGET_H
#include <QWidget>
#include <QListWidget>
#include <QShortcut>
#include "Controller/Controller.h"


class AdminWidget: public QWidget {
private:
    Controller* controller;
    QShortcut *undoShortcut;
    QShortcut *redoShortcut;



public:
    AdminWidget(Controller* controller);

    QLineEdit *titleEdit;
    QLineEdit *descriptionEdit;
    QLineEdit *linkEdit;

    QLineEdit *number_of_peopleEdit;
    QLineEdit *dayEdit;
    QLineEdit *monthEdit;
    QLineEdit *yearEdit;
    QLineEdit *hourEdit;
    QLineEdit *minutesEdit;


    void addButtonMethod();
    void deleteButtonMethod();
    void updateButtonMethod();

    void updateController(Controller* controller);
    void listApp();
    void OpenCSV_HTMLfile();
    void UndoMethod();
    void RedoMethod();


    void showError(const string &message);
    void keyPressEvent(QKeyEvent* event) override;

};


#endif //OOP_A6_7_ELIZALUCHIAN_ADMINWIDGET_H
