//
// Created by 40745 on 24/03/2024.
//

#include <algorithm>
#include "Controller.h"
#include "Repo/HtmlAdminFile.h"
#include "Repo/HtmlUserFile.h"
#include "Repo/CsvAdminFile.h"
#include "Repo/CsvUserFile.h"

int CalculateDate(DateTime date)
{
int sum=date.getYear()*3650000+ date.getMonth()*12000+ date.getDay()*100+date.getHours()*10+date.getMinutes();
return sum;
}
bool CompareDate(Event ev1, Event ev2)
{
    int d1= CalculateDate(ev1.getDate());
    int d2= CalculateDate(ev2.getDate());
    return (d1<d2);
}
FileAdminRepo* Controller::get_admin_repo(){
    return repo;
}

void Controller::addController(const Event& event){
        repo->addRepo(event);
    Action* currentAction = new AddAction(this->repo, event);
    this->undoStackAdminMode.push_back(currentAction);
    this->redoStackAdminMode.clear();
}


void  Controller::deleteController(const std::string &title) {
    Event eventgood=repo->getElemwithTitle(title);
    repo->deleteRepo(title) ;

    Action* currentAction = new DeleteAction(this->repo, eventgood);
    this->undoStackAdminMode.push_back(currentAction);
    this->redoStackAdminMode.clear();
}
vector<Event> Controller::getAllElemsController() const{
    return repo->getAllElements();
}

Controller::Controller() : repo(), repo_user() {
}
void Controller::updateController(const std::string& title, const Event& event) {
    Event prevEvent = repo->getElemwithTitle(title);
    Event newEvent = repo->getElemwithTitle(title);
    if(!event.getDescription().empty())
        newEvent.setDescription(event.getDescription());
    if(!event.getLink().empty())
        newEvent.setLink(event.getLink());
    if(event.getNumberOfPeople()!=-1)
        newEvent.setNPeople(event.getNumberOfPeople());
    if(event.getDay()!=-1)
        newEvent.setDay(event.getDay());
    if(event.getMonth()!=-1)
        newEvent.setMonth(event.getMonth());
    if(event.getYear()!=-1)
        newEvent.setYear(event.getYear());
    if(event.getMinutes()!=-1)
        newEvent.setMinutes(event.getMinutes());
    if(event.getHours()!=-1)
        newEvent.setHours(event.getHours());
    repo->updateRepo(title, newEvent);

    Action* currentAction = new UpdateAction(this->repo, prevEvent, newEvent);
    this->undoStackAdminMode.push_back(currentAction);
    this->redoStackAdminMode.clear();
}

FileUserRepo* Controller::get_user_repo(){
    return repo_user;
}

void Controller::addUserController(const Event &event) {
   vector<Event>arr=repo->getAllElements();

    //Event event1=repo.getElemwithTitle(event.getTitle());
    repo_user->addEventUser(event);

    auto iterator=search_n(arr.begin(), arr.end(), 1, event.getTitle(), Event::TitleEqual);
    Event event1=*iterator;
   event1.setNPeople(event.getNumberOfPeople()+1);

    repo->updateRepo(event.getTitle(),event1);

    Action* currentAction = new AddUserAction(this->repo_user,event);
    this->undoStackUserMode.push_back(currentAction);
    this->redoStackUserMode.clear();


}

void Controller::removeEventController(const std::string& title) {
    vector<Event>arr=repo->getAllElements();
    Event event=repo->getElemwithTitle(title);
repo_user->removeEventUser(title);

    auto iterator=search_n(arr.begin(), arr.end(), 1, event.getTitle(), Event::TitleEqual);
    Event event1=*iterator;
    event1.setNPeople(event.getNumberOfPeople()-1);
    repo->updateRepo(title,event1);

    Action* currentAction = new RemoveUserAction(this->repo_user,event);
    this->undoStackUserMode.push_back(currentAction);
    this->redoStackUserMode.clear();
}


vector<Event> Controller::getEventsbyMonth(int month) const {
    vector<Event> array=repo->getAllElements();
    vector<Event> arr;

    Event aux;
    if(month!=-1)
    {for(auto &elem : array)
        {
        if(elem.getMonth()==month)
            arr.push_back(elem);}
    return arr;}
    else
    {
      sort(array.begin(),array.end(), CompareDate);
        return array;
    }


}

vector<Event> Controller::getAllEventsController() const {
    return this->repo_user->getEventList();
}

void Controller::readFromFile() {
    repo->readFromFile();
    repo_user->readFromFile();
}

Controller::Controller( std::string adminFileName, std::string userFileName) : repo{new FileAdminRepo(adminFileName)}, repo_user{new FileUserRepo(userFileName)} {
}

Controller::Controller(const string &type) {

    if(type=="html")
    {
        repo=new HtmlAdminFile("AdminFile");
        repo_user=new HtmlUserFile("UserFile");


    }
    else if(type=="csv")
    {
        repo=new CsvAdminFile("AdminFile");
        repo_user=new CsvUserFile("UserFile");
    }
    else
    {    repo=new FileAdminRepo("AdminFile");
        repo_user=new FileUserRepo("UserFile");
    }

    readFromFile();
}
void Controller::undoLastAction(std::vector<Action*> &currentUndoStack, std::vector<Action*> &currentRedoStack) {
    if (currentUndoStack.empty()) {
        return;
    }

    Action* currentAction = currentUndoStack.back();
    currentAction->Undofunction();
    currentRedoStack.push_back(currentAction);
    currentUndoStack.pop_back();
}

void Controller::redoLastAction(std::vector<Action*> &currentUndoStack, std::vector<Action*> &currentRedoStack) {
    if (currentRedoStack.size() == 0) {
        return;
    }

    Action* currentAction = currentRedoStack.back();
    currentAction->Redofunction();
    currentUndoStack.push_back(currentAction);
    currentRedoStack.pop_back();
}

void Controller::undoAdminMode() {
    this->undoLastAction(this->undoStackAdminMode, this->redoStackAdminMode);
}

void Controller::redoAdminMode() {
    this->redoLastAction(this->undoStackAdminMode, this->redoStackAdminMode);
}

void Controller::undoUserMode() {
    this->undoLastAction(this->undoStackUserMode, this->redoStackUserMode);
}

void Controller::redoUserMode() {
    this->redoLastAction(this->undoStackUserMode, this->redoStackUserMode);
}