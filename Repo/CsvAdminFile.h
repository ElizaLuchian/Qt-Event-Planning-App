//
// Created by 40745 on 29/04/2024.
//

#ifndef OOP_A6_7_ELIZALUCHIAN_CSVADMINFILE_H
#define OOP_A6_7_ELIZALUCHIAN_CSVADMINFILE_H


#include "FileAdminRepo.h"

class CsvAdminFile : public FileAdminRepo{

public:
    CsvAdminFile(const std:: string &filename);
    void writeToFile() override;
    std::string generateCommand() override;
};


#endif //OOP_A6_7_ELIZALUCHIAN_CSVADMINFILE_H
