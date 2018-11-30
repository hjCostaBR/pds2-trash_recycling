#ifndef _USER_DAO_CPP_
#define _USER_DAO_CPP_

#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../../../../header/module/user/UserDAO.h"
#include "../../../../header/common/DAO.h"

using namespace std;

const string UserDAO::STORAGE_FILE = "user.txt";

string UserDAO::getStorageFileName(void) {
    return UserDAO::STORAGE_FILE;
};

shared_ptr<UserModel> UserDAO::insert(const shared_ptr<UserModel> user) {

    if (user == nullptr)
        throw invalid_argument("Falha ao tentar inserir usuario cujo os dados nao foram informados");

    // Valida se usuario eh repetido
    this->openStorageForReading();

    int i = 0;
    string fileLine;

    while (getline(this->readingStream, fileLine)) {
        i++;
        cout << "pipa " << i << ": " << fileLine << endl;

        istringstream iss(fileLine);

        int code;
        iss >> code;

        string cpfCnpj;
        iss >> cpfCnpj;

    }

    /*this->writingStream
        << user->getCode() << ";"
        << user->getCpfCnpj() << ";"
        << user->getType() << ";"
        << user->getName() << ";"
        // << user->getRejectTypesOfInterest() << ";"
        << endl;*/

    return user;
}

#endif