//
// Created by 40745 on 25/03/2024.
//

#include <iostream>
#include "ui.h"
#include "InputValidator.h"
#include <utility>
#include <cstdlib>
#include <QtWidgets/QDialog>
#include <QtWidgets/QvBoxLayout>
#include <QtWidgets/QLabel>
#include <QtCore/QObject>
#include <QtWidgets/QPushButton>


using namespace std;

ui::ui() {

}

void deleteBuffer() {
    cin.clear();
    cin.ignore(100, '\n');
}

void ui::admin_menu() {


    /*QDialog* window= new QDialog();
    QVBoxLayout* vertLayout = new QVBoxLayout;
    QLabel* writing1=  new QLabel("Choose the format of your file CSV/ HTML");
    QLabel* writing2=  new QLabel("1. Add an event into the database.");
    QLabel* writing3=  new QLabel("2. Remove an event from the database.");
    QLabel* writing4=  new QLabel("3. Update an event from the database.");
    QLabel* writing5=  new QLabel("4. Display all the events.");
    QLabel* writing7=  new QLabel("5. Open csv file or html file.");
    QLabel* writing6=  new QLabel("0. Exit.");*/

    cout<<"Choose one of the options below:\n";
    cout<<"1. Add an event into the database.\n";
    cout<<"2. Remove an event from the database.\n";
    cout<<"3. Update an event from the database.\n";
    cout<<"4. Display all the events.\n";
    cout<<"5. Open csv file or html file.\n";
    cout<<"0. Exit.\n";

}

void ui::user_menu() {
   /* QDialog* window= new QDialog();
    QVBoxLayout* vertLayout = new QVBoxLayout;
    QLabel* writing1=  new QLabel("Choose one of the options below:");
    QLabel* writing2=  new QLabel("1. See the events in the database:");
    QLabel* writing3=  new QLabel("2. Delete an event form the personal list:");
    QLabel* writing4=  new QLabel("3.See his own personal list:");
    QLabel* writing5=  new QLabel("4. Open csv file or html file.");
    QLabel* writing6=  new QLabel("0. Exit.");*/
    cout<<"Choose one of the options below:\n";
    cout<<"1.See the events in the database:\n";
    cout<<"2. Delete an event form the personal list:.\n";
    cout<<"3.See his own personal list:\n";

    cout<<"4. Open csv file or html file.\n";
    cout<<"0. Exit.\n";

}

void ui::addAdmin() {
    InputValidator validator;
    char title[100], description[100], link[100];
    int nrPeople, day, month, year, minutes, hour;
    cout << "provide title of the event:  ";
    if (!(cin.getline(title, 100))) {
        deleteBuffer();
        throw exception();
    }
    validator.isNonEmptyString(title);
    validator.isTitle(title);


    cout << "provide description of the event:  ";
    if (!(cin.getline(description, 100))) {
        deleteBuffer();
        throw exception();
    }
    validator.isNonEmptyString(description);

    cout << "provide link to the event";
    if (!(cin.getline(link, 100))) {
        deleteBuffer();
        throw exception();
    }

    validator.isNonEmptyString(link);

    cout << "provide number of people at the event:  ";
    if (!(cin >> nrPeople)) {
        deleteBuffer();
        throw exception();
    }

    validator.isNonNegative(nrPeople);


    cout << "provide day: ";
    if (!(cin >> day)) {
        deleteBuffer();
        throw exception();
    }
    validator.isNonNegative(day);
    validator.isDay(day);
    cout << "provide month: ";
    if (!(cin >> month)) {
        deleteBuffer();
        throw exception();
    }
    validator.isNonNegative(month);
    validator.isMonth(month);
    cout << "provide year: ";
    if (!(cin >> year)) {
        deleteBuffer();
        throw exception();
    }
    validator.isNonNegative(year);
    cout << "provide the minutes: ";
    if (!(cin >> minutes)) {
        deleteBuffer();
        throw exception();
    }
    validator.isNonNegative(minutes);
    validator.isMinutes(minutes);

    cout << "provide the hour: ";
    if (!(cin >> hour)) {
        deleteBuffer();
        throw exception();
    }
    validator.isNonNegative(hour);
    validator.isHour(hour);
    Event event = Event(title, description, nrPeople, link, day, month, year, minutes, hour);

    controller.addController(event);
}

