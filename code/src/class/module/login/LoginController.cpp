#ifndef _LOGIN_CONTROLLER_CPP_
#define _LOGIN_CONTROLLER_CPP_

#include <stdio.h>
#include <memory>

#include "../../../../header/module/login/LoginController.h"
#include "../../../../header/common/class/MenuItemSet.h"
#include "../../../../header/common/class/MenuController.h"

using namespace std;

void LoginController::reset(void) {
    this->userLoginCode = 0;
    this->userLoginPwd = "";
};

// @todo: Ocultar senha do usuario!!
// void LoginController::getLoginUserPwd(void) {
//     string readInput;
//     cout << "Informe a senha do usuario: ";
//     cin >> readInput;
//     if (readInput != "0") this->userLoginPwd = readInput;
// };

shared_ptr<UserModel> LoginController::authenticate(void) {
    auto foundUser = this->userDao->getExistingUser(this->userLoginCode, "");
    if (foundUser == nullptr) return nullptr;
    cout << "Login realizado com sucesso: Seja bem vindo(a) " << foundUser->getName() << "!" << endl;
    return foundUser;
};

// @todo: Validar senha
shared_ptr<UserModel> LoginController::login() {

    do {

        // Inicializa tela de LOGIN
        this->reset();
        cout << "> LOGIN" << endl
             << "pressione '0' para sair" << endl
             << endl;

        try {

            // Captura codigo & senha para login
            this->userLoginCode = this->getNumberFromStdIO("Informe o Codigo do usuario", "Codigo invalido");
            if (!this->userLoginCode) return nullptr;

            // @todo: Validar senha
            // this->getLoginUserPwd();
            // if (this->userLoginPwd != "") return false;

            // Executa autenticacao
            auto loggedUser = this->authenticate();
            if (loggedUser != nullptr) return loggedUser;
            cout << "Usuario nao encontrado!" << endl;

        } catch (exception error) {
            cout << "Falha inesperada ao tentar realizar autenticacao de usuario" << endl;
        }

        cout << "Realizar nova tentativa? (s/n): ";
        string tryAgain;
        cin >> tryAgain;
        cout << endl;
        if (tryAgain != "s") return nullptr;

    } while (true);
};

void LoginController::showLoggedOptions(const shared_ptr<UserModel> loggedUser) {

    vector<MenuItemSet> menuItems;

    // Incluir opcao: Add residuo
    if (loggedUser->getType() == UserTypeEnum::ADMIN)
        menuItems.push_back(MenuItemSet("Novo Tipo de Residuo", nullptr));

    // Incluir opcao: Listar residuos
    menuItems.push_back(MenuItemSet("Listar Tipos de Residuo", nullptr));

    // Incluir opcao: Agendar coleta
    if (loggedUser->getType() != UserTypeEnum::ADMIN)
        menuItems.push_back(MenuItemSet("Agendar Coleta de Residuos", nullptr));

    // Incluir opcao: Visualizar agendamentos
    if (loggedUser->getType() != UserTypeEnum::ADMIN)
        menuItems.push_back(MenuItemSet("Minhas coletas agendadas", nullptr));

    // Incluir opcao: Listar usuario cadastrados
    if (loggedUser->getType() == UserTypeEnum::ADMIN)
        menuItems.push_back(MenuItemSet("Listar usuarios", nullptr));

    // Incluir opcao: Atualizar dados pessoais
    menuItems.push_back(MenuItemSet("Atualizar dados pessoais", nullptr));

    // Incluir opcao: Sair
    menuItems.push_back(MenuItemSet("Sair", nullptr));

    // Exibir menu
    MenuController menuController("Menu Principal", menuItems);
    menuController.initialize();
};

void LoginController::initialize(void) {

    auto loggedUser = this->login();

    if (loggedUser != nullptr) {
        this->showLoggedOptions(loggedUser);
        return;
    }

    cout << "Usuario selecionou: 'sair'..." << endl;
};

void LoginController::initialize(int action) {
    this->initialize();
}

#endif