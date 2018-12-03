#ifndef _SCHEDULING_CONTROLLER_H_
#define _SCHEDULING_CONTROLLER_H_

#include "SchedulingDAO.h"
#include "SchedulingService.h"
#include "../../common/class/Controller.h"
#include "../../module/meeting-point/MeetingPointDAO.h"
#include "../../module/meeting-point/MeetingPointService.h"
#include "../../module/user/UserDAO.h"
#include "../../module/user/UserService.h"

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

    /** DAO de Pontos de Coleta. */
    shared_ptr<MeetingPointDAO> mPointDao = nullptr;

    /** Classe de servico de Pontos de Coleta. */
    shared_ptr<MeetingPointService> mPointService = nullptr;

    /** DAO de Usuarios. */
    shared_ptr<UserDAO> userDao = nullptr;

    /** Classe de servico de Usuario. */
    shared_ptr<UserService> userService = nullptr;

    /** Dados do registro sendo manipulado no momento. */
    shared_ptr<SchedulingModel> currentScheduling = nullptr;


    /** Efetua cadastro de novo usuario. */
    bool create(const shared_ptr<UserModel> loggedUser);

    /**
     * Captura & retorna dados para inserir/atualizar 01 registro.
     *
     * @param insert Flag: Determina se a coleta de dados eh para realizar insercao (SE nao for, sera atualizacao).
     * @param loggedUser Usuario atual que executa o agendamento.
     * @return
     */
    bool getDataFromStdIo(const bool insert, const shared_ptr<UserModel> loggedUser);

    /** Atualiza cadastro de 01 registro ja armazenado. */
    bool update(shared_ptr<SchedulingModel> scheduling);

    /**
     * Monta & exibe listagem de registros + opcoes de acao.
     * @return Flag: SE o usuario selecionou 'sair'.
     */
    bool showList(void);

    /** Captura & define data para o registro em edicao no momento. */
    void setCurrentSchedulingDate(void);

    /** Captura & define ponto de coleta para o registro em edicao no momento. */
    void setCurrentSchedulingMeetingPoint(void);

    /** Captura & define doador para o registro em edicao no momento. */
    void setCurrentSchedulingDonator(const shared_ptr<UserModel> loggedUser);

    /** Captura & define receptor para o registro em edicao no momento. */
    void setCurrentSchedulingReceiver(const shared_ptr<UserModel> loggedUser);

    /** Captura & define lista de residuos para o registro em edicao no momento. */
    void setCurrentSchedulingRejectsList(void);

public:

    /** Contrutor. */
    SchedulingController(
        const shared_ptr<SchedulingDAO> dao,
        const shared_ptr<SchedulingService> service,
        const shared_ptr<MeetingPointDAO> mPointDao,
        const shared_ptr<MeetingPointService> mPointService,
        const shared_ptr<UserDAO> userDao,
        const shared_ptr<UserService> userService

    ) : dao(dao),
        service(service),
        mPointDao(mPointDao),
        mPointService(mPointService),
        userDao(userDao),
        userService(userService)
        {};

    /**
     * @inherit
     */
    virtual bool runAction(int action, shared_ptr<UserModel> currentUser);
};


#endif