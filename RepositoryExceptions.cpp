#include "RepositoryExceptions.h"

//
// Created by 40745 on 29/04/2024.
//
RepositoryExceptions::RepositoryExceptions() : std::exception(), message(""){

}

RepositoryExceptions::RepositoryExceptions(const std::string& message) : std::exception(), message(message) {
}

const char *RepositoryExceptions::what() const noexcept {
    return this->message.c_str();
}


const char *AlreadyExists::what() const noexcept  {
    return "This title already exists";
}


const char *NotFound::what() const noexcept {
    return "This title doesn't exist";
}
