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

void RejectTypeDAO::writeRegisterIntoStorage(shared_ptr<RejectTypeModel> rejectType) {

    this->openStorageForWriting();

    this->writingStream
            << rejectType->getCode() << ";"
            << rejectType->getName() << ";"
            << rejectType->getStorageSpecification() << ";"
            << endl;
}

string RejectTypeDAO::getStorageFileName(void) {
    return RejectTypeDAO::STORAGE_FILE;
};

shared_ptr<RejectTypeModel> RejectTypeDAO::insert(const shared_ptr<RejectTypeModel> rejectType) {

    // Validacao
    if (rejectType == nullptr) throw invalid_argument("Dados nao informados");

    auto existingRejTypeSearch = this->findOne(rejectType->getCode());
    auto existingRejType = existingRejTypeSearch.foundRegister;

    if (existingRejType != nullptr) throw domain_error("Tipo de Residuo ja existe");

    // Add
    this->writeRegisterIntoStorage(rejectType);

    // Tudo OK
    return rejectType;
};

shared_ptr<RejectTypeModel> RejectTypeDAO::update(const shared_ptr<RejectTypeModel> rejectType) {

    // Validacao
    if (rejectType == nullptr) throw invalid_argument("Dados insuficientes");
    auto existingRejTypeSearch = this->findOne(rejectType->getCode());
    if (existingRejTypeSearch.foundRegister == nullptr) throw invalid_argument("Tipo de Residuo nao existe");

    // Remove linha defasada, insere nova & retorna objeto valido
    this->deleteOne(existingRejTypeSearch.line);
    this->writeRegisterIntoStorage(rejectType);
    return rejectType;
};

FindResult<RejectTypeModel> RejectTypeDAO::findOne(const int code) {

    // Abre arquivo
    this->openStorageForReading();

    // Inicializa dados de retorno
    FindResult<RejectTypeModel> result;
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
            cout << endl << "** WARNING: Cadastro de Tipo de Residuo invalido (linha: " << lineCount << ") **" << endl << endl;
            continue;
        }

        // Verifica se usuario pesquisado foi encontrado
        if (code == stoi(lineProps[0])) {
            result.foundRegister = this->service->getModelFromStorageLine(lineProps);
            result.line = lineCount;
            return result;
        }
    }

    return result;
};

vector<FindResult<RejectTypeModel>> RejectTypeDAO::findAll(void) {

    this->openStorageForReading();

    vector<FindResult<RejectTypeModel>> returnList;
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
            cout << endl << "** WARNING: Cadastro de Tipo de Residuo invalido (linha: " << lineCount << ") **" << endl << endl;
            continue;
        }

        // Add item na lista de retorno
        FindResult<RejectTypeModel> result;
        result.foundRegister = this->service->getModelFromStorageLine(lineProps);
        result.line = lineCount;
        returnList.push_back(result);
    }

    return returnList;
};

#endif