//
// Created by 40745 on 28/04/2024.
//

#include <exception>
#include <string>
#include <utility>

#ifndef OOP_A6_7_ELIZALUCHIAN_VALIDATOREXCEPTIONS_H
#define OOP_A6_7_ELIZALUCHIAN_VALIDATOREXCEPTIONS_H



class ValidationsExceptions: public std::exception
{

private:
    std::string message;
public:
    ValidationsExceptions(std::string message);
    const char * what() const noexcept override;

};

ValidationsExceptions::ValidationsExceptions(std::string message) {
this->message=std::move(message);
}

const char *ValidationsExceptions::what() const noexcept {
    return this->message.c_str();
}

#endif //OOP_A6_7_ELIZALUCHIAN_VALIDATOREXCEPTIONS_H