//
// Created by 40745 on 13/05/2024.
//

#ifndef OOP_A6_7_ELIZALUCHIAN_USERWIDGET_H
#define OOP_A6_7_ELIZALUCHIAN_USERWIDGET_H


#include <QPushButton>
#include <QStackedLayout>
#include "Controller/Controller.h"

#include "EventTableModel.h"
#include <QTableView>


class UserWidget: public QWidget {
private:
    Controller* controller;

    QLineEdit* title;
    QLineEdit* choiceToEdit;
    QLineEdit* month;
    int choice=1;
    QWidget *windowDatabase;
    QWidget *windowListDatabase;


    QTableView* eventListTableView;
    EventTableModel* eventTableModel;





public:
    UserWidget(Controller* controller);
    void SeeAllDatabase();
    void SeePersonalList();
    void removeEvent();
    void updateController(Controller* controller);
    void addPersonalList(const Event& event);
    void OpenCSV_HTMLfile();
    void ConfirmMethod();
    void nextButtonMethod();
    void stopButtonMethod();
    void addButtonMethod();
    void UndoMethod();
    void RedoMethod();
void SeePersonalListTable();

    QStackedLayout* eventlist;
    vector<Event> events;
    void showError(const string &message);







};


#endif //OOP_A6_7_ELIZALUCHIAN_USERWIDGET_H