void ui::updateAdmin() {
    InputValidator validator;
    char title[100], description[100], link[100];
    int nrPeople, day, month, year, minutes, hour;
    cout << "provide title of the event:  ";
    if (!(cin.getline(title, 100))) {
        deleteBuffer();
        throw exception();

    }
    validator.isNonEmptyString(title);
    validator.isTitle(title);




    cout << "provide description of the event or empty space to not change it:  ";
    if (!(cin.getline(description, 100))) {
        deleteBuffer();
        throw exception();
    }

    validator.isNonEmptyString(description);

    cout << "provide link to the event or empty space to not change it: ";
    if (!(cin.getline(link, 100))) {
        deleteBuffer();
        throw exception();
    }

    validator.isNonEmptyString(link);

    cout << "provide number of people at the event or -1 to not change it:  ";
    if (!(cin >> nrPeople)) {
        deleteBuffer();
        throw exception();
    }

    validator.isNonNegative(nrPeople);

    cout << "provide day or -1 to not change it: ";
    if (!(cin >> day)) {
        deleteBuffer();
        throw exception();
    }
    validator.isNonNegative(day);
    validator.isDay(day);

    cout << "provide month or -1 to not change it: ";
    if (!(cin >> month)) {
        deleteBuffer();
        throw exception();
    }

    validator.isMonth(month);

    cout << "provide year or -1 to not change it: ";
    if (!(cin >> year)) {
        deleteBuffer();
        throw exception();
    }
    validator.isNonNegative(year);

    cout << "provide the minutes or -1 to not change it: ";
    if (!(cin >> minutes)) {
        deleteBuffer();
        throw exception();
    }
    validator.isMinutes(minutes);
    validator.isNonNegative(minutes);

    cout << "provide the hour or -1 to not change it: ";
    if (!(cin >> hour)) {
        deleteBuffer();
        throw exception();
    }
    validator.isHour(hour);
    validator.isNonNegative(hour);

    Event event = Event(title, description, nrPeople, link, day, month, year, minutes, hour);

    controller.updateController(title, event);
}

void ui::deleteAdmin() {
    InputValidator validator;
    string title;
    cout << "provide the title for searching: ";
    cin >> title;
    validator.isNonEmptyString(title);
    validator.isTitle(title);


    controller.deleteController(title);

}

void ui::displayAdmin() {
    vector<Event> array = controller.getAllElemsController();
    for (auto &elem: array) {
        cout << "title: " << elem.getTitle() << endl;
        cout << "description: " << elem.getDescription() << endl;
        cout << "link: " << elem.getLink() << endl;
        cout << "number of people: " << elem.getNumberOfPeople() << endl;
        cout << "date:" << elem.getDay() << " " << elem.getMonth() << " "
             << elem.getYear() << " " << "time:  " << elem.getHours() << ":" << elem.getMinutes() << endl << endl;

    }
    // controller.writeFile();
}


void ui::remove_user() {
    InputValidator validator;
    char title[100];

    cout << "provide the title of the event you want to remove:  ";
    cin.getline(title, 100);
    validator.isNonEmptyString(title);
    validator.isTitle(title);
    controller.removeEventController(title);
}

void ui::displayPersonalEventlist() {
    vector<Event> array = controller.getAllEventsController();
    for (auto &elem: array) {
        cout << "title: " << elem.getTitle() << endl;
        cout << "description: " << elem.getDescription() << endl;
        cout << "link: " << elem.getLink() << endl;
        cout << "number of people: " << elem.getNumberOfPeople() << endl;
        cout << "date:" << elem.getDay() << " " << elem.getMonth() << " "
             << elem.getYear() << " " << "time:  " << elem.getHours() << ":" << elem.getMinutes() << endl << endl;

    }

}

