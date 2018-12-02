#ifndef _REJECTTYPE_CONTROLLER_CPP_
#define _REJECTTYPE_CONTROLLER_CPP_

#include "../../../../header/module/user/UserModel.h"
#include "../../../../header/module/reject-type/RejectTypeController.h"
#include "../../../../header/module/reject-type/RejectTypeModel.h"

using namespace std;

bool RejectTypeController::create(void) {

    do {

        cout << "> CADASTRO" << endl;
        cout << "pressione '0' para sair" << endl << endl;

        this->currentRejectType = make_shared<RejectTypeModel>();

        if (!this->getDataFromStdIo(true)) return false;

        try {
            this->dao->insert(this->currentRejectType);
            cout << "Tipo de Residuo criado com sucesso!" << endl;
            return true;

        } catch (invalid_argument error) {
            cout << endl << "Ops! Dados de Tipo de Residuo invalidos" << endl;

        } catch (domain_error error) {
            cout << endl << "Ops! Codigo ja cadastrado(s) para outro Tipo de Residuo." << endl;

        } catch (exception error) {
            cout << endl << "Falha inesperada ao tentar adicionar Tipo de Residuo" << endl;
        }

        if (!this->aksYesOrNoQuestionThroughStdIO("Realizar nova tentativa?")) return false;

    } while (true);
};

bool RejectTypeController::getDataFromStdIo(const bool insert) {

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

bool RejectTypeController::update(shared_ptr<RejectTypeModel> rejType) {

    cout << endl << "> EDITAR TIPO de RESIDUO" << endl << endl;

    // Exibir dados atuais
    cout << "Dados atuais cadastrados:" << endl;
    this->showDataTableHeader();
    this->service->showRegisterData(rejType);
    cout << endl;

    // Confirmar desejo pela alteracao
    if (!this->aksYesOrNoQuestionThroughStdIO("Alterar cadastro?")) return false;
    cin.ignore();

    do {
        try {

            this->currentRejectType = rejType;
            if (!this->getDataFromStdIo(false)) return false;

            this->dao->update(this->currentRejectType);
            cout << "Dados atualizados com sucesso!" << endl;
            return true;

        } catch (invalid_argument error) {
            cout << "Ops! Dados de Tipo de Residuo invalidos" << endl;

        } catch (exception error) {
            cout << "Falha inesperada ao tentar atualizar Tipo de Residuo" << endl;
        }

        if (!this->aksYesOrNoQuestionThroughStdIO("Realizar nova tentativa?")) return false;

    } while (true);
};

void RejectTypeController::showDataTableHeader(void) const {
    cout << "| Codigo\t|"
         << "\tNome\t|"
         << "\tInstrucao de armazenamento\t\t\t\t|"
         << endl;
};

bool RejectTypeController::showList(const shared_ptr<UserModel> currentUser) {

    cout << "> TIPOS de RESIDUO" << endl
        << "Pressione '0' para sair..." << endl << endl;

    // Exibe listagem
    this->showDataTableHeader();
    this->service->showRegistersListData(this->dao->findAll());

    // Captura acao selecionada pelo usuario
    string action = "";

    do {

        if (action != "") cout << "Acao '" << action << "' invalida!" << endl << endl;
        cout << "Pressione 'e' (para editar) ou 'r' (para remover): ";

        char readInput[100];
        scanf("%s", &readInput);
        action = string(readInput);

        if (action == "0") return false;

    } while (action != "e" && action != "r");

    const bool remove = (action == "r");
    const bool update = (action == "e");

    const string actionStr = (remove) ? "REMOVER" : "EDITAR";
    cout << "Opcao selecionada: " << actionStr << endl << endl;

    // Seleciona item sobre o qual a acao sera executada
    FindResult<RejectTypeModel> rejTypeSearch;
    string selectionDescMsg = "Informe o codigo do Tipo de Residuo a ser ";
    selectionDescMsg += (remove) ? "removido" : "editado";

    do {

        const int selectedRejCode = this->getNumberFromStdIO(selectionDescMsg, "Codigo invalido: ");
        if (selectedRejCode == 0) return false;

        rejTypeSearch = this->dao->findOne(selectedRejCode);

        if (rejTypeSearch.foundRegister == nullptr) {
            cout << "Tipo de residuo nao encontrado (codigo invalido)" << endl << endl;
            const auto tryAgain = this->aksYesOrNoQuestionThroughStdIO("Deseja tentar novamente?");
            if (!tryAgain) return false;
        }

    } while (rejTypeSearch.foundRegister == nullptr);

    // Executa edicao (se necessario)
    if (update) return this->update(rejTypeSearch.foundRegister);

    // Executa remocao (se necessario)
    this->dao->deleteOne(rejTypeSearch.line);
    cout << "Tipo de residuo removido com sucesso!" << endl;
    return true;
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
    cout << "Informe nome do tipo de residuo: ";
    char readInput[100];
    cin.getline(readInput, sizeof(readInput));
    if (readInput != "0") this->currentRejectType->setName(string(readInput));
};

void RejectTypeController::setCurrentRejectTypeStorageSpecification(void) {
    cout << "Informe descricao de armazenamento para este tipo de residuo (max 100 caracteres): ";
    char readInput[100];
    cin.getline(readInput, sizeof(readInput));
    if (readInput != "0") this->currentRejectType->setStorageSpecification(string(readInput));
};

#endif