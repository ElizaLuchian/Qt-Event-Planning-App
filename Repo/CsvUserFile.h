//
// Created by 40745 on 29/04/2024.
//

#ifndef OOP_A6_7_ELIZALUCHIAN_CSVUSERFILE_H
#define OOP_A6_7_ELIZALUCHIAN_CSVUSERFILE_H



#include "FileUserRepo.h"

class CsvUserFile : public FileUserRepo{
public:
    CsvUserFile(const std:: string &filename);
    void writeToFile() override;
    std::string generateCommand() override;

};


#endif //OOP_A6_7_ELIZALUCHIAN_CSVUSERFILE_H
