#ifndef _SCHEDULING_CONTROLLER_H_
#define _SCHEDULING_CONTROLLER_H_

#include "SchedulingDAO.h"
#include "SchedulingService.h"
#include "../../common/class/Controller.h"
#include "../../module/meeting-point/MeetingPointDAO.h"
#include "../../module/meeting-point/MeetingPointService.h"
#include "../../module/user/UserDAO.h"
#include "../../module/user/UserService.h"
#include "../../module/reject-type/RejectTypeService.h"
#include "../../module/reject-type/RejectTypeDAO.h"

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

    /** DAO de Tipos de Residuo. */
    shared_ptr<RejectTypeDAO> rejTypeDao = nullptr;
    /** Classe de servico de Tipos de Residuo. */
    shared_ptr<RejectTypeService> rejTypeService = nullptr;

    /** Dados do registro sendo manipulado no momento. */
    shared_ptr<SchedulingModel> currentScheduling = nullptr;

    /** Lista atual de Pontos de Coleta disponiveis. */
    vector<FindResult<MeetingPointModel>> availableMPoints;
    /** Lista atual de Doadores disponiveis. */
    vector<FindResult<UserModel>> availableDonators;
    /** Lista atual de Receptores disponiveis. */
    vector<FindResult<UserModel>> availableReceivers;
    /** Lista atual de Tipos de Residuo disponiveis. */
    vector<FindResult<RejectTypeModel>> availableRejTypes;


    /** Efetua cadastro de novo usuario. */
    bool create(const shared_ptr<UserModel> loggedUser);

    /**
     * Captura & retorna dados para inserir/atualizar 01 registro.
     *
     * @param loggedUser Usuario atual que executa o agendamento.
     * @return
     */
    bool getDataFromStdIo(const shared_ptr<UserModel> loggedUser);

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

    /**
     * Captura & define uma das pessoas envolvidas num agendamento (doador / receptor) para o registro em edicao no momento.
     *
     * @param loggedUser
     * @param setDonator Flag: Determina se a pessoa a ser definida eh 01 doador (SE nao for, sera 01 receptor).
     */
    void setCurrentSchedulingUser(const shared_ptr<UserModel> loggedUser, const bool setDonator);

    /** Captura & define lista de residuos para o registro em edicao no momento. */
    void setCurrentSchedulingRejectsList(void);

    /**
     * Captura as listas de opcoes necessarias para gerar 01 agendamento (doadores, receptores, tipos de residuos, etc.).
     *
     * @param loggedUserIsDonator Flag: Informa se o usuario que executa a acao eh do tipo Doador (SE nao for, sera considerado Receptor).
     * @return
     */
    bool getOptionsForScheduling(const bool loggedUserIsDonator);

public:

    /** Contrutor. */
    SchedulingController(
        const shared_ptr<SchedulingDAO> dao,
        const shared_ptr<SchedulingService> service,
        const shared_ptr<MeetingPointDAO> mPointDao,
        const shared_ptr<MeetingPointService> mPointService,
        const shared_ptr<UserDAO> userDao,
        const shared_ptr<UserService> userService,
        const shared_ptr<RejectTypeDAO> rejTypeDao,
        const shared_ptr<RejectTypeService> rejTypeService

    ) : dao(dao),
        service(service),
        mPointDao(mPointDao),
        mPointService(mPointService),
        userDao(userDao),
        userService(userService),
        rejTypeDao(rejTypeDao),
        rejTypeService(rejTypeService)
        {};

    /**
     * @inherit
     */
    virtual bool runAction(int action, shared_ptr<UserModel> currentUser);
};


#endif