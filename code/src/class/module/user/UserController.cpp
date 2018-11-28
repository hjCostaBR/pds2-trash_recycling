#ifndef _USER_CONTROLLER_CPP_
#define _USER_CONTROLLER_CPP_

#include <memory>
#include <functional>
#include "../../../../header/module/user/UserController.h"
#include "../../../../header/module/user/UserModel.h"
#include "../../../../header/common/enums.h"

using namespace std;

PersonTypeEnum UserController::getNewUserTypeFromStdIo(void) const {

    bool reapeat = false;
    bool tried = false;
    string readInput;
    int number;

    do {

        // Notifica tentativa invalida (se necessario)
        if (tried) cout << "'" << readInput <<"' nao e um tipo valido!" << endl << endl;
        tried = true;

        // Captura entrada
        cout << "Informe o tipo do novo usaurio (pf/pj): ";
        cin >> readInput;
        reapeat = (readInput != "pf" && readInput != "pj");

    } while (reapeat);

    // Tudo OK
    return (readInput == "pf") ? PersonTypeEnum ::PF : PersonTypeEnum ::PJ;
};

string UserController::getCpfOrCnpjFromStdIo(PersonTypeEnum personType) const {

    string docType = (personType == PersonTypeEnum::PF) ? "CPF" : "CNPJ";

    string readInput = "";
    string cpfCnpj = "";
    bool tried = false;
    bool reapeat = false;

    do {

        // Notifica tentativa invalida (se necessario)
        if (tried) cout << docType << " invalido!" << endl << endl;
        tried = true;
        reapeat = false;

        // Captura entrada
        cout << "Informe " << docType << " do usuario (apenas numeros): ";
        cin >> readInput;

        // Verifica se usuario solicitou 'sair'
        if (readInput == "0") break;

        // Valida entrada (comprimento)
        if ((personType == PersonTypeEnum::PF && readInput.length() != 11)
            || (personType == PersonTypeEnum::PJ && readInput.length() != 14)
        ) {
            reapeat = true;
            continue;
        }

        // Valida entrada (conteudo)
        for (uint i = 0; i < readInput.length(); i++) {
            if (isdigit(readInput[i])) continue;
            reapeat = true;
            break;
        }

    } while (reapeat);

    // Tudo OK
    if (readInput != "0") cpfCnpj = readInput;
    return cpfCnpj;
};

UserModel UserController::getDataToCreateUser(void) const {

    UserModel user = UserModel();

    PersonTypeEnum personType = this->getNewUserTypeFromStdIo();

    int code = this->getNumberFromStdIO("Informe um Codigo para o usuario", "Codigo invalido");
    string cpfCnpj = this->getCpfOrCnpjFromStdIo(personType);

    // int type;
    // string name;
    // vector<RejectTypeModel> rejectTypesOfInterest;

    return user;
}

void UserController::initialize(void) {
    throw bad_function_call();
};

void UserController::initialize(int action) {

    switch (action) {
        case ControllerActionEnum::CREATE:
            this->getDataToCreateUser();
            break;

        case ControllerActionEnum::DEFAULT:
        default:
            this->initialize();
            break;
    }
};

#endif