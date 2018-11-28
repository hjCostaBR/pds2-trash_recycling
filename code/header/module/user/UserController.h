#ifndef _USER_CONTROLLER_H_
#define _USER_CONTROLLER_H_

#include <memory>
#include "../../common/Controller.h"
#include "../../common/MenuController.h"
#include "../../common/enums.h"
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

    /**
     * Captura & retorna tipo para insercao de novo usuario (pf /pj).
     * @return Dados para inserir 01 novo usuario.
     */
    PersonTypeEnum getNewUserTypeFromStdIo(void) const;

    /**
     * Captura & retorna valor para CPF/CNPJ de 01 novo usuario a ser cadastrado.
     * @param personType Tipo de pessoa (pf/pj).
     * @return Cpf/Cnpj
     */
    string getCpfOrCnpjFromStdIo(PersonTypeEnum personType) const;

public:

    /** Contrutor. */
    UserController() {};

    /**
     * @inherit
     */
    virtual void initialize(void) override;

    /**
     * @inherit
     */
    virtual void initialize(int action) override;
};

#endif