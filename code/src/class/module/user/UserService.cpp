#ifndef _USER_SERVICE_CPP_
#define _USER_SERVICE_CPP_

#include <exception>
#include <stdexcept>
#include "../../../../header/module/user/UserService.h"
#include "../../../../header/common/enums.h"

bool UserService::validateStoredRegister(const vector<string> lineProps) const {

    if (lineProps.size() < 4)
        return false;

    // Valida codigo
    try { stoi(lineProps[0]); }
    catch (exception err) { return false; }

    // Valida tipo
    try { !this->validateUserType(stoi(lineProps[0])); }
    catch (exception err) { return false; }

    // Valida cpf/cnpj
    try { this->getUserPersonType(string(lineProps[1])); }
    catch (exception err) { return false; }

    return true;
};

void UserService::showRegisterData(const shared_ptr<UserModel> user) const {

    cout << "|\t" << user->getCode()
         << "\t|\t" << user->getCpfCnpj()
         << "\t|\t" << this->getUserTypeLabel((UserTypeEnum)user->getType());

    if ((UserTypeEnum)user->getType() == UserTypeEnum::DONATOR) cout << "\t";

    cout << "\t|\t" << user->getName()
         << "\t|" << endl;
};

PersonTypeEnum UserService::getUserPersonType(const string cpfCnpj) const {
    if (cpfCnpj.size() == 11) return PersonTypeEnum::PF;
    if (cpfCnpj.size() == 14) return PersonTypeEnum::PJ;
    throw invalid_argument("CPF/CNPJ invalido");
}

bool UserService::validateUserType(const int type) const {
    try { this->getUserTypeLabel((UserTypeEnum)type); }
    catch (invalid_argument err) { return false; }
    return true;
}

string UserService::getUserTypeLabel(const UserTypeEnum typeCode) const {

    switch (typeCode) {
        case UserTypeEnum::ADMIN:
            return "Administrador";

        case UserTypeEnum::DONATOR:
            return "Doador";

        case UserTypeEnum::RECEIVER:
            return "Receptor";
    }

    throw invalid_argument("Tipo de usuario invalido");
};

#endif