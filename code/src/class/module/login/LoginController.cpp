#ifndef _LOGIN_CONTROLLER_CPP_
#define _LOGIN_CONTROLLER_CPP_

#include <stdio.h>
#include <memory>

#include "../../../../header/module/login/LoginController.h"
#include "../../../../header/common/PageControllerSet.h"
#include "../../../../header/common/MenuController.h"

using namespace std;

void LoginController::reset(void) {
    this->userLoginCode = NULL;
    this->userLoginPwd = NULL;
};

void LoginController::getLoginUserCode(void) {

    bool failure = false;
    bool tried = false;
    string readInput;
    int insertedCode;

    do {

        // Notifica tentativa invalida (se necessario)
        if (tried) cout << "Codigo invalido '" << readInput << "'!" << endl;
        tried = true;

        // Captura entrada
        cout << "Informe o Codigo do usuario: ";
        cin >> readInput;

        try {
            insertedCode = stoi(readInput);

        } catch (exception error) {
            failure = true;
        }

    } while (failure);

    // Define codigo do usuario (se houver)
    shared_ptr<int> chico(new int(100));

    if (insertedCode != 0) {
        *this->userLoginCode = insertedCode;
        *chico = insertedCode;
    }

    cout << "bar!";
};

// @todo: Ocultar senha do usuario!!
void LoginController::getLoginUserPwd(void) {


    cout << "baz!";
    string readInput;
    cout << "Informe a senha do usuario: ";
    cin >> readInput;

    if (readInput != "0") {
        cout << "CHICO!!";
        *this->userLoginPwd = readInput;
    }
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
    this->getLoginUserCode();

    if (this->userLoginCode != NULL) {
        this->getLoginUserPwd();
    }

    // @todo: Executa autenticacao
    if (this->userLoginPwd != NULL) {
        this->authenticate();
    }

    // Sair
    cout << "Usuario selecionou: 'sair'..." << endl;
};

#endif