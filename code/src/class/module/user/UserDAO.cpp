#ifndef _USER_DAO_CPP_
#define _USER_DAO_CPP_

#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../../../../header/common/FindResult.h"
#include "../../../../header/common/class/DAO.h"
#include "../../../../header/module/user/UserDAO.h"
#include "../../../../header/module/user/UserService.h"

using namespace std;

const string UserDAO::STORAGE_FILE = "user.txt";

string UserDAO::getStorageFileName(void) {
    return UserDAO::STORAGE_FILE;
};

FindResult<UserModel> UserDAO::findOne(const int code, const string cpfCnpj) {

    // Abre arquivo
    this->openStorageForReading();

    // Inicializa dados de retorno
    FindResult<UserModel> result;
    result.foundRegister = nullptr;
    result.line = 0;

    // Efetua busca
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
        if (code == stoi(lineProps[0]) || cpfCnpj == lineProps[1]) {
            result.foundRegister = this->getModelFromStorageLine(lineProps);
            result.line = lineCount;
            return result;
        }
    }

    return result;
};

FindResult<UserModel> UserDAO::findOne(const int code) {
    return this->findOne(code, "");
};

FindResult<UserModel> UserDAO::findOne(const string cpfCnpj) {
    return this->findOne(0, cpfCnpj);
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

    auto existingUserSearch = this->findOne(user->getCode(), user->getCpfCnpj());
    auto existingUser = existingUserSearch.foundRegister;

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

shared_ptr<UserModel> UserDAO::update(const shared_ptr<UserModel> user) {

    // Validacao
    bool invalidArgument = (user == nullptr);
    shared_ptr<UserModel> existingUser;

    if (!invalidArgument) {
        auto existingUserSearch = this->findOne(user->getCode());
        existingUser = existingUserSearch.foundRegister;
        invalidArgument = (existingUser == nullptr);
    }

    if (invalidArgument) throw invalid_argument("Usuario nao existe");

    if (existingUser->getCode() != user->getCode() || existingUser->getCpfCnpj() != user->getCpfCnpj())
        throw domain_error("Dados repetidos");

    // Remove linha atual do usuario
    // @todo...

    // Add nova linha para o usuario
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