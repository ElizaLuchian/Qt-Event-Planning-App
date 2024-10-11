//
// Created by 40745 on 29/04/2024.
//

#ifndef OOP_A6_7_ELIZALUCHIAN_HTMLADMINFILE_H
#define OOP_A6_7_ELIZALUCHIAN_HTMLADMINFILE_H


#include "FileAdminRepo.h"

class HtmlAdminFile: public FileAdminRepo{
public:
    HtmlAdminFile(std::string filename): FileAdminRepo(filename){};
    void writeToFile() override;
    std::string generateCommand() override;

};


#endif //OOP_A6_7_ELIZALUCHIAN_HTMLADMINFILE_H
