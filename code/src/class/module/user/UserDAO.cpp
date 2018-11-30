#ifndef _USER_DAO_CPP_
#define _USER_DAO_CPP_

#include <memory>
#include <iostream>
#include <fstream>
#include "../../../../header/module/user/UserDAO.h"
#include "../../../../header/common/DAO.h"

using namespace std;

const string UserDAO::STORAGE_FILE = "user.txt";

void UserDAO::openStorageFile(void) {
    if (this->storageFile.is_open()) return;
    this->storageFile.open(DAO::STORAGE_DIR_PATH + UserDAO::STORAGE_FILE, ios::in);
}

shared_ptr<UserModel> UserDAO::insert(const shared_ptr<UserModel> user) {

    if (user == nullptr)
        throw invalid_argument("Falha ao tentar inserir usuario cujo os dados nao foram informados");

    // this->openStorageFile();

    ifstream fooo;
    fooo.open(DAO::STORAGE_DIR_PATH + UserDAO::STORAGE_FILE/*, ios::app | ios::in*/);

    // while (!this->storageFile.eof()) {
        string foo = "";
        fooo >> foo;
        cout << "FOO: " << foo << endl;
    // }

    /*this->storageFile
        << user->getCode() << ";"
        << user->getCpfCnpj() << ";"
        << user->getType() << ";"
        << user->getName() << ";"
        // << user->getRejectTypesOfInterest() << ";"
        << endl;*/

    return user;
}

#endif