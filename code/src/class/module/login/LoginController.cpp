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

bool LoginController::authenticate(void) {
    auto foundUser = this->userDao->getExistingUser(this->userLoginCode, "");
    if (foundUser == nullptr) return false;
    cout << "Login realizado com sucesso: Seja bem vindo(a) " << foundUser->getName() << "!" << endl;
    return true;
};

// @todo: Validar senha
bool LoginController::login() {

    do {

        // Inicializa tela de LOGIN
        this->reset();
        cout << "> LOGIN" << endl
             << "pressione '0' para sair" << endl
             << endl;

        try {

            // Captura codigo & senha para login
            this->userLoginCode = this->getNumberFromStdIO("Informe o Codigo do usuario", "Codigo invalido");
            if (!this->userLoginCode) return false;

            // @todo: Validar senha
            // this->getLoginUserPwd();
            // if (this->userLoginPwd != "") return false;

            // Executa autenticacao
            if (this->authenticate()) return true;
            cout << "Usuario nao encontrado!" << endl;

        } catch (exception error) {
            cout << "Falha inesperada ao tentar realizar autenticacao de usuario" << endl;
        }

        cout << "Realizar nova tentativa? (s/n): ";
        string tryAgain;
        cin >> tryAgain;
        cout << endl;
        if (tryAgain != "s") return false;

    } while (true);
};

void LoginController::showLoggedOptions(void) {
    cout << "TODO: Mostrar menu 'logado'..." << endl;
};

void LoginController::initialize(void) {

    if (this->login()) {
        this->showLoggedOptions();
        return;
    }

    cout << "Usuario selecionou: 'sair'..." << endl;
};

void LoginController::initialize(int action) {
    this->initialize();
}

#endif