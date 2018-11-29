#ifndef _USER_DAO_CPP_
#define _USER_DAO_CPP_

#include <memory>
#include <iostream>
#include <fstream>
#include "../../../../header/module/user/UserDAO.h"

using namespace std;

const string UserDAO::STORAGE_FILE = "user.txt";
const string STORAGE_FILE_REL_PATH = "../../../../../storage/";

void UserDAO::openStorageFile(void) {
    if (this->storageFile.is_open()) return;
    this->storageFile.open(STORAGE_FILE_REL_PATH + UserDAO::STORAGE_FILE);
}

shared_ptr<UserModel> UserDAO::insert(const shared_ptr<UserModel> model) {
    this->openStorageFile();
    this->storageFile << "1, 2, 3 testando..." << endl;
    return make_shared<UserModel>();
}

#endif