#ifndef _USER_CONTROLLER_CPP_
#define _USER_CONTROLLER_CPP_

#include <memory>
#include <functional>
#include <map>
#include <algorithm>
#include <sstream>
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
        cout << "Informe o tipo de pessoa do cadastro (pf/pj): ";
        cin >> readInput;
        cin.ignore();
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

    userTypesList.push_back(UserTypeEnum::RECEIVER);
    typeCodeMap[UserTypeEnum::RECEIVER] = 1;

    userTypesList.push_back(UserTypeEnum::DONATOR);
    typeCodeMap[UserTypeEnum::DONATOR] = 2;

    do {

        // Notifica tentativa invalida (se necessario)
        if (tried) cout << "Tipo invalido!" << endl << endl;
        tried = true;
        reapeat = false;

        // Exibir opcoes
        cout << "Selecione um tipo de usuario: " << endl;

        function<void(UserTypeEnum)> showOneOption = [&typeCodeMap, this] (const UserTypeEnum userType) {
            cout << "\t" << typeCodeMap.find(userType)->second
                << " - " << this->service->getUserTypeLabel(userType) << endl;
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
            cout << "Tipo selecionado: " << this->service->getUserTypeLabel(validUserType) << endl << endl;
            break;
        }

        // Verificar: Alguma opcao valida encontrada?
        if (!this->currentUser->getType()) reapeat = true;

    } while (reapeat);
};

void UserController::setCurrentUserName(void) {
    const string readInput = this->getStringFromStdIO("Informe nome do usuario: ");
    if (readInput != "0") this->currentUser->setName(readInput);
};

void UserController::setCurrentUserRejTypeList(void) {

    // Confirma intencao alterar essa lista
    cout << endl;
    const bool update = this->aksYesOrNoQuestionThroughStdIO("Deseja alterar lista de Tipos de Residuo de interesse?");
    if (!update) return;

    // Exibe opcoes disponiveis
    cout << ">> Tipos de Residuo disponiveis: " << endl;
    const auto rejTypesSearch = this->rejTypeDao->findAll();
    this->rejTypeService->showRegistersListData(rejTypesSearch);

    // Captura selecao do usuario
    vector<int> selectedCodes;
    bool repeat = true;

    do {

        // Captura
        const string selectedCodesStr = this->getStringFromStdIO("Insira lista de codigos (separados por virgula)");

        stringstream ss(selectedCodesStr);
        string item;
        bool error = false;

        while (getline(ss, item, ',')) {

            try {

                const int code = stoi(item);
                const auto existanceTestSearch = this->rejTypeDao->findOne(code);

                if (existanceTestSearch.foundRegister == nullptr) {
                    cout << "Tipo de Residuo de codigo '" << code << "' nao existe" << endl;
                    error = true;
                    continue;
                }

                selectedCodes.push_back(code);

            } catch (exception err) {
                cout << "Valor invalido: '" << item << "'" << endl;
                error = true;
            }
        }

        // Valida
        if (!error) {
            repeat = false;
            continue;
        }

        cout << endl;
        const bool tryAgain = this->aksYesOrNoQuestionThroughStdIO("Lista invalida. Deseja tentar novamente?");
        if (!tryAgain) return;

    } while (repeat);

    // Add tipos de residuo para o usuario
    for (uint i = 0; i < selectedCodes.size(); i++) {
        this->currentUser->addRejectTypeOfInterest(selectedCodes[i]);
    }
};

bool UserController::getDataForUserFromStdIo(const bool insert, const bool admin) {

    cout << "pressione '0' para sair" << endl
         << endl;

    // Define tipo de pessoa do usuario (pf/pj)
    this->setCurrentUserPersonType();
    if (this->currentUserType == nullptr) return false;

    // Captura codigo (se necessario)
    if (insert) {
        int code = this->getNumberFromStdIO("Informe um Codigo para o usuario", "Codigo invalido");
        if (!code) return false;
        this->currentUser->setCode(code);
    }

    // Captura documento (cpf/cnpj)
    this->setCurrentUserCpfOrCnpj();
    if (this->currentUser->getCpfCnpj() == "") return false;

    // Captura tipo de usuario (se necessario)
    if (!admin) {
        this->setCurrentUserType();
        if (!this->currentUser->getType()) return false;
    }

    // Captura nome do usuario
    this->setCurrentUserName();
    if (this->currentUser->getName() == "") return false;

    // Captura lista de tipos de residuo de interesse do usuario
    this->setCurrentUserRejTypeList();
    return true;
};

