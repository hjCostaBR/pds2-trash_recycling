#ifndef _REJECTTYPE_SERVICE_CPP_
#define _REJECTTYPE_SERVICE_CPP_

#include "../../../../header/module/reject-type/RejectTypeService.h"

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

    // cout << "|\t" << user->getCode()
    //      << "\t|\t" << user->getCpfCnpj()
    //      << "\t|\t" << this->getUserTypeLabel((UserTypeEnum)user->getType());
    //
    // if ((UserTypeEnum)user->getType() == UserTypeEnum::DONATOR) cout << "\t";
    //
    // cout << "\t|\t" << user->getName()
    //      << "\t|" << endl;
};

#endif