#ifndef _MEETINGPOINT_DAO_CPP_
#define _MEETINGPOINT_DAO_CPP_

#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../../../../header/common/FindResult.h"
#include "../../../../header/common/class/DAO.h"
#include "../../../../header/module/meeting-point/MeetingPointDAO.h"
#include "../../../../header/module/meeting-point/MeetingPointService.h"
#include "../../../../header/module/meeting-point/MeetingPointModel.h"

using namespace std;

const string MeetingPointDAO::STORAGE_FILE = "meeting-point.txt";

void MeetingPointDAO::writeRegisterIntoStorage(shared_ptr<MeetingPointModel> rejectType) {

    this->openStorageForWriting();

    this->writingStream
            << rejectType->getCode() << ";"
            << rejectType->getName() << ";"
            << endl;
}

string MeetingPointDAO::getStorageFileName(void) {
    return MeetingPointDAO::STORAGE_FILE;
};

shared_ptr<MeetingPointModel> MeetingPointDAO::insert(const shared_ptr<MeetingPointModel> rejectType) {
    if (rejectType == nullptr) throw invalid_argument("Dados nao informados");
    this->writeRegisterIntoStorage(rejectType);
    return rejectType;
};

shared_ptr<MeetingPointModel> MeetingPointDAO::update(const shared_ptr<MeetingPointModel> rejectType) {

    // // Validacao
    // if (rejectType == nullptr) throw invalid_argument("Dados insuficientes");
    // auto existingRejTypeSearch = this->findOne(rejectType->getCode());
    // if (existingRejTypeSearch.foundRegister == nullptr) throw invalid_argument("Tipo de Residuo nao existe");
    //
    // // Remove linha defasada, insere nova & retorna objeto valido
    // this->deleteOne(existingRejTypeSearch.line);
    // this->writeRegisterIntoStorage(rejectType);
    // return rejectType;
};

FindResult<MeetingPointModel> MeetingPointDAO::findOne(const int code) {

    // // Abre arquivo
    // this->openStorageForReading();
    //
    // // Inicializa dados de retorno
    // FindResult<MeetingPointModel> result;
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
    //         cout << endl << "** WARNING: Cadastro de Tipo de Residuo invalido (linha: " << lineCount << ") **" << endl << endl;
    //         continue;
    //     }
    //
    //     // Verifica se usuario pesquisado foi encontrado
    //     if (code == stoi(lineProps[0])) {
    //         result.foundRegister = this->service->getModelFromStorageLine(lineProps);
    //         result.line = lineCount;
    //         return result;
    //     }
    // }
    //
    // return result;
};

vector<FindResult<MeetingPointModel>> MeetingPointDAO::findAll(void) {

    // this->openStorageForReading();
    //
    // vector<FindResult<MeetingPointModel>> returnList;
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
    //         cout << endl << "** WARNING: Cadastro de Tipo de Residuo invalido (linha: " << lineCount << ") **" << endl << endl;
    //         continue;
    //     }
    //
    //     // Add item na lista de retorno
    //     FindResult<MeetingPointModel> result;
    //     result.foundRegister = this->service->getModelFromStorageLine(lineProps);
    //     result.line = lineCount;
    //     returnList.push_back(result);
    // }
    //
    // return returnList;
};

#endif