#ifndef _USER_CONTROLLER_H_
#define _USER_CONTROLLER_H_

#include <memory>
#include "../../common/Controller.h"
#include "../../common/MenuController.h"

/**
 * CONTROLLER
 * Gerencia a interacao com as 'telas' relacionadas a USUARIO no sistema
 * Trash Recycling System
 * 
 * @author hjcostabr
 */
class UserController: public Controller {

private:

    // /** Codigo do usuario para o qual eh feita 01 tentativa de login. */
    // int userLoginCode = 0;
    //
    // /** Senha do usuario para o qual eh feita 01 tentativa de login. */
    // string userLoginPwd = "";
    //
    //
    // /** Forca valor das variaveis necessarias para autenticacao para seus valores 'default'. */
    // void reset(void);
    //
    // /** Captura codigo do usuario para o qual sera feito o login. */
    // void getLoginUserCode(void);
    //
    // /** Captura senha para autenticacao do usuario. */
    // void getLoginUserPwd(void);
    //
    // /** Autentica dados para login de usuario. */
    // void authenticate(void);

public:

    /** Contrutor. */
    UserController() {};

    /**
     * @inherit
     */
    virtual void initialize(int action);
};

#endif