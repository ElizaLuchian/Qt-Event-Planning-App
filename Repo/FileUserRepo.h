//
// Created by 40745 on 06/04/2024.
//

#ifndef OOP_A4_5_ELIZALUCHIAN_USERREPO_H
#define OOP_A4_5_ELIZALUCHIAN_USERREPO_H




#include "Domain/Event.h"
#include <vector>
using namespace std;
class FileUserRepo {
protected:
    vector<Event> eventlist;
    string fileName;


public:
    FileUserRepo();
    FileUserRepo(string  fileName);



  vector<Event> getEventList()const;
    void addEventUser( Event event);
    void removeEventUser(std::string title);



    void readFromFile();
    virtual void writeToFile();
    virtual std::string generateCommand();


};


#endif //OOP_A4_5_ELIZALUCHIAN_USERREPO_H
