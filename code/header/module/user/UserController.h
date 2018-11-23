#ifndef _USER_CONTROLLER_H_
#define _USER_CONTROLLER_H_

#include <memory>
#include "../../common/Controller.h"
#include "../../common/MenuController.h"
#include "./UserModel.h"

/**
 * CONTROLLER
 * Gerencia a interacao com as 'telas' relacionadas a USUARIO no sistema
 * Trash Recycling System
 * 
 * @author hjcostabr
 */
class UserController: public Controller {

private:

    /**
     * Captura & retorna dados para inserir 01 novo usuario.
     * @return Dados para inserir 01 novo usuario.
     */
    UserModel getDataToCreateUser(void) const;

public:

    /** Contrutor. */
    UserController() {};

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