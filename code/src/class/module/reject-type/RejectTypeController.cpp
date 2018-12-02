#ifndef _REJECTTYPE_CONTROLLER_CPP_
#define _REJECTTYPE_CONTROLLER_CPP_

#include "../../../../header/module/user/UserModel.h"
#include "../../../../header/module/reject-type/RejectTypeController.h"
#include "../../../../header/module/reject-type/RejectTypeModel.h"

using namespace std;

bool RejectTypeController::create(void) {

    do {

        cout << "> CADASTRO" << endl;

        this->currentRejectType = make_shared<RejectTypeModel>();

        if (!this->getDataFromStdIo(true)) return false;

        try {
            this->dao->insert(this->currentRejectType);
            cout << "Tipo de Residuo criado com sucesso!" << endl;
            return true;

        } catch (invalid_argument error) {
            cout << "Ops! Dados de Tipo de Residuo invalidos" << endl;

        } catch (domain_error error) {
            // @todo: Definir msg de notificacao
            cout << "Ops! Codigo ja cadastrado(s) para outro Tipo de Residuo." << endl;

        } catch (exception error) {
            cout << "Falha inesperada ao tentar adicionar Tipo de Residuo" << endl;
        }

        if (!this->aksYesOrNoQuestionThroughStdIO("Realizar nova tentativa?")) return false;

    } while (true);
};

bool RejectTypeController::getDataFromStdIo(const bool insert) {

    cout << "pressione '0' para sair" << endl << endl;

    // Captura codigo (se necessario)
    if (insert) {
        int code = this->getNumberFromStdIO("Informe um Codigo para o Tipo de Residuo", "Codigo invalido");
        if (!code) return false;
        this->currentRejectType->setCode(code);
    }

    // Define nome
    this->setCurrentRejectTypeName();
    if (this->currentRejectType->getName() == "") return false;

    // Define instrucoes de armazenamento
    this->setCurrentRejectTypeStorageSpecification();
    if (this->currentRejectType->getStorageSpecification() == "") return false;

    return true;

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
    cout << "| Codigo\t|"
         << " Nome\t|"
         << " Instrucao de armazenamento\t\t|"
         << endl;
};

bool RejectTypeController::showList(const shared_ptr<UserModel> currentUser) const {

    this->showDataTableHeader();
    this->service->showRegistersListData(this->dao->findAll());

    // @todo: Arrumar isso
    return false;
};

bool RejectTypeController::runAction(int action) {
    if (action != ControllerActionEnum::CREATE) throw invalid_argument("Acao invalida para controlador de tipos de residuo (1)");
    if (!this->create()) cout << "Usuario selecionou: 'sair'..." << endl;
    return false;
};

bool RejectTypeController::runAction(int action, shared_ptr<UserModel> currentUser) {
    if (action != ControllerActionEnum::RETRIVE) throw invalid_argument("Acao invalida para controlador de Tipos de Residuo (2)");
    if (!this->showList(currentUser)) cout << "Usuario selecionou: 'sair'..." << endl;
    return false;
};

void RejectTypeController::setCurrentRejectTypeName(void) {
    const string readInput = this->getStringFromStdIO("Informe nome do tipo de residuo: ");
    if (readInput != "0") this->currentRejectType->setName(readInput);
};

void RejectTypeController::setCurrentRejectTypeStorageSpecification(void) {
    const string readInput = this->getStringFromStdIO("Informe descricao de armazenamento para este tipo de residuo (max 100 caracteres): ");
    if (readInput != "0") this->currentRejectType->setStorageSpecification(readInput);
};

#endif