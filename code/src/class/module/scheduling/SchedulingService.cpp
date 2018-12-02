#ifndef _SCHEDULLING_SERVICE_CPP_
#define _SCHEDULLING_SERVICE_CPP_

#include <vector>
#include "../../../../header/module/scheduling/SchedulingModel.h"
#include "../../../../header/module/scheduling/SchedulingService.h"
#include "../../../../header/common/FindResult.h"

bool SchedulingService::validateStoredRegister(const vector<string> lineProps) const {

    // if (lineProps.size() != 2) return false;
    //
    // try { stoi(lineProps[0]); }
    // catch (exception err) { return false; }

    return true;
};

void SchedulingService::showRegisterData(const shared_ptr<SchedulingModel> scheduling) const {
    // cout << "|\t" << scheduling->getCode() << "\t| "
    //      << scheduling->getName() << "\t|"
    //      << endl;
};

void SchedulingService::showDataTableHeader(void) const {
    cout << "|\tCodigo\t|"
         << "\tNome\t\t|"
         << endl;
};

void SchedulingService::showRegistersListData(const vector<FindResult<SchedulingModel>> schedulingList) const {

    if (!schedulingList.size()) {
        cout << "Nenhum registro encontrado..." << endl;
        return;
    }

    this->showDataTableHeader();

    for (uint i = 0; i < schedulingList.size(); i++) {
        this->showRegisterData(schedulingList[i].foundRegister);
    }

    cout << endl;
};

shared_ptr<SchedulingModel> SchedulingService::getModelFromStorageLine(const vector<string> lineProps) {

    if (!this->validateStoredRegister(lineProps))
        throw invalid_argument("Tentativa de gerar Agendamento a partir de dados invalidos");

    // auto scheduling = make_shared<SchedulingModel>();
    // scheduling->setCode(stoi(lineProps[0]));
    // scheduling->setName(lineProps[1]);
    // return scheduling;
    return nullptr;
};

#endif
