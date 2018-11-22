#ifndef _LOGIN_CONTROLLER_H_
#define _LOGIN_CONTROLLER_H_

#include <memory>
#include "../../common/Controller.h"
#include "../../common/MenuController.h"

/**
 * CONTROLLER
 * Gerencia a interacao com a 'tela' de LOGIN de usuario no sistema
 * Trash Recycling System
 * 
 * @author hjcostabr
 */
class LoginController: public Controller
{
private:
    int userLoginCode = 0;
    string userLoginPwd = "";

    // Forca valor das variaveis necessarias para autenticacao para seus valores 'default'
    void reset(void);

    // Captura codigo do usuario para o qual sera feito o login
    void getLoginUserCode(void);

    // Captura senha para autenticacao do usuario
    void getLoginUserPwd(void);

    // Autentica dados para login de usuario
    void authenticate(void);

public:
    // Contrutor
    LoginController() {};

    // Inicializa exibicao da tela de login
    virtual void initialize(void);
};

#endif