#ifndef _SCHEDULLING_SERVICE_CPP_
#define _SCHEDULLING_SERVICE_CPP_

#include <vector>
#include "../../../../header/module/scheduling/SchedulingService.h"
#include "../../../../header/common/FindResult.h"

bool SchedullingService::validateStoredRegister(const vector<string> lineProps) const {

    // if (lineProps.size() != 2) return false;
    //
    // try { stoi(lineProps[0]); }
    // catch (exception err) { return false; }

    return true;
};

void SchedullingService::showRegisterData(const shared_ptr<SchedullingModel> schedulling) const {
    // cout << "|\t" << schedulling->getCode() << "\t| "
    //      << schedulling->getName() << "\t|"
    //      << endl;
};

void SchedullingService::showDataTableHeader(void) const {
    cout << "|\tCodigo\t|"
         << "\tNome\t\t|"
         << endl;
};

void SchedullingService::showRegistersListData(const vector<FindResult<SchedullingModel>> schedullingList) const {

    if (!schedullingList.size()) {
        cout << "Nenhum registro encontrado..." << endl;
        return;
    }

    this->showDataTableHeader();

    for (uint i = 0; i < schedullingList.size(); i++) {
        this->showRegisterData(schedullingList[i].foundRegister);
    }

    cout << endl;
};

shared_ptr<SchedullingModel> SchedullingService::getModelFromStorageLine(const vector<string> lineProps) {

    if (!this->validateStoredRegister(lineProps))
        throw invalid_argument("Tentativa de gerar Agendamento a partir de dados invalidos");

    // auto schedulling = make_shared<SchedullingModel>();
    // schedulling->setCode(stoi(lineProps[0]));
    // schedulling->setName(lineProps[1]);
    // return schedulling;
    return nullptr;
};

#endif
