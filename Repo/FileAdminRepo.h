//
// Created by 40745 on 24/03/2024.
//

#ifndef OOP_A4_5_ELIZALUCHIAN_ADMINREPO_H
#define OOP_A4_5_ELIZALUCHIAN_ADMINREPO_H
#include <vector>
#include "Domain/Event.h"

using namespace std;
class FileAdminRepo {
protected:
    vector<Event>events;
    string fileName;

public:

    FileAdminRepo();
    FileAdminRepo(string  fileName);
    int get_size_repo()const;
    void addRepo(const Event& event);
    void deleteRepo(const std::string& title);
    vector<Event> getAllElements()const;
    void updateRepo(const std::string& title, const Event& event);
    Event getElemwithTitle(const std::string & title)const;
    void readFromFile();
    virtual  void writeToFile();
    virtual std::string generateCommand();

   // void addAllElementsFromFile();

    //Event getEventAtIndex(int index)const;



};


#endif //OOP_A4_5_ELIZALUCHIAN_ADMINREPO_H
