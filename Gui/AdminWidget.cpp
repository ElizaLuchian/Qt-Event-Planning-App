#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDialog>
#include <QPushButton>
#include "AdminWidget.h"
#include <QMessageBox>
#include <QKeyEvent>
#include <stdlib.h>
#include "InputValidator.h" // Include InputValidator header

using namespace std;

AdminWidget::AdminWidget(Controller *controller) {
    this->controller = controller;
    QGridLayout* adminlayout = new QGridLayout{this};
    QLabel* textInterface = new QLabel("Admin Interface");
    adminlayout->addWidget(textInterface);

    QLabel* titleLabel = new QLabel{ "Title" };
    this->titleEdit = new QLineEdit{};
    QLabel* descriptionLabel = new QLabel{ "Description" };
    this->descriptionEdit = new QLineEdit{};
    QLabel* linkLabel = new QLabel{ "Link" };
    this->linkEdit = new QLineEdit{};

    QLabel* numberOfPeopleLabel = new QLabel{ "Number of People" };
    this->number_of_peopleEdit = new QLineEdit{};
    QLabel* dayLabel = new QLabel{ "day" };
    this->dayEdit = new QLineEdit{};
    QLabel* monthLabel = new QLabel{ "month" };
    this->monthEdit = new QLineEdit{};
    QLabel* yearLabel = new QLabel{ "year" };
    this->yearEdit = new QLineEdit{};
    QLabel* hoursLabel = new QLabel{ "hours" };
    this->hourEdit = new QLineEdit{};
    QLabel* minutesLabel = new QLabel{ "minutes" };
    this->minutesEdit = new QLineEdit{};

    adminlayout->addWidget(titleLabel, 1, 0);
    adminlayout->addWidget(this->titleEdit, 1, 1);
    adminlayout->addWidget(descriptionLabel, 2, 0);
    adminlayout->addWidget(this->descriptionEdit, 2, 1);
    adminlayout->addWidget(linkLabel, 3, 0);
    adminlayout->addWidget(this->linkEdit, 3, 1);
    adminlayout->addWidget(numberOfPeopleLabel, 4, 0);
    adminlayout->addWidget(this->number_of_peopleEdit, 4, 1);
    adminlayout->addWidget(dayLabel, 5, 0);
    adminlayout->addWidget(this->dayEdit, 5, 1);
    adminlayout->addWidget(monthLabel, 6, 0);
    adminlayout->addWidget(this->monthEdit, 6, 1);
    adminlayout->addWidget(yearLabel, 7, 0);
    adminlayout->addWidget(this->yearEdit, 7, 1);
    adminlayout->addWidget(hoursLabel, 8, 0);
    adminlayout->addWidget(this->hourEdit, 8, 1);
    adminlayout->addWidget(minutesLabel, 9, 0);
    adminlayout->addWidget(this->minutesEdit, 9, 1);

    QPushButton* addButton = new QPushButton("ADD");
    QPushButton* deleteButton = new QPushButton("DELETE");
    QPushButton* updateButton = new QPushButton("UPDATE");
    QPushButton* listButton = new QPushButton("SHOW DATABASE");
    QPushButton* OpenHTML_CSVFile = new QPushButton("OPEN HTML OR CSV FILE");
    QPushButton* UNDO = new QPushButton("UNDO");
    QPushButton* REDO = new QPushButton("REDO");

    adminlayout->addWidget(addButton, 1, 4);
    adminlayout->addWidget(deleteButton, 2, 4);
    adminlayout->addWidget(updateButton, 3, 4);
    adminlayout->addWidget(listButton, 4, 4);
    adminlayout->addWidget(OpenHTML_CSVFile, 5, 4);
    adminlayout->addWidget(UNDO, 6, 4);
    adminlayout->addWidget(REDO, 7, 4);

    QObject::connect(addButton, &QPushButton::clicked, this, &AdminWidget::addButtonMethod);
    QObject::connect(deleteButton, &QPushButton::clicked, this, &AdminWidget::deleteButtonMethod);
    QObject::connect(updateButton, &QPushButton::clicked, this, &AdminWidget::updateButtonMethod);
    QObject::connect(listButton, &QPushButton::clicked, this, &AdminWidget::listApp);
    QObject::connect(OpenHTML_CSVFile, &QPushButton::clicked, this, &AdminWidget::OpenCSV_HTMLfile);
    QObject::connect(UNDO, &QPushButton::clicked, this, &AdminWidget::UndoMethod);
    QObject::connect(REDO, &QPushButton::clicked, this, &AdminWidget::RedoMethod);
    undoShortcut=new QShortcut(QKeySequence("Ctrl+Z"),this);
    redoShortcut=new QShortcut(QKeySequence("Ctrl+Y"), this);
    connect(undoShortcut, &QShortcut::activated, this, &AdminWidget::UndoMethod);
    connect(redoShortcut, &QShortcut::activated, this, &AdminWidget::RedoMethod);

}

