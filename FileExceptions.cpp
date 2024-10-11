#include "FileExceptions.h"

//
// Created by 40745 on 29/04/2024.
//
FileExceptions::FileExceptions(std::string message) {
    this->message=message;
}

const char *FileExceptions::what() const noexcept {
    return "File could not be opened";
}

FileExceptions::FileExceptions() {

}
