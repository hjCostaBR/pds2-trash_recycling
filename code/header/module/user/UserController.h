#ifndef _USER_CONTROLLER_H_
#define _USER_CONTROLLER_H_

#include <memory>
#include "../../common/class/Controller.h"
#include "../../common/class/MenuController.h"
#include "../../common/enums.h"
#include "./UserModel.h"
#include "./UserDAO.h"

/**
 * CONTROLLER
 * Gerencia a interacao com as 'telas' relacionadas a USUARIO no sistema
 * Trash Recycling System
 * 
 * @author hjcostabr
 */
class UserController: public Controller {

private:

    /** DAO. */
    shared_ptr<UserDAO> dao = nullptr;
    /** Servico. */
    shared_ptr<UserService> service = nullptr;

    /** Usuario sendo manipulado no momento. */
    shared_ptr<UserModel> currentUser = nullptr;
    /** Tipo de pessoa do usuario atual. */
    shared_ptr<PersonTypeEnum> currentUserType = nullptr;


    /**
     * Efetua cadastro de novo usuario.
     */
    bool createUser(void);

    /**
     * Captura & retorna dados para inserir 01 novo usuario.
     * @return SE os dados necessarios foram completamente coletados.
     */
    bool getDataToCreateUser(void);

    /**
     * Captura & define tipo (pf /pj) para insercao de novo usuario.
     */
    void setCurrentUserPersonType(void);

    /**
     * Captura & define valor para CPF/CNPJ de 01 novo usuario a ser cadastrado.
     */
    void setCurrentUserCpfOrCnpj(void);

    /**
     * Captura & define tipo do usuario atual.
     */
    void setCurrentUserType(void);

    /**
     * Captura & define nome do usuario atual.
     */
    void setCurrentUserName(void);

public:

    /** Contrutor. */
    UserController(const shared_ptr<UserDAO> dao, const shared_ptr<UserService> service)
        : dao(dao), service(service)
        {};

    /**
     * @inherit
     */
    virtual bool runAction(int action) override;

    /**
     * @inherit
     */
    virtual bool runAction(int action, shared_ptr<UserModel> currentUser) override;
};

#endif