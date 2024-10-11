//
// Created by 40745 on 26/03/2024.
//

#include "Tests.h"


#include "Controller/Controller.h"
#include <cassert>
#include <algorithm>
#include <iostream>
#include <fstream>

void setUp(const string &adminFileName, const string &userFileName) {
    ofstream file1(adminFileName);
    ofstream file2(userFileName);
    file1.close();
    file2.close();
}

void tearDown(const string &adminFileName, const string &userFileName) {
    remove(adminFileName.c_str());
    remove(userFileName.c_str());
}

void testAdd() {
    string adminFileName = "testAdmin.txt";
    string userFileName = "testUser.txt";
    setUp(adminFileName, userFileName);
    Controller controller = Controller(adminFileName, userFileName);
    int initialsize = controller.getAllElemsController().size();

    Event event = Event("EventTitle", "EventDescription", 90, "EventLink", 3, 3, 2004, 20, 11);

    controller.addController(event);


    vector<Event> array = controller.getAllElemsController();


    assert(array.size() == initialsize + 1);
    Event event1 = Event("EventTitle", "EventDescription", 90, "EventLink", 3, 3, 2004, 20, 11);
    try {
        controller.addController(event1);
        assert(false);
    }
    catch (std::exception &exception) { assert(true); }

    tearDown(adminFileName, userFileName);
}


void testDelete() {
    string adminFileName = "testAdmin.txt";
    string userFileName = "testUser.txt";
    setUp(adminFileName, userFileName);
    Controller controller = Controller(adminFileName, userFileName);
    FileAdminRepo repo = *controller.get_admin_repo();

    int initialsize = controller.getAllElemsController().size();
    Event event = Event("Title", "Description", 80, "Link", 15, 6, 2025, 35, 12);

    controller.addController(event);


    controller.deleteController("Title");


    vector<Event> arr = controller.getAllElemsController();


    assert(arr.size() == initialsize);
    try {
        repo.deleteRepo("Title");
        assert(false);
    }
    catch (std::exception &exception) {
        assert(true);
    }

    tearDown(adminFileName, userFileName);
}


void testUpdateEvent() {
    string adminFileName = "testAdmin.txt";
    string userFileName = "testUser.txt";
    setUp(adminFileName, userFileName);
    Controller controller = Controller(adminFileName, userFileName);
    FileAdminRepo repo = *controller.get_admin_repo();


    Event event = Event("Title", "Description", 400, "Link", 2, 2, 2003, 30, 10);

    controller.addController(event);


    Event event1 = Event("Title", "Description123", 200, "Link123", 2, 5, 2004, 0, 7);
    controller.updateController("Title", event1);

    // Retrieve all events
    vector<Event> events = controller.getAllElemsController();

    // Find the updated event
    auto iterator = search_n(events.begin(), events.end(), 1, "Title", Event::TitleEqual);
    assert(iterator != events.end()); // Event should exist

    // Retrieve the updated event
    Event updatedEvent = *iterator;


    // Check if the event is updated correctly
    assert(updatedEvent.getDescription() == "Description123");
    assert(updatedEvent.getLink() == "Link123");
    assert(updatedEvent.getNumberOfPeople() == 200);

    assert(updatedEvent.getYear() == 2004);
    assert(updatedEvent.getMonth() == 5);
    assert(updatedEvent.getDay() == 2);
    assert(updatedEvent.getHours() == 7);
    assert(updatedEvent.getMinutes() == 0);

    try {
        repo.updateRepo("123", event1);
        assert(false);
    }
    catch (std::exception &exception) { assert(true); }
    controller.deleteController(event.getTitle());

    tearDown(adminFileName, userFileName);
}

void testAddUser() {
    string adminFileName = "testAdmin.txt";
    string userFileName = "testUser.txt";
    setUp(adminFileName, userFileName);
    Controller controller = Controller(adminFileName, userFileName);
    FileUserRepo repo = *controller.get_user_repo();
    int initialsize = controller.getAllElemsController().size();
    Event event = Event("EventTitle", "EventDescription", 90, "EventLink", 3, 3, 2004, 20, 11);
    controller.addController(event);
    controller.addUserController(event);


    vector<Event> array = controller.getAllEventsController();


    assert(array.size() == 1);


    tearDown(adminFileName, userFileName);

}

void testDeleteUser() {
    string adminFileName = "testAdmin.txt";
    string userFileName = "testUser.txt";
    setUp(adminFileName, userFileName);
    Controller controller = Controller(adminFileName, userFileName);

    int initialsize = controller.getAllElemsController().size();
    Event event = Event("Title", "Description", 80, "Link", 15, 6, 2025, 35, 12);
    controller.addController(event);
    controller.addUserController(event);


    controller.removeEventController("Title");


    vector<Event> arr = controller.getAllEventsController();


    assert(arr.size() == 0);


    tearDown(adminFileName, userFileName);

}

void testGetEventsbyMont() {
    string adminFileName = "testAdmin.txt";
    string userFileName = "testUser.txt";
    setUp(adminFileName, userFileName);
    Controller controller = Controller(adminFileName, userFileName);
    int initialsize = controller.getEventsbyMonth(7).size();
    Event event = Event("Title2", "Description", 80, "Link", 15, 6, 2025, 35, 12);
    Event event1 = Event("Title1", "Description", 80, "Link", 23, 7, 2025, 35, 12);
    Event event2 = Event("Title", "Description", 80, "Link", 15, 7, 2025, 35, 12);
    controller.addController(event);
    controller.addController(event1);
    controller.addController(event2);
    vector<Event> array = controller.getEventsbyMonth(7);
    assert(array.size() == 2);

    assert(array[0].getTitle() == "Title1");
    assert(array[1].getTitle() == "Title");

    vector<Event> arr = controller.getEventsbyMonth(-1);
    assert(arr.size() == 3);

    assert(arr[0].getTitle() == "Title2");
    assert(arr[1].getTitle() == "Title");
    assert(arr[2].getTitle() == "Title1");


    tearDown(adminFileName, userFileName);
}

void testSetTitle() {
    Event event = Event("Title2", "Description", 80, "Link", 15, 6, 2025, 35, 12);
    event.setTitle("Title");
    assert(event.getTitle() == "Title");
}

Tests::Tests() {
    testAdd();
    testAddUser();
    testDeleteUser();
    testDelete();
    testSetTitle();
    testGetEventsbyMont();
    testUpdateEvent();
}
