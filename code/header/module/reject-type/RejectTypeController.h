#ifndef _REJECT_TYPE_CONTROLLER_H_
#define _REJECT_TYPE_CONTROLLER_H_

#include <memory>
#include "../../common/class/Controller.h"
#include "../../common/class/MenuController.h"
#include "./RejectTypeModel.h"
#include "./RejectTypeDAO.h"
#include "./RejectTypeService.h"

/**
 * CONTROLLER
 * Gerencia a interacao com as 'telas' relacionadas a TIPOS de RESIDUO no sistema
 * Trash Recycling System
 * 
 * @author hjcostabr
 */
class RejectTypeController: public Controller {

private:

    /** DAO. */
    shared_ptr<RejectTypeDAO> dao = nullptr;

    /** Dados do registro sendo manipulado no momento. */
    shared_ptr<RejectTypeModel> currentRejectType = nullptr;


    /** Efetua cadastro de novo usuario. */
    bool create(void);

    /**
     * Captura & retorna dados para inserir/atualizar 01 registro.
     *
     * @param insert Flag: Determina se a coleta de dados eh para realizar insercao (SE nao for, sera atualizacao).
     * @return
     */
    bool getDataFromStdIo(const bool insert);

    /** Atualiza cadastro de 01 registro ja armazenado. */
    bool update(shared_ptr<RejectTypeModel> currentRejectType);

    /** Exibe cabecalho para exibicao tabular de dados. */
    void showDataTableHeader(void) const;

    /** Captura & define nome para o registro em edicao no momento. */
    void setCurrentRejectTypeName(void);

    /** Captura & define instrucoes de armazenamento para registro em edicao no momento. */
    void setCurrentRejectTypeStorageSpecification(void);

public:

    /** Contrutor. */
    RejectTypeController(const shared_ptr<RejectTypeDAO> dao) : dao(dao) {};

    /**
     * @inherit
     */
    virtual bool runAction(int action) override;

    /**
     * @inherit
     */
    virtual bool runAction(int action, shared_ptr<RejectTypeModel> currentUser);
};

#endif