void ui::start() {
    char input[100], inputFormat[100], inputFormat2[100];
    int number, month, choice, choicetoendit = 1;

    cout<<"input for file format:\n";
    /*QDialog* window= new QDialog();
    QVBoxLayout* vertLayout = new QVBoxLayout;
    QLabel* writing6=  new QLabel("Choose the format of your file CSV/ HTML");
    QPushButton* writing7=  new QPushButton("Start CSV button");
    QPushButton* writing8=  new QPushButton("Start Html button");




    vertLayout->addWidget(writing6);
    vertLayout->addWidget(writing7);
    vertLayout->addWidget(writing8);
    QObject::connect(writing8, &QPushButton::clicked, [&](){
        controller=Controller("html");
        controller.readFromFile();
        controller.get_admin_repo()->writeToFile();
        controller.get_user_repo()->writeToFile();
        window->close();
    });
    QObject::connect(writing7, &QPushButton::clicked, [&](){
        controller=Controller("csv");
        controller.readFromFile();
        controller.get_admin_repo()->writeToFile();
        controller.get_user_repo()->writeToFile();
        window->close();
    });
    window->setLayout(vertLayout);
    window->show();*/

   cin.getline(inputFormat,100);
    controller=Controller(inputFormat);
    controller.readFromFile();
    controller.get_admin_repo()->writeToFile();
    controller.get_user_repo()->writeToFile();




    while (1) {
        try {
            cout << "provide option(admin/user):    ";
            cin >> input;


            if (string(input) == "admin") {
                admin_menu();
                cout << "provide option(number between 1-4 or 0):    ";

                if (!(cin >> number)) {
                    deleteBuffer();
                    throw exception();
                }
                cin.get();
                if (number == 1)
                    addAdmin();

                else if (number == 2)
                    deleteAdmin();
                else if (number == 3)
                    updateAdmin();
                else if (number == 4) {
                    displayAdmin();
                    cout << controller.getAllElemsController().size() << endl;
                }
                else if(number==5)
                {
                    string command = controller.get_admin_repo()->generateCommand();
                    system(command.c_str());
                }
                else if (number == 0)
                    return;
                else {
                    cout << "number should be between 1-4" << endl;
                    continue;
                }


            } else if (string(input) == "user") {
                user_menu();
                cout << "provide option(number between 1-3 or 0):    ";
                if (!(cin >> number)) {
                    deleteBuffer();
                    throw exception();
                }
                cin.get();
                if (number == 1) {
                    cout << "please introduce the month after you are searching:   ";
                    cin >> month;
                    vector<Event> list = controller.getEventsbyMonth(month);

                    if (list.size() == 0) {
                        cout << "there are no events in that month\n";
                        return;
                    }
                    choicetoendit = 1;
                    while (choicetoendit) {
                        for (auto &elem: list) {
                            cout << "title: " << elem.getTitle() << endl;
                            cout << "description: " << elem.getDescription() << endl;

                            cout << "number of people: " << elem.getNumberOfPeople() << endl;
                            cout << "date:" << elem.getDay() << " " << elem.getMonth()
                                 << " "
                                 << elem.getYear() << " " << "time:  "
                                 << elem.getHours()
                                 << ":" << elem.getMinutes() << endl << endl;
                            cout << "link: " << elem.getLink() << endl;
                            string command = "start " + elem.getLink();
                            system(command.c_str());
                            // ShellExecute(NULL,"open", list.eventAtIndex(i).getLink().c_str(),NULL,NULL,SW_SHOWNORMAL);

                            if (list.size() != controller.getAllEventsController().size()) {
                                cout << "do you wish to add this event to your event list?Write 1 if you want\n";
                                cin >> choice;
                                if (choice == 1)
                                    controller.addUserController(elem);
                            } else
                                cout << "you added all the events to your list\n";
                            cout << "do you wish to continue, choose 0 if not:\n";
                            cin >> choicetoendit;
                            if (choicetoendit == 0)
                                break;


                        }
                    }
                    continue;
                } else if (number == 3)
                    remove_user();
                else if (number == 4)
                    displayPersonalEventlist();
                else if (number ==5)
                {
                    string command = controller.get_user_repo()->generateCommand();
                    system(command.c_str());
                }
                else if (number == 0)
                    break;
            } else
                cout << "try again writing admin or user" << endl;


        }

        catch (exception &exception) {
            cout << exception.what() << "\n";
        }

    }


}












