#ifndef _LOGIN_CONTROLLER_H_
#define _LOGIN_CONTROLLER_H_

#include "../../common/class/Controller.h"
#include "../../common/class/MenuController.h"
#include "../../module/user/UserDAO.h"

/**
 * CONTROLLER
 * Gerencia a interacao com a 'tela' de LOGIN de usuario no sistema
 * Trash Recycling System
 * 
 * @author hjcostabr
 */
class LoginController: public Controller {

private:

    /** DAO de usuario. */
    shared_ptr<UserDAO> userDao = nullptr;

    /** Codigo do usuario para o qual eh feita 01 tentativa de login. */
    int userLoginCode = 0;

    /** Senha do usuario para o qual eh feita 01 tentativa de login. */
    string userLoginPwd = "";


    /** Forca valor das variaveis necessarias para autenticacao para seus valores 'default'. */
    void reset(void);

    /** Captura senha para autenticacao do usuario. */
    // void getLoginUserPwd(void);

    /**
     * Autentica dados para login de usuario.
     * @return Status de sucesso na operacao.
     */
    bool authenticate(void);

    /** Encapsula procedimento de interacao com usuario para realizar login. */
    bool login(void);

    /** Monta & exibe opcoes para usuario logado. */
    void showLoggedOptions(void);

public:

    /** Contrutor. */
    LoginController(const shared_ptr<UserDAO> userDao): userDao(userDao) {};

    /**
     * @inherit
     */
    virtual void initialize(void);

    /**
     * @inherit
     */
    virtual void initialize(int action);
};

#endif