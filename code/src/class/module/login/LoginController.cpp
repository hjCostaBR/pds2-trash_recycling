#ifndef _LOGIN_CONTROLLER_CPP_
#define _LOGIN_CONTROLLER_CPP_

#include <stdio.h>
#include <memory>

#include "../../../../header/module/login/LoginController.h"
#include "../../../../header/common/MenuItemSet.h"
#include "../../../../header/common/MenuController.h"

using namespace std;

void LoginController::reset(void) {
    this->userLoginCode = 0;
    this->userLoginPwd = "";
};

// @todo: Ocultar senha do usuario!!
void LoginController::getLoginUserPwd(void) {
    string readInput;
    cout << "Informe a senha do usuario: ";
    cin >> readInput;
    if (readInput != "0") this->userLoginPwd = readInput;
};

// @todo: Implementar autenticacao
void LoginController::authenticate(void) {
    cout << "Autenticando usuario com os seguintes parametros: " << endl
         << "\tCodigo: " << this->userLoginCode << endl
         << "\tSenha: " << this->userLoginPwd << endl
         << endl;
};

void LoginController::initialize(void) {

    // Inicializa tela de LOGIN
    this->reset();
    cout << "> LOGIN" << endl
         << "pressione '0' para sair" << endl
         << endl;

    // Captura codigo & senha para login
    this->userLoginCode = this->getNumberFromStdIO("Informe o Codigo do usuario", "Codigo invalido");
    if (this->userLoginCode) this->getLoginUserPwd();

    // @todo: Executa autenticacao
    if (this->userLoginPwd != "") this->authenticate();

    // Sair
    cout << "Usuario selecionou: 'sair'..." << endl;
};

void LoginController::initialize(int action) {
    this->initialize();
}

#endif