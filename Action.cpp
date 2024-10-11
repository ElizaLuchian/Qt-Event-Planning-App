//
// Created by 40745 on 02/06/2024.
//

#include "Action.h"

AddAction::AddAction(FileAdminRepo *repo,  Event event):repo{repo} {
this->event=event;
}

void AddAction::Undofunction() {
this->repo->deleteRepo(this->event.getTitle());
}

void AddAction::Redofunction() {
this->repo->addRepo(event);
}

DeleteAction::DeleteAction(FileAdminRepo *repo, Event event): repo{repo} {
this->event=event;

}

void DeleteAction::Undofunction() {
this->repo->addRepo(event);
}

void DeleteAction::Redofunction() {
    this->repo->deleteRepo(event.getTitle());

}

UpdateAction::UpdateAction(FileAdminRepo *repo, Event event, Event newevent) : repo{repo}{
this->event=event;
this->newevent=newevent;
}

void UpdateAction::Redofunction() {
this->repo->updateRepo(event.getTitle(), newevent);
}

void UpdateAction::Undofunction() {
this->repo->updateRepo(event.getTitle(), event);
}



RemoveUserAction::RemoveUserAction(FileUserRepo *repo_user, Event event):repo_user{repo_user} {
this->event=event;

}

void RemoveUserAction::Undofunction() {
this->repo_user->addEventUser(event);
}

void RemoveUserAction::Redofunction() {
this->repo_user->removeEventUser(event.getTitle());
}



AddUserAction::AddUserAction(FileUserRepo *repo, Event event):repo_user{repo} {
this->event=event;
}
void AddUserAction::Undofunction() {
    this->repo_user->removeEventUser(event.getTitle());
}
void AddUserAction::Redofunction() {
this->repo_user->addEventUser(event);
}
