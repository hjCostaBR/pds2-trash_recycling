#ifndef _MEETINGPOINT_SERVICE_CPP_
#define _MEETINGPOINT_SERVICE_CPP_

#include <vector>
#include "../../../../header/module/meeting-point/MeetingPointService.h"
#include "../../../../header/common/FindResult.h"

bool MeetingPointService::validateStoredRegister(const vector<string> lineProps) const {

    // if (lineProps.size() < 4)
    //     return false;
    //
    // // Valida codigo
    // try { stoi(lineProps[0]); }
    // catch (exception err) { return false; }
    //
    // // Valida tipo
    // try { !this->validateUserType(stoi(lineProps[0])); }
    // catch (exception err) { return false; }
    //
    // // Valida cpf/cnpj
    // try { this->getUserPersonType(string(lineProps[1])); }
    // catch (exception err) { return false; }

    return true;
};

void MeetingPointService::showRegisterData(const shared_ptr<MeetingPointModel> rejectType) const { };

void MeetingPointService::showDataTableHeader(void) const { };

void MeetingPointService::showRegistersListData(const vector<FindResult<MeetingPointModel>> rejTypesList) const {

    // this->showDataTableHeader();
    //
    // for (uint i = 0; i < rejTypesList.size(); i++) {
    //     this->showRegisterData(rejTypesList[i].foundRegister);
    // }
    //
    // cout << endl;
};

shared_ptr<MeetingPointModel> MeetingPointService::getModelFromStorageLine(const vector<string> lineProps) {

    // if (!this->validateStoredRegister(lineProps))
    //     throw invalid_argument("Tentativa de gerar Tipo de Residuo a partir de dados invalidos");
    //
    // auto rejType = make_shared<MeetingPointModel>();
    // rejType->setCode(stoi(lineProps[0]));
    // rejType->setName(lineProps[1]);
    // rejType->setStorageSpecification(lineProps[2]);
    // return rejType;
};

#endif