void AdminWidget::addButtonMethod() {
    try {
        QString title = this->titleEdit->text();
        QString description = this->descriptionEdit->text();
        QString link = this->linkEdit->text();
        QString numberOfPeople = this->number_of_peopleEdit->text();
        QString day = this->dayEdit->text();
        QString month = this->monthEdit->text();
        QString year = this->yearEdit->text();
        QString hours = this->hourEdit->text();
        QString minutes = this->minutesEdit->text();

        // Validate inputs
        InputValidator::isTitle(title.toStdString());
        InputValidator::isNonEmptyString(title.toStdString());
        InputValidator::isNonEmptyString(description.toStdString());
        InputValidator::isNonEmptyString(link.toStdString());
        InputValidator::isNonNegative(numberOfPeople.toInt());
        InputValidator::isDay(day.toInt());
        InputValidator::isMonth(month.toInt());
        InputValidator::isNonNegative(year.toInt());
        InputValidator::isHour(hours.toInt());
        InputValidator::isMinutes(minutes.toInt());

        Event event = Event(title.toStdString(), description.toStdString(), numberOfPeople.toInt(), link.toStdString(), day.toInt(), month.toInt(), year.toInt(), minutes.toInt(), hours.toInt());
        this->controller->addController(event);
    } catch (const std::exception &e) {
        showError(e.what());
    }
}

void AdminWidget::deleteButtonMethod() {
    try {
        QString title = this->titleEdit->text();
        InputValidator::isTitle(title.toStdString());
        InputValidator::isNonEmptyString(title.toStdString());
        this->controller->deleteController(title.toStdString());
    } catch (const std::exception &e) {
        showError(e.what());
    }
}

void AdminWidget::updateButtonMethod() {
    try {
        QString title = this->titleEdit->text();
        QString description = this->descriptionEdit->text();
        QString link = this->linkEdit->text();
        QString numberOfPeople = this->number_of_peopleEdit->text();
        QString day = this->dayEdit->text();
        QString month = this->monthEdit->text();
        QString year = this->yearEdit->text();
        QString hours = this->hourEdit->text();
        QString minutes = this->minutesEdit->text();

        // Validate inputs
        InputValidator::isTitle(title.toStdString());
        InputValidator::isNonEmptyString(title.toStdString());
        InputValidator::isNonEmptyString(description.toStdString());
        InputValidator::isNonEmptyString(link.toStdString());
        InputValidator::isNonNegative(numberOfPeople.toInt());
        InputValidator::isDay(day.toInt());
        InputValidator::isMonth(month.toInt());
        InputValidator::isNonNegative(year.toInt());
        InputValidator::isHour(hours.toInt());
        InputValidator::isMinutes(minutes.toInt());

        Event event = Event(title.toStdString(), description.toStdString(), numberOfPeople.toInt(), link.toStdString(), day.toInt(), month.toInt(), year.toInt(), minutes.toInt(), hours.toInt());
        this->controller->updateController(title.toStdString(), event);
    } catch (const std::exception &e) {
        showError(e.what());
    }
}

void AdminWidget::updateController(Controller *controller) {
    this->controller = controller;
}

void AdminWidget::listApp() {
    try {
        QWidget *windowDatabase = new QWidget;
        QListWidget *eventListWidget = new QListWidget{windowDatabase};
        eventListWidget->clear();
        for (auto &elem : this->controller->getAllElemsController()) {
            QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(elem.getTitle() + "/" + elem.getDescription() + "/" + elem.getLink() + "/" + to_string(elem.getNumberOfPeople()) + "/" + to_string(elem.getDay()) + "." + to_string(elem.getMonth()) + "." + to_string(elem.getYear()) + "..." + to_string(elem.getHours()) + ":" + to_string(elem.getMinutes()))};
            QFont font{ "Verdana", 10, 10 };
            item->setFont(font);
            eventListWidget->addItem(item);
        }

        windowDatabase->show();
    } catch (const std::exception &e) {
        showError(e.what());
    }
}

void AdminWidget::OpenCSV_HTMLfile() {
    try {
        string command = this->controller->get_admin_repo()->generateCommand();
        system(command.c_str());
    } catch (const std::exception &e) {
        showError(e.what());
    }
}

void AdminWidget::showError(const std::string &message) {
    QMessageBox::critical(this, "Error", QString::fromStdString(message));
}

void AdminWidget::UndoMethod() {
    this->controller->undoAdminMode();
}

void AdminWidget::RedoMethod() {
this->controller->redoAdminMode();
}

void AdminWidget::keyPressEvent(QKeyEvent *event) {
    if(event->modifiers() & Qt::ControlModifier ) {
        switch (event->key()) {
            case Qt::Key_Z:
                UndoMethod();
                \
                break;
            case Qt::Key_Y:
                RedoMethod();
                break;
        }
    }
}