bool UserController::create(void) {

    do {

        cout << "> CADASTRO" << endl;

        this->currentUser = make_shared<UserModel>();
        this->currentUserType = nullptr;

        if (!this->getDataForUserFromStdIo(true, false)) return false;

        try {
            this->dao->insert(this->currentUser);
            cout << "Usuario criado com sucesso!" << endl;
            return true;

        } catch (invalid_argument error) {
            cout << "Ops! Dados de usuario invalidos" << endl;

        } catch (domain_error error) {
            string docType = (*this->currentUserType == PersonTypeEnum::PF) ? "CPF" : "CNPJ";
            cout << "Ops! Codigo ou " << docType << " ja cadastrado(s) para outro usuario." << endl;

        } catch (exception error) {
            cout << "Falha inesperada ao tentar adicionar usuario" << endl;
        }

        if (!this->aksYesOrNoQuestionThroughStdIO("Realizar nova tentativa?")) return false;

    } while (true);
};

void UserController::showDataTableHeader(void) const {
    cout << "|\tCodigo\t|"
         << "\tCPF/CNPJ\t|"
         << "\tTipo\t\t|"
         << "\tNome\t\t|"
         << endl;
};

bool UserController::update(shared_ptr<UserModel> currentUser) {

    // Exibir dados atuais
    cout << "Dados atuais cadastrados:" << endl;
    this->showDataTableHeader();
    this->service->showRegisterData(currentUser);
    cout << endl;

    // Confirmar desejo pela alteracao
    if (!this->aksYesOrNoQuestionThroughStdIO("Alterar cadastro?")) return false;

    do {
        try {

            this->currentUser = currentUser;
            this->currentUserType = nullptr;

            if (!this->getDataForUserFromStdIo(false, (UserTypeEnum)currentUser->getType() == UserTypeEnum::ADMIN))
                return false;

            this->dao->update(this->currentUser);
            cout << "Dados atualizados com sucesso!" << endl;
            return true;

        } catch (invalid_argument error) {
            cout << "Ops! Dados de usuario invalidos" << endl;

        } catch (domain_error error) {
            string docType = (*this->currentUserType == PersonTypeEnum::PF) ? "CPF" : "CNPJ";
            cout << "Ops! " << docType << " ja cadastrado para outro usuario." << endl;

        } catch (exception error) {
            cout << "Falha inesperada ao tentar atualizar usuario" << endl;
        }

        if (!this->aksYesOrNoQuestionThroughStdIO("Realizar nova tentativa?")) return false;

    } while (true);
};

void UserController::showList(void) const {

};

bool UserController::runAction(int action) {

    if (action != ControllerActionEnum::CREATE && action != ControllerActionEnum::RETRIVE)
        throw invalid_argument("Acao invalida para controlador de usuarios (1)");

    bool exit = false;

    switch (action) {
        case ControllerActionEnum::CREATE:
            exit = (!this->create());
            break;

        case ControllerActionEnum::RETRIVE:
            this->showList();
            exit = false;
            break;
    }


    if (exit) cout << "Usuario selecionou: 'sair'..." << endl;
    return false;
};

bool UserController::runAction(int action, shared_ptr<UserModel> currentUser) {
    if (action != ControllerActionEnum::UPDATE) throw invalid_argument("Acao invalida para controlador de usuarios (2)");
    if (!this->update(currentUser)) cout << "Usuario selecionou: 'sair'..." << endl;
    return false;
};

#endif