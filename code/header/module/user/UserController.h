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

    /** Dados do registro sendo manipulado no momento. */
    shared_ptr<UserModel> currentUser = nullptr;
    /** Tipo de pessoa do usuario atual. */
    shared_ptr<PersonTypeEnum> currentUserType = nullptr;


    /** Captura & define tipo (pf /pj) para insercao de novo usuario. */
    void setCurrentUserPersonType(void);

    /** Captura & define valor para CPF/CNPJ de 01 novo usuario a ser cadastrado. */
    void setCurrentUserCpfOrCnpj(void);

    /** Captura & define tipo do usuario atual. */
    void setCurrentUserType(void);

    /** Captura & define nome do usuario atual. */
    void setCurrentUserName(void);

    /** Efetua cadastro de novo usuario. */
    bool create(void);

    /**
     * Captura & retorna dados para inserir/atualizar 01 registro.
     *
     * @param insert Flag: Determina se a coleta de dados eh para realizar insercao (SE nao for, sera atualizacao).
     * @param admin Flag: Determina SE o usuario atual que realiza a operacao eh ADMIN.
     * @return
     */
    bool getDataForUserFromStdIo(const bool insert, const bool admin);

    /** Atualiza cadastro de 01 registro ja armazenado. */
    bool update(shared_ptr<UserModel> currentUser);

    /** Exibe cabecalho para exibicao tabular de dados. */
    void showDataTableHeader(void) const;

    /** Exibe listagem de usuarios cadastrados. */
    void showUsersList(void) const;

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
    virtual bool runAction(int action, shared_ptr<UserModel> currentUser);
};

#endif