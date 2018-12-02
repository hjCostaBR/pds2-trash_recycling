#ifndef _REJECTTYPE_SERVICE_CPP_
#define _REJECTTYPE_SERVICE_CPP_

#include "../../../../header/module/reject-type/RejectTypeService.h"
#include "../../../../header/common/FindResult.h"

bool RejectTypeService::validateStoredRegister(const vector<string> lineProps) const {

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

void RejectTypeService::showRegisterData(const shared_ptr<RejectTypeModel> rejectType) const {
    cout << "|\t" << rejectType->getCode() << "\t"
         << "| " << rejectType->getStorageSpecification();
};

void RejectTypeService::showRegistersListData(const vector<FindResult<RejectTypeModel>> rejTypesList) const {

    cout << "|\tResiduos:\t|" << endl;

    for (uint i = 0; i < rejTypesList.size(); i++) {
        this->showRegisterData(rejTypesList[i].foundRegister);
    }

}

#endif