#include <QGridLayout>
#include <QLabel>
#include <QListWidgetItem>
#include "UserWidget.h"
#include <QLineEdit>
#include <QStackedLayout>
#include <QMessageBox>  // For displaying error messages



UserWidget::UserWidget(Controller* controller) {
    this->controller = controller;
    QGridLayout* userlayout = new QGridLayout{this};
    QLabel* textInterface = new QLabel("User Interface");
    userlayout->addWidget(textInterface);


    QLabel* titleLabel = new QLabel{ "Title" };
    this->title = new QLineEdit{};

    QPushButton *SeeAllDatabase = new QPushButton("SEE ALL DATABASE");
    QPushButton *Remove = new QPushButton("REMOVE EVENT");
    QPushButton *SeePersonalList = new QPushButton("SEE PERSONAL LIST");
    QPushButton *OpenHTML_CSVFile = new QPushButton("OPEN HTML OR CSV FILE");
    QPushButton *Undo = new QPushButton("UNDO");
    QPushButton *Redo = new QPushButton("REDO");
    QPushButton *tableView = new QPushButton("OPEN TABLE VIEW");

    userlayout->addWidget(SeeAllDatabase, 0, 2);
    userlayout->addWidget(Remove, 0, 3);
    userlayout->addWidget(SeePersonalList, 0, 4);
    userlayout->addWidget(titleLabel, 1, 0);
    userlayout->addWidget(this->title, 1, 1);
    userlayout->addWidget(OpenHTML_CSVFile, 0, 5);
    userlayout->addWidget(Undo, 2, 0);
    userlayout->addWidget(Redo, 3, 0);
    userlayout->addWidget(tableView, 4, 0);

    QObject::connect(SeeAllDatabase, &QPushButton::clicked, this, &UserWidget::SeeAllDatabase);
    QObject::connect(SeePersonalList, &QPushButton::clicked, this, &UserWidget::SeePersonalList);
    QObject::connect(Remove, &QPushButton::clicked, this, &UserWidget::removeEvent);
    QObject::connect(OpenHTML_CSVFile, &QPushButton::clicked, this, &UserWidget::OpenCSV_HTMLfile);
    QObject::connect(Undo, &QPushButton::clicked, this, &UserWidget::UndoMethod);
    QObject::connect(Redo, &QPushButton::clicked, this, &UserWidget::RedoMethod);
    QObject::connect(tableView, &QPushButton::clicked, this, &UserWidget::SeePersonalListTable);



}

void UserWidget::SeeAllDatabase() {
    try {
        vector<Event> array;
        windowDatabase = new QWidget{};
        QGridLayout *input = new QGridLayout{windowDatabase};

        QLabel *chooseMonth = new QLabel{"Month"};
        this->month = new QLineEdit{};
        input->addWidget(chooseMonth, 1, 0);
        input->addWidget(this->month, 1, 1);

        QPushButton *confirm = new QPushButton("CONFIRM");
        input->addWidget(confirm, 1, 3);
        QObject::connect(confirm, &QPushButton::clicked, this, &UserWidget::ConfirmMethod);

        windowDatabase->show();
    } catch (const std::exception &e) {
        showError(e.what());
    }
}

void UserWidget::SeePersonalList() {
    try {
        QWidget *windowPersonalList = new QWidget;
        QListWidget *eventListWidgetUser = new QListWidget{windowPersonalList};
        eventListWidgetUser->clear();
        for (auto &elem : this->controller->getAllEventsController()) {
            QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(elem.getTitle() + "/" + elem.getDescription() + "/" + elem.getLink() + "/" + to_string(elem.getNumberOfPeople()) + "/" + to_string(elem.getDay()) + "." + to_string(elem.getMonth()) + "." + to_string(elem.getYear()) + "..." + to_string(elem.getHours()) + ":" + to_string(elem.getMinutes()))};
            QFont font{ "Verdana", 10, 10 };
            item->setFont(font);
            eventListWidgetUser->addItem(item);
        }
        windowPersonalList->show();
    } catch (const std::exception &e) {
        showError(e.what());
    }
}

void UserWidget::removeEvent() {
    try {
        QString titleEvent = this->title->text();
        this->controller->removeEventController(titleEvent.toStdString());
    } catch (const std::exception &e) {
        showError(e.what());
    }
}



void UserWidget::addPersonalList(const Event &event) {
    try {
        controller->addUserController(event);
    } catch (const std::exception &e) {
        showError(e.what());
    }
}

