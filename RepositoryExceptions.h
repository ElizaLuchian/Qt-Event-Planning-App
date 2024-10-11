//
// Created by 40745 on 29/04/2024.
//

#ifndef OOP_A6_7_ELIZALUCHIAN_REPOSITORYEXCEPTIONS_H
#define OOP_A6_7_ELIZALUCHIAN_REPOSITORYEXCEPTIONS_H


#include <string>

class RepositoryExceptions: public std::exception{
protected:
    std::string message;
public:
    RepositoryExceptions();
    RepositoryExceptions(const std::string& message);
    const char * what() const noexcept override;
};

class  NotFound: public RepositoryExceptions{
public:
    const char * what() const noexcept override;
};
class AlreadyExists: public RepositoryExceptions{
public:

    const char * what() const noexcept override;
};


#endif //OOP_A6_7_ELIZALUCHIAN_REPOSITORYEXCEPTIONS_H