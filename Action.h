//
// Created by 40745 on 02/06/2024.
//

#ifndef OOP_A6_7_ELIZALUCHIAN_ACTION_H
#define OOP_A6_7_ELIZALUCHIAN_ACTION_H


#include "Repo/FileAdminRepo.h"
#include "Repo/FileUserRepo.h"

class Action {
public:
    virtual void Undofunction()=0;
    virtual void Redofunction()=0;



};
class AddAction: public Action{
private:
    FileAdminRepo *repo;
    //FileUserRepo *repo_user;
     Event event;


public:
    AddAction(FileAdminRepo* repo, Event event);
    void Undofunction()override;
    void Redofunction()override;
};

#endif //OOP_A6_7_ELIZALUCHIAN_ACTION_H

class DeleteAction: public Action{
private:
    FileAdminRepo *repo;
    Event event;
public:

    DeleteAction(FileAdminRepo* repo, Event event);
    void Undofunction()override;
    void Redofunction()override;
};

class UpdateAction: public Action{
private:
    FileAdminRepo *repo;
    Event event;
    Event newevent;
public:

    UpdateAction(FileAdminRepo* repo, Event event, Event newevent);
    void Undofunction()override;
    void Redofunction()override;
};

class AddUserAction: public Action{
private:
    FileUserRepo *repo_user;
    Event event;
public:

    AddUserAction(FileUserRepo* repo, Event event);
    void Undofunction()override;
    void Redofunction()override;
};

class RemoveUserAction: public Action{
private:
    FileUserRepo *repo_user;
    Event event;
public:

    RemoveUserAction(FileUserRepo* repo, Event event);
    void Undofunction()override;
    void Redofunction()override;
};

