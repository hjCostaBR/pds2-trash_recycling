#ifndef _LOGIN_CONTROLLER_CPP_
#define _LOGIN_CONTROLLER_CPP_

#include <stdio.h>
#include <memory>

#include "../../../../header/common/class/MenuItemSet.h"
#include "../../../../header/common/class/MenuController.h"
#include "../../../../header/module/login/LoginController.h"
#include "../../../../header/module/user/UserController.h"
#include "../../../../header/module/reject-type/RejectTypeController.h"

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
            auto searchResult = this->userDao->findOne(this->userLoginCode, "");
            auto loggedUser = searchResult.foundRegister;

            if (loggedUser != nullptr) {
                cout << "Login realizado com sucesso: Seja bem vindo(a) " << loggedUser->getName() << "!" << endl << endl;
                return loggedUser;
            }

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
    auto rejectTypeService = make_shared<RejectTypeService>();
    auto rejectTypeDao = make_shared<RejectTypeDAO>(rejectTypeService);
    auto rejectTypeController = make_shared<RejectTypeController>(rejectTypeDao, rejectTypeService);

    if (loggedUser->getType() == UserTypeEnum::ADMIN)
        menuItems.push_back(MenuItemSet("Novo Tipo de Residuo", rejectTypeController, ControllerActionEnum::CREATE));

    // Incluir opcao: Listar residuos
    menuItems.push_back(MenuItemSet("Listar Tipos de Residuo", rejectTypeController, ControllerActionEnum::RETRIVE, loggedUser));

    if (loggedUser->getType() != UserTypeEnum::ADMIN) {

        // Incluir opcao: Agendar coleta
        menuItems.push_back(MenuItemSet("Agendar Coleta de Residuos", nullptr));

        // Incluir opcao: Visualizar agendamentos
        menuItems.push_back(MenuItemSet("Minhas coletas agendadas", nullptr));
    }

    // Incluir opcao: Listar usuario cadastrados
    auto userService = make_shared<UserService>();
    auto userDao = make_shared<UserDAO>(userService);
    auto userController = make_shared<UserController>(userDao, userService, rejectTypeService, rejectTypeDao);

    if (loggedUser->getType() == UserTypeEnum::ADMIN)
        menuItems.push_back(MenuItemSet("Listar usuarios", userController, ControllerActionEnum::RETRIVE));

    // Incluir opcao: Atualizar dados pessoais
    menuItems.push_back(MenuItemSet("Atualizar dados pessoais", userController, ControllerActionEnum::UPDATE, loggedUser));

    // Incluir opcao: Sair
    menuItems.push_back(MenuItemSet("Sair", nullptr));

    // Exibir menu
    MenuController menuController("Menu Principal", menuItems);
    menuController.runAction();
};

bool LoginController::runAction(void) {

    auto loggedUser = this->login();

    if (loggedUser == nullptr) {
        cout << "Usuario selecionou: 'sair'..." << endl;
        return false;
    }

    this->showLoggedOptions(loggedUser);
    return true;
};

#endif