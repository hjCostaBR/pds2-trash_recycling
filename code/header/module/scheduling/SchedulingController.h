#ifndef _SCHEDULING_CONTROLLER_H_
#define _SCHEDULING_CONTROLLER_H_

/**
 * CONTROLLER
 * Gerencia a interacao com as 'telas' relacionadas a AGENDAMENTO no sistema
 * Trash Recycling System
 * 
 * @author hjcostabr
 */
class SchedulingController: public Controller {

private:

    /** DAO. */
    shared_ptr<SchedulingDAO> dao = nullptr;

    /** Classe de servico. */
    shared_ptr<SchedulingService> service = nullptr;

    /** Dados do registro sendo manipulado no momento. */
    shared_ptr<SchedulingModel> currentScheduling = nullptr;


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
    bool update(shared_ptr<SchedulingModel> scheduling);

    /**
     * Monta & exibe listagem de registros + opcoes de acao.
     * @return Flag: SE o usuario selecionou 'sair'.
     */
    bool showList(void);

    /** Captura & define nome para o registro em edicao no momento. */
    void setCurrentSchedulingName(void);

public:

    /** Contrutor. */
    SchedulingController(const shared_ptr<SchedulingDAO> dao, const shared_ptr<SchedulingService> service)
        : dao(dao), service(service) {};

    /**
     * @inherit
     */
    virtual bool runAction(int action) override;
};

#endif