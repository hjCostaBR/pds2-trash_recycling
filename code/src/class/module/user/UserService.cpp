#ifndef _USER_SERVICE_CPP_
#define _USER_SERVICE_CPP_

#include <exception>
#include <stdexcept>
#include "../../../../header/module/user/UserService.h"
#include "../../../../header/common/enums.h"

PersonTypeEnum UserService::getUserPersonType(const string cpfCnpj) const {
    if (cpfCnpj.size() == 11) return PersonTypeEnum::PF;
    if (cpfCnpj.size() == 14) return PersonTypeEnum::PJ;
    throw invalid_argument("CPF/CNPJ invalido");
}

bool UserService::validateUserType(const int type) const {
    return (type == UserTypeEnum::ADMIN || type == UserTypeEnum::RECEIVER || type == UserTypeEnum::DONATOR);
}

bool UserService::validateStoredRegister(const vector<string> lineProps) const {

    if (lineProps.size() < 4)
        return false;

    // Valida codigo
    try { int code = stoi(lineProps[0]); }
    catch (exception err) { return false; }

    // Valida tipo
    try { !this->validateUserType(stoi(lineProps[0])); }
    catch (exception err) { return false; }

    // Valida cpf/cnpj
    try { PersonTypeEnum aux = this->getUserPersonType(string(lineProps[1])); }
    catch (exception err) { return false; }

    return true;
};

#endif