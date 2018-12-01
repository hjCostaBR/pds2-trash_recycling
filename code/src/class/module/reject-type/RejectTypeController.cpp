#ifndef _REJECTTYPE_CONTROLLER_CPP_
#define _REJECTTYPE_CONTROLLER_CPP_

#include "../../../../header/module/reject-type/RejectTypeController.h"
#include "../../../../header/module/reject-type/RejectTypeModel.h"

using namespace std;

bool RejectTypeController::create(void) {

    /*do {

        cout << "> CADASTRO" << endl;

        this->currentUser = make_shared<RejectTypeModel>();
        this->currentUserType = nullptr;

        if (!this->getDataForUserFromStdIo(true, false)) return false;

        try {
            this->dao->insert(this->currentUser);
            cout << "Usuario criado com sucesso!" << endl;
            return true;

        } catch (invalid_argument error) {
            cout << "Ops! Dados de usuario invalidos" << endl;

        } catch (domain_error error) {
            string docType = (*this->currentUserType == PersonTypeEnum::PF) ? "CPF" : "CNPJ";
            cout << "Ops! Codigo ou " << docType << " ja cadastrado(s) para outro usuario." << endl;

        } catch (exception error) {
            cout << "Falha inesperada ao tentar adicionar usuario" << endl;
        }

        if (!this->aksYesOrNoQuestionThroughStdIO("Realizar nova tentativa?")) return false;

    } while (true);*/
};

bool RejectTypeController::getDataFromStdIo(const bool insert, const bool admin) {

};

bool RejectTypeController::update(shared_ptr<RejectTypeModel> currentUser) {

    /*// Exibir dados atuais
    cout << "Dados atuais cadastrados:" << endl;
    this->showUserDataTableHeader();
    this->service->showRegisterData(currentUser);
    cout << endl;

    // Confirmar desejo pela alteracao
    if (!this->aksYesOrNoQuestionThroughStdIO("Alterar cadastro?")) return false;

    do {
        try {

            this->currentUser = currentUser;
            this->currentUserType = nullptr;

            if (!this->getDataForUserFromStdIo(false, (UserTypeEnum)currentUser->getType() == UserTypeEnum::ADMIN))
                return false;

            this->dao->update(this->currentUser);
            cout << "Dados atualizados com sucesso!" << endl;
            return true;

        } catch (invalid_argument error) {
            cout << "Ops! Dados de usuario invalidos" << endl;

        } catch (domain_error error) {
            string docType = (*this->currentUserType == PersonTypeEnum::PF) ? "CPF" : "CNPJ";
            cout << "Ops! " << docType << " ja cadastrado para outro usuario." << endl;

        } catch (exception error) {
            cout << "Falha inesperada ao tentar atualizar usuario" << endl;
        }

        if (!this->aksYesOrNoQuestionThroughStdIO("Realizar nova tentativa?")) return false;

    } while (true);*/
    return false;
};

void RejectTypeController::showDataTableHeader(void) const {
    /*cout << "|\tCodigo\t|"
         << "\tCPF/CNPJ\t|"
         << "\tTipo\t\t|"
         << "\tNome\t\t|"
         << endl;*/
};

bool RejectTypeController::runAction(int action) {

    /*if (action != ControllerActionEnum::CREATE && action != ControllerActionEnum::RETRIVE)
        throw invalid_argument("Acao invalida para controlador de usuarios (1)");

    bool exit = false;

    switch (action) {
        case ControllerActionEnum::CREATE:
            exit = (!this->create());
            break;

        case ControllerActionEnum::RETRIVE:
            this->showUsersList();
            exit = false;
            break;
    }


    if (exit) cout << "Usuario selecionou: 'sair'..." << endl;
     */
    return false;
};

bool RejectTypeController::runAction(int action, shared_ptr<RejectTypeModel> currentUser) {
    // if (action != ControllerActionEnum::UPDATE) throw invalid_argument("Acao invalida para controlador de usuarios (2)");
    // if (!this->updateUser(currentUser)) cout << "Usuario selecionou: 'sair'..." << endl;
    return false;
};

#endif