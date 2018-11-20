#ifndef _LOGIN_CONTROLLER_H_
#define _LOGIN_CONTROLLER_H_

#include "../../../common/MenuController/MenuController.h"

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
    int* userLoginCode;
    string* userLoginPwd;

    void reset(void);
    void getLoginUserCode(void);
    void getLoginUserPwd(void);
    void authenticate(void);

public:
    LoginController() {};
    virtual void initialize(void);
};

#endif