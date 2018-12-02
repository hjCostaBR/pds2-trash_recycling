#ifndef _REJECTTYPE_SERVICE_CPP_
#define _REJECTTYPE_SERVICE_CPP_

#include <vector>
#include "../../../../header/module/reject-type/RejectTypeService.h"
#include "../../../../header/common/FindResult.h"

bool RejectTypeService::validateStoredRegister(const vector<string> lineProps) const {

    if (lineProps.size() != 3) return false;

    // Valida codigo
    try { stoi(lineProps[0]); }
    catch (exception err) { return false; }

    return true;
};

void RejectTypeService::showRegisterData(const shared_ptr<RejectTypeModel> rejectType) const {
    cout << "|\t" << rejectType->getCode() << "\t"
         << "| " << rejectType->getName() << "\t";

    if (rejectType->getName().size() < 6) cout << "\t";

    cout << "| " << rejectType->getStorageSpecification()
         << endl;
};

void RejectTypeService::showDataTableHeader(void) const {
    cout << "| Codigo\t|"
         << "\tNome\t|"
         << "\tInstrucao de armazenamento\t\t\t\t|"
         << endl;
};

void RejectTypeService::showRegistersListData(const vector<FindResult<RejectTypeModel>> rejTypesList) const {

    if (!rejTypesList.size()) {
        cout << "Nenhum registro encontrado..." << endl;
        return;
    }

    this->showDataTableHeader();

    for (uint i = 0; i < rejTypesList.size(); i++) {
        this->showRegisterData(rejTypesList[i].foundRegister);
    }

    cout << endl;
};

shared_ptr<RejectTypeModel> RejectTypeService::getModelFromStorageLine(const vector<string> lineProps) {

    if (!this->validateStoredRegister(lineProps))
        throw invalid_argument("Tentativa de gerar Tipo de Residuo a partir de dados invalidos");

    auto rejType = make_shared<RejectTypeModel>();
    rejType->setCode(stoi(lineProps[0]));
    rejType->setName(lineProps[1]);
    rejType->setStorageSpecification(lineProps[2]);
    return rejType;
};

#endif