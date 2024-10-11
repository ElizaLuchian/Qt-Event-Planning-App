//
// Created by 40745 on 14/04/2024.
//

#include <sstream>
#include <string>
#include "Domain/Helpers.h"

std::vector<std::string> Helpers::tokenize(const std::string &str, char delimitator) {
    std::vector<std::string> info;
    std::stringstream stringStream(str);
    std::string token;
    while(getline(stringStream, token, delimitator))
        info.push_back(token);
    return info;

}