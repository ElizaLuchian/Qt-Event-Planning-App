//
// Created by 40745 on 29/04/2024.
//

#ifndef OOP_A6_7_ELIZALUCHIAN_FILEEXCEPTIONS_H
#define OOP_A6_7_ELIZALUCHIAN_FILEEXCEPTIONS_H


#include <exception>
#include <string>


class FileExceptions: public std::exception
{

private:
    std::string message;
public:
    FileExceptions();
    FileExceptions(std::string message);
    const char * what() const noexcept override;

};


#endif //OOP_A6_7_ELIZALUCHIAN_FILEEXCEPTIONS_H
