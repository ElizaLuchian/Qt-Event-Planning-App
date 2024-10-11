//
// Created by 40745 on 29/04/2024.
//

#ifndef OOP_A6_7_ELIZALUCHIAN_HTMLUSERFILE_H
#define OOP_A6_7_ELIZALUCHIAN_HTMLUSERFILE_H



#include "FileUserRepo.h"

class HtmlUserFile: public FileUserRepo {
public:
    HtmlUserFile(std::string filename): FileUserRepo(filename){};
    void writeToFile() override;
    std::string generateCommand() override;
};


#endif //OOP_A6_7_ELIZALUCHIAN_HTMLUSERFILE_H
