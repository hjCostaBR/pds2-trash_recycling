#ifndef _USER_DAO_CPP_
#define _USER_DAO_CPP_

#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../../../../header/common/class/DAO.h"
#include "../../../../header/module/user/UserDAO.h"
#include "../../../../header/module/user/UserService.h"

using namespace std;

const string UserDAO::STORAGE_FILE = "user.txt";

string UserDAO::getStorageFileName(void) {
    return UserDAO::STORAGE_FILE;
};

shared_ptr<UserModel> UserDAO::getExistingUser(const int code, const string cpfCnpj) {

    this->openStorageForReading();

    int lineCount = 0;
    string fileLine;

    while (getline(this->readingStream, fileLine)) {

        lineCount++;

        // Extrai propriedades da linha
        stringstream ss(fileLine);
        string item;
        vector<string> lineProps;

        while (getline(ss, item, ';')) {
            lineProps.push_back(item);
        }

        // Valida valores extraidos
        if (!this->service->validateStoredRegister(lineProps)) {
            cout << endl << "** WARNING: Cadastro de usuário invalido (linha: " << lineCount << ") **" << endl << endl;
            continue;
        }

        // Verifica se usuario pesquisado foi encontrado
        if (code == stoi(lineProps[0]) || cpfCnpj == lineProps[1])
            return this->getModelFromStorageLine(lineProps);
    }

    return nullptr;
};

shared_ptr<UserModel> UserDAO::getModelFromStorageLine(const vector<string> lineProps) {

    if (!this->service->validateStoredRegister(lineProps))
        throw invalid_argument("Tentativa de gerar usuario a partir de dados invalidos");

    auto user = make_shared<UserModel>();
    user->setCode(stoi(lineProps[0]));
    user->setCpfCnpj(lineProps[1]);
    user->setType((UserTypeEnum)stoi(lineProps[2]));
    user->setName(lineProps[3]);
    return user;
};

shared_ptr<UserModel> UserDAO::insert(const shared_ptr<UserModel> user) {

    // Validacao
    if (user == nullptr) throw invalid_argument("Falha ao tentar inserir usuario cujo os dados nao foram informados");
    auto existingUser = this->getExistingUser(user->getCode(), user->getCpfCnpj());
    if (existingUser != nullptr) throw domain_error("Tentativa de inserir usuario que ja existe");

    // Add usuario
    this->openStorageForWriting();

    this->writingStream
        << user->getCode() << ";"
        << user->getCpfCnpj() << ";"
        << user->getType() << ";"
        << user->getName() << ";"
        // << user->getRejectTypesOfInterest() << ";"
        << endl;

    // Tudo OK
    return user;
};

shared_ptr<UserModel> UserDAO::insert(const int code, const shared_ptr<UserModel> user) {

    // Validacao
    if (user == nullptr) throw invalid_argument("Falha ao tentar atualizar usuario cujo os dados nao foram informados");
    auto existingUser = this->getExistingUser(user->getCode(), user->getCpfCnpj());
    if (existingUser == nullptr) throw domain_error("Tentativa de atualizar usuario que NAO existe");

    // Add usuario
    this->openStorageForWriting();

    this->writingStream
        << user->getCode() << ";"
        << user->getCpfCnpj() << ";"
        << user->getType() << ";"
        << user->getName() << ";"
        // << user->getRejectTypesOfInterest() << ";"
        << endl;

    // Tudo OK
    return user;
};

#endif