void UserWidget::OpenCSV_HTMLfile() {
    try {
        string command = this->controller->get_user_repo()->generateCommand();
        system(command.c_str());
    } catch (const std::exception &e) {
        showError(e.what());
    }
}

void UserWidget::ConfirmMethod() {
    try {
        windowDatabase->close();

        windowListDatabase = new QWidget{};
        QGridLayout *Databaselayout = new QGridLayout{windowListDatabase};
        QWidget *emptyObject = new QWidget{};

        eventlist = new QStackedLayout{emptyObject};
        Databaselayout->addWidget(emptyObject, 1, 0);
        QPushButton *nextButton = new QPushButton{"NEXT"};
        QPushButton *stopButton = new QPushButton{"STOP"};
        QPushButton *addButton = new QPushButton{"ADD"};
        Databaselayout->addWidget(nextButton, 3, 0);
        Databaselayout->addWidget(addButton, 3, 1);
        Databaselayout->addWidget(stopButton, 3, 2);
        QObject::connect(nextButton, &QPushButton::clicked, this, &UserWidget::nextButtonMethod);
        QObject::connect(stopButton, &QPushButton::clicked, this, &UserWidget::stopButtonMethod);
        QObject::connect(addButton, &QPushButton::clicked, this, &UserWidget::addButtonMethod);
        events = controller->getEventsbyMonth(this->month->text().toInt());
        for (auto &el : events) {
            QWidget *event = new QWidget;
            QGridLayout* lay = new QGridLayout{event};
            lay->addWidget(new QLabel{el.getTitle().c_str()}, 1, 0);
            lay->addWidget(new QLabel{el.getDescription().c_str()}, 2, 0);
            lay->addWidget(new QLabel{el.getLink().c_str()}, 3, 0);
            lay->addWidget(new QLabel{std::to_string(el.getNumberOfPeople()).c_str()}, 4, 0);
            lay->addWidget(new QLabel{std::to_string(el.getDay()).c_str()}, 5, 0);
            lay->addWidget(new QLabel{"."}, 5, 1);
            lay->addWidget(new QLabel{std::to_string(el.getMonth()).c_str()}, 5, 2);
            lay->addWidget(new QLabel{"."}, 5, 3);
            lay->addWidget(new QLabel{std::to_string(el.getYear()).c_str()}, 5, 4);
            lay->addWidget(new QLabel{std::to_string(el.getHours()).c_str()}, 6, 0);
            lay->addWidget(new QLabel{":"}, 6, 1);
            lay->addWidget(new QLabel{std::to_string(el.getMinutes()).c_str()}, 6, 2);
            eventlist->addWidget(event);
        }
        eventlist->setCurrentIndex(0);

        windowListDatabase->show();
    } catch (const std::exception &e) {
        showError(e.what());
    }
}

void UserWidget::nextButtonMethod() {
    try {
        if (eventlist->count() - 1 == eventlist->currentIndex())
            eventlist->setCurrentIndex(0);
        else
            eventlist->setCurrentIndex(eventlist->currentIndex() + 1);
    } catch (const std::exception &e) {
        showError(e.what());
    }
}

void UserWidget::stopButtonMethod() {
    try {
        windowListDatabase->close();
    } catch (const std::exception &e) {
        showError(e.what());
    }
}

void UserWidget::addButtonMethod() {
    try {
        controller->addUserController(events[eventlist->currentIndex()]);
    } catch (const std::exception &e) {
        showError(e.what());
    }
}

void UserWidget::showError(const std::string &message) {
    QMessageBox::critical(this, "Error", QString::fromStdString(message));
}

void UserWidget::UndoMethod() {
this->controller->undoUserMode();

}

void UserWidget::RedoMethod() {
this->controller->redoUserMode();

}



void UserWidget::updateController(Controller* controller) {
    this->controller = controller;

}

void UserWidget::SeePersonalListTable() {
    try {
        windowListDatabase = new QWidget{};
        QGridLayout* layout = new QGridLayout{windowListDatabase};

        eventTableModel = new EventTableModel(controller, this);
        eventListTableView = new QTableView{windowListDatabase};
        eventListTableView->setModel(eventTableModel);

        layout->addWidget(eventListTableView, 0, 0);
        windowListDatabase->show();
    } catch (const std::exception &e) {
        showError(e.what());
    }
}