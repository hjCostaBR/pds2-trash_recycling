#ifndef _SCHEDULING_DAO_CPP_
#define _SCHEDULING_DAO_CPP_

#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../../../../header/common/FindResult.h"
#include "../../../../header/common/class/DAO.h"
#include "../../../../header/module/scheduling/SchedulingDAO.h"
#include "../../../../header/module/scheduling/SchedulingService.h"
#include "../../../../header/module/scheduling/SchedulingModel.h"

using namespace std;

const string SchedulingDAO::STORAGE_FILE = "scheduling.txt";

void SchedulingDAO::writeRegisterIntoStorage(shared_ptr<SchedulingModel> scheduling) {

    const int doneFlagValue = scheduling->isDone() ? 1 : 0;
    this->openStorageForWriting();

    this->writingStream
        << scheduling->getDate() << ";"
        << scheduling->getMeetingPointCode() << ";"
        << scheduling->getDonatorCode() << ";"
        << scheduling->getReceiverCode() << ";";

    for (uint i = 0; i < scheduling->getRejectsToBeExchangedCodes().size(); i++) {
        if (i > 0) this->writingStream << ",";
        this->writingStream << scheduling->getRejectsToBeExchangedCodes()[i];
    }

    this->writingStream << ";"
        << doneFlagValue << ";"
        << endl;
}

string SchedulingDAO::getStorageFileName(void) {
    return SchedulingDAO::STORAGE_FILE;
};

shared_ptr<SchedulingModel> SchedulingDAO::insert(const shared_ptr<SchedulingModel> scheduling) {
    if (scheduling == nullptr) throw invalid_argument("Dados nao informados");
    this->writeRegisterIntoStorage(scheduling);
    return scheduling;
};

shared_ptr<SchedulingModel> SchedulingDAO::update(const shared_ptr<SchedulingModel> scheduling) {

    // // Validacao
    // if (scheduling == nullptr) throw invalid_argument("Dados insuficientes");
    // auto existingSchedulingSearch = this->findOne(scheduling->getCode());
    // if (existingSchedulingSearch.foundRegister == nullptr) throw invalid_argument("Agendamento nao existe");
    //
    // // Remove linha defasada, insere nova & retorna objeto valido
    // this->deleteOne(existingSchedulingSearch.line);
    // this->writeRegisterIntoStorage(scheduling);
    // return scheduling;
    return nullptr;
};

FindResult<SchedulingModel> SchedulingDAO::findOne(const int code) {

    // // Abre arquivo
    // this->openStorageForReading();
    //
    // // Inicializa dados de retorno
    // FindResult<SchedulingModel> result;
    // result.foundRegister = nullptr;
    // result.line = 0;
    //
    // // Efetua busca
    // int lineCount = 0;
    // string fileLine;
    //
    // while (getline(this->readingStream, fileLine)) {
    //
    //     lineCount++;
    //
    //     // Extrai propriedades da linha
    //     stringstream ss(fileLine);
    //     string item;
    //     vector<string> lineProps;
    //
    //     while (getline(ss, item, ';')) {
    //         lineProps.push_back(item);
    //     }
    //
    //     // Valida valores extraidos
    //     if (!this->service->validateStoredRegister(lineProps)) {
    //         cout << endl << "** WARNING: Cadastro de Ponto de Coleta invalido (linha: " << lineCount << ") **" << endl << endl;
    //         continue;
    //     }
    //
    //     // Verifica se registro pesquisado foi encontrado
    //     if (code == stoi(lineProps[0])) {
    //         result.foundRegister = this->service->getModelFromStorageLine(lineProps);
    //         result.line = lineCount;
    //         return result;
    //     }
    // }
    //
    // return result;
};

vector<FindResult<SchedulingModel>> SchedulingDAO::findAll(void) {

    // this->openStorageForReading();
    //
    // vector<FindResult<SchedulingModel>> returnList;
    // int lineCount = 0;
    // string fileLine;
    //
    // while (getline(this->readingStream, fileLine)) {
    //
    //     lineCount++;
    //
    //     // Extrai propriedades da linha
    //     stringstream ss(fileLine);
    //     string item;
    //     vector<string> lineProps;
    //
    //     while (getline(ss, item, ';')) {
    //         lineProps.push_back(item);
    //     }
    //
    //     // Valida valores extraidos
    //     if (!this->service->validateStoredRegister(lineProps)) {
    //         cout << endl << "** WARNING: Cadastro de Ponto de Coleta invalido (linha: " << lineCount << ") **" << endl << endl;
    //         continue;
    //     }
    //
    //     // Add item na lista de retorno
    //     FindResult<SchedulingModel> result;
    //     result.foundRegister = this->service->getModelFromStorageLine(lineProps);
    //     result.line = lineCount;
    //     returnList.push_back(result);
    // }
    //
    // return returnList;
};

#endif