#ifndef _USER_CONTROLLER_CPP_
#define _USER_CONTROLLER_CPP_

#include <memory>
#include <functional>
#include <map>
#include <algorithm>
#include "../../../../header/module/user/UserController.h"
#include "../../../../header/module/user/UserModel.h"
#include "../../../../header/common/enums.h"

using namespace std;

void UserController::setCurrentUserPersonType(void) {

    bool reapeat = false;
    bool tried = false;
    string readInput;
    int number;

    do {

        // Notifica tentativa invalida (se necessario)
        if (tried) cout << "'" << readInput <<"' nao e um tipo valido!" << endl << endl;
        tried = true;

        // Captura entrada
        cout << "Informe o tipo do novo usuario (pf/pj): ";
        cin >> readInput;
        reapeat = (readInput != "pf" && readInput != "pj" && readInput != "0");

    } while (reapeat);


    // Tudo OK
    if (readInput == "0") return;

    this->currentUserType = (readInput == "pf")
        ? make_shared<PersonTypeEnum>(PersonTypeEnum ::PF)
        : make_shared<PersonTypeEnum>(PersonTypeEnum ::PJ);
};

void UserController::setCurrentUserCpfOrCnpj(void) {

    string docType = (*this->currentUserType == PersonTypeEnum::PF) ? "CPF" : "CNPJ";

    string readInput = "";
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
        if ((*this->currentUserType == PersonTypeEnum::PF && readInput.length() != 11)
            || (*this->currentUserType == PersonTypeEnum::PJ && readInput.length() != 14)
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
    if (readInput != "0") this->currentUser->setCpfCnpj(readInput);
};

void UserController::setCurrentUserType(void) {

    string readInput = "";
    bool tried = false;
    bool reapeat = false;

    // Monta estrutura para exibir opcoes
    vector<UserTypeEnum> userTypesList;
    map<UserTypeEnum, int> typeCodeMap;
    map<UserTypeEnum, string> typeLabelMap;

    userTypesList.push_back(UserTypeEnum::RECEIVER);
    typeCodeMap[UserTypeEnum::RECEIVER] = 1;
    typeLabelMap[UserTypeEnum::RECEIVER] = "Receptor";

    userTypesList.push_back(UserTypeEnum::DONATOR);
    typeCodeMap[UserTypeEnum::DONATOR] = 2;
    typeLabelMap[UserTypeEnum::DONATOR] = "Doador";

    do {

        // Notifica tentativa invalida (se necessario)
        if (tried) cout << "Tipo invalido!" << endl << endl;
        tried = true;
        reapeat = false;

        // Exibir opcoes
        cout << "Selecione um tipo de usuario: " << endl;

        function<void(UserTypeEnum)> showOneOption = [&typeLabelMap, &typeCodeMap] (const UserTypeEnum userType) {
            cout << "\t" << typeCodeMap.find(userType)->second << " - " << typeLabelMap.find(userType)->second << endl;
        };

        for_each (userTypesList.begin(), userTypesList.end(), showOneOption);

        // Capturar entrada
        cin >> readInput;
        cout << endl;
        if (readInput == "0") break;

        // Validar entrada: Tipo
        int selectedTypeCode;

        try {
            selectedTypeCode = stoi(readInput);

        } catch (exception error) {
            reapeat = true;
            continue;
        }

        for (uint i = 0; i < userTypesList.size(); i++) {

            // Validar entrada: Valor
            const UserTypeEnum validUserType = userTypesList[i];
            const int validTypeCode = typeCodeMap.find(validUserType)->second;
            if (selectedTypeCode != validTypeCode) continue;

            // Opcao valida informada!
            this->currentUser->setType(validUserType);
            cout << "Tipo selecionado: " << typeLabelMap.find(validUserType)->second << endl << endl;
            break;
        }

        // Verificar: Alguma opcao valida encontrada?
        if (!this->currentUser->getType()) reapeat = true;

    } while (reapeat);
};

void UserController::setCurrentUserName(void) {
    cout << "Informe nome do usuario: ";
    char readInput[100];
    cin.ignore();
    cin.getline(readInput, sizeof(readInput));
    if (readInput != "0") this->currentUser->setName(string(readInput));
};

bool UserController::getDataToCreateUser(void) {

    cout << "> CADASTRO" << endl
         << "pressione '0' para sair" << endl
         << endl;

    // Reseta dados
    this->currentUser = make_shared<UserModel>();
    this->currentUserType = nullptr;

    // Define tipo de pessoa do usuario (pf/pj)
    this->setCurrentUserPersonType();
    if (this->currentUserType == nullptr) return false;

    // Captura codigo
    int code = this->getNumberFromStdIO("Informe um Codigo para o usuario", "Codigo invalido");
    if (!code) return false;
    this->currentUser->setCode(code);

    // Captura documento (cpf/cnpj)
    this->setCurrentUserCpfOrCnpj();
    if (this->currentUser->getCpfCnpj() == "") return false;

    // Captura tipo de usuario
    this->setCurrentUserType();
    if (!this->currentUser->getType()) return false;

    // Captura nome do usuario
    this->setCurrentUserName();
    if (this->currentUser->getName() == "") return false;

    // @todo: Captura lista de residuos de interesse
    return true;
};

bool UserController::createUser(void) {

    do {

        if (!this->getDataToCreateUser()) return false;

        try {
            this->dao->insert(this->currentUser);
            return true;

        } catch (invalid_argument error) {
            cout << "Ops! Dados de usuario invalidos" << endl;

        } catch (domain_error error) {
            string docType = (*this->currentUserType == PersonTypeEnum::PF) ? "CPF" : "CNPJ";
            cout << "Ops! Codigo ou " << docType << " ja cadastrado(s) para outro usuario." << endl;

        } catch (exception error) {
            cout << "Falha inesperada ao tentar adicionar usuario" << endl;
        }

        cout << "Realizar nova tentativa? (s/n): ";
        string tryAgain;
        cin >> tryAgain;
        cout << endl;
        if (tryAgain != "s") return false;

    } while (true);
};

bool UserController::runAction(int action) {

    if (action != ControllerActionEnum::CREATE) throw invalid_argument("Acao invalida para controlador de usuarios (1)");

    bool exit = true;

    if (this->createUser()) {
        exit = false;
        cout << "Usuario criado com sucesso!" << endl;
    }

    if (exit) cout << "Usuario selecionou: 'sair'..." << endl;
    return false;
};

bool UserController::runAction(int action, shared_ptr<UserModel> currentUser) {
    if (action != ControllerActionEnum::UPDATE) throw invalid_argument("Acao invalida para controlador de usuarios (2)");
    cout << "CHEOU em Atualizar usuario..." << endl;
    return false;
};

#endif