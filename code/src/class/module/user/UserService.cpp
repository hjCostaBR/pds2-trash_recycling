#ifndef _USER_SERVICE_CPP_
#define _USER_SERVICE_CPP_

#include <exception>
#include <stdexcept>
#include <vector>
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

    // Exibe dados gerais
    cout << "|\t" << user->getCode()
         << "\t|\t" << user->getCpfCnpj()
         << "\t|\t" << this->getUserTypeLabel((UserTypeEnum)user->getType());

    if ((UserTypeEnum)user->getType() == UserTypeEnum::DONATOR) cout << "\t";

    cout << "\t|\t" << user->getName()
         << "\t|" << endl;

    // Exibe lista de residuos de interesse
    if (!user->getRejectTypesOfInterestCodes().size()) {
        cout << "Nenhum Tipo de Residuo de interesse selecionado..." << endl;
        return;
    }

    cout << "Residuos de interesse: ";

    for (uint i = 0; i < user->getRejectTypesOfInterestCodes().size(); i++) {

        const int rejTypeCode = user->getRejectTypesOfInterestCodes()[i];
        const auto rejTypeSearch = this->rejTypeDAO->findOne(rejTypeCode);

        if (rejTypeSearch.foundRegister == nullptr) {
            cout << endl << "** WARNING: Cadastro de usuário invalido (tipo de residuo nao existe: " << rejTypeCode << ") **" << endl << endl;
            continue;
        }

        if (i > 0) cout << ", ";
        cout << rejTypeSearch.foundRegister->getName();
    }

    cout << endl;
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

shared_ptr<UserModel> UserService::getModelFromStorageLine(const vector<string> lineProps) {

    if (!this->validateStoredRegister(lineProps))
        throw invalid_argument("Tentativa de gerar usuario a partir de dados invalidos");

    auto user = make_shared<UserModel>();
    user->setCode(stoi(lineProps[0]));
    user->setCpfCnpj(lineProps[1]);
    user->setType((UserTypeEnum)stoi(lineProps[2]));
    user->setName(lineProps[3]);
    return user;
};

#endif