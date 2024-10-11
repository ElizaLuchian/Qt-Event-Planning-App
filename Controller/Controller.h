//
// Created by 40745 on 24/03/2024.
//

#ifndef OOP_A4_5_ELIZALUCHIAN_CONTROLLER_H
#define OOP_A4_5_ELIZALUCHIAN_CONTROLLER_H



#include "Domain/Event.h"
#include "Repo/FileAdminRepo.h"
#include "Repo/FileUserRepo.h"
#include "Action.h"


class Controller{

private:
    std::string type;
    FileAdminRepo *repo;
    FileUserRepo *repo_user;
    std::vector<Action*> undoStackAdminMode;
    std::vector<Action*> redoStackAdminMode;
    std::vector<Action*> undoStackUserMode;
    std::vector<Action*> redoStackUserMode;
public:
    Controller();
    Controller(std:: string fileName, std::string userFileName);
    explicit Controller(const std::string &type);
    FileAdminRepo* get_admin_repo();
    FileUserRepo* get_user_repo();

    void addController(const Event& event);

    void deleteController(const std::string &title);

    vector<Event> getAllElemsController()const;
    void updateController(const std::string &title, const Event& event);
    void addUserController(const Event& event);
    void removeEventController(const std::string &title);
    vector<Event> getEventsbyMonth(int month)const;
    vector<Event> getAllEventsController()const;
    void undoLastAction(std::vector<Action*>& currentUndoStack, std::vector<Action*>& currentRedoStack);
    void redoLastAction(std::vector<Action*>& currentUndoStack, std::vector<Action*>& currentRedoStack);
    void undoAdminMode();

    void redoAdminMode();

    void undoUserMode();

    void redoUserMode();

    void readFromFile();


};


#endif //OOP_A4_5_ELIZALUCHIAN_CONTROLLER_H
