#ifndef _REJECTTYPE_DAO_CPP_
#define _REJECTTYPE_DAO_CPP_

#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../../../../header/common/FindResult.h"
#include "../../../../header/common/class/DAO.h"
#include "../../../../header/module/reject-type/RejectTypeDAO.h"
#include "../../../../header/module/reject-type/RejectTypeService.h"
#include "../../../../header/module/reject-type/RejectTypeModel.h"

using namespace std;

const string RejectTypeDAO::STORAGE_FILE = "reject-type.txt";

void RejectTypeDAO::writeRegisterIntoStorage(shared_ptr<RejectTypeModel> user) {

    /*this->openStorageForWriting();

    this->writingStream
            << user->getCode() << ";"
            << user->getCpfCnpj() << ";"
            << user->getType() << ";"
            << user->getName() << ";"
            // << user->getRejectTypesOfInterest() << ";"
            << endl;*/
}

string RejectTypeDAO::getStorageFileName(void) {
    return RejectTypeDAO::STORAGE_FILE;
};

shared_ptr<RejectTypeModel> RejectTypeDAO::getModelFromStorageLine(const vector<string> lineProps) {

    // if (!this->service->validateStoredRegister(lineProps))
    //     throw invalid_argument("Tentativa de gerar usuario a partir de dados invalidos");
    //
    // auto user = make_shared<RejectTypeModel>();
    // user->setCode(stoi(lineProps[0]));
    // user->setCpfCnpj(lineProps[1]);
    // user->setType((UserTypeEnum)stoi(lineProps[2]));
    // user->setName(lineProps[3]);
    // return user;

    return nullptr;
};

shared_ptr<RejectTypeModel> RejectTypeDAO::insert(const shared_ptr<RejectTypeModel> user) {

    // Validacao
    // if (user == nullptr) throw invalid_argument("Falha ao tentar inserir usuario cujo os dados nao foram informados");
    //
    // auto existingUserSearch = this->findOne(user->getCode(), user->getCpfCnpj());
    // auto existingUser = existingUserSearch.foundRegister;
    //
    // if (existingUser != nullptr) throw domain_error("Tentativa de inserir usuario que ja existe");
    //
    // // Add usuario
    // this->writeRegisterIntoStorage(user);
    //
    // // Tudo OK
    // return user;
    return nullptr;
};

shared_ptr<RejectTypeModel> RejectTypeDAO::update(const shared_ptr<RejectTypeModel> user) {

    // if (user == nullptr) throw invalid_argument("Dados insuficientes");
    //
    // // Verifica SE usuario existe
    // auto existingUserSearch = this->findOne(user->getCode());
    // if (existingUserSearch.foundRegister == nullptr) throw invalid_argument("Usuario nao existe");
    //
    // // Verifica SE cpf/cnpj esta disponivel
    // auto docValidationSearch = this->findOne(user->getCpfCnpj());
    // auto docValidationFoundUser = existingUserSearch.foundRegister;
    //
    // if (docValidationFoundUser != nullptr && docValidationFoundUser->getCode() != user->getCode())
    //     throw domain_error("Dados repetidos");
    //
    // // Remove linha atual do usuario
    // this->deleteOne(existingUserSearch.line);
    //
    // // Add nova linha para usuario
    // this->writeRegisterIntoStorage(user);
    //
    // // Tudo OK
    // return user;
    return nullptr;
};

FindResult<RejectTypeModel> RejectTypeDAO::findOne(const int code) {
    // return this->findOne(code, "");
    FindResult<RejectTypeModel> foo;
    return foo;
};

#endif