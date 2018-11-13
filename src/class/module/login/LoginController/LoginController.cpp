#ifndef _LOGIN_CONTROLLER_CPP_
#define _LOGIN_CONTROLLER_CPP_

#include <stdio.h>

#include "./LoginController.h"
#include "../../../common/MenuController/MenuController.h"
#include "../../../common/PageControllerSet/PageControllerSet.h"

using namespace std;

// Forca valor das variaveis necessarias para autenticacao para seus valores 'default'
void LoginController::reset(void)
{
    this->userLoginCode = NULL;
    this->userLoginPwd = NULL;
};

// Captura codigo do usuario para o qual sera feito o login
void LoginController::getLoginUserCode(void)
{
    bool failure = false;
    bool tried = false;
    string readInput;
    int insertedCode;

    do {

        // Notifica tentativa invalida (se necessario)
        if (tried) {
            cout << "Codigo invalido '" << readInput << "'!" << endl;

        } else {
            tried = true;
        }

        cout << "Informe o Codigo do usuario: ";

        // Captura entrada
        cin >> readInput;

        try {
            insertedCode = stoi(readInput);
            
        } catch (exception error) {
            failure = true;
        }

    } while (failure);

    // Define codigo do usuario (se houver)
    if (insertedCode != 0) {
        this->userLoginCode = &insertedCode;
    }
};

// @todo: Ocultar senha do usuario!!
// Captura senha para autenticacao do usuario 
void LoginController::getLoginUserPwd(void)
{
    string readInput;
    cout << "Informe a senha do usuario: ";
    cin >> readInput;

    if (readInput != "0") {
        cout << "CHICO!!";
        this->userLoginPwd = &readInput;
    }
};

// @todo: Implementar autenticacao
// Autentica dados para login de usuario
void LoginController::authenticate(void)
{
    cout << "Autenticando usuario com os seguintes parametros: " << endl
         << "\tCodigo: " << *this->userLoginCode << endl
         << "\tSenha: " << *this->userLoginPwd << endl
         << endl;
};

// Inicializa exibicao da tela de login
void LoginController::initialize(void)
{

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

    // @todo: Executa autentiacaos
    if (this->userLoginPwd != NULL) {
        this->authenticate();
    }

    // Sair
    cout << "Usuario selecionou 'sair'..." << endl;
};

#endif