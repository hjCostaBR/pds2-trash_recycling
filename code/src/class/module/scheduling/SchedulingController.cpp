#ifndef _SCHEDULING_CONTROLLER_CPP_
#define _SCHEDULING_CONTROLLER_CPP_

#include <sstream>
#include "../../../../header/module/user/UserModel.h"
#include "../../../../header/module/scheduling/SchedulingController.h"
#include "../../../../header/module/scheduling/SchedulingModel.h"

using namespace std;

bool SchedulingController::create(const shared_ptr<UserModel> loggedUser) {

    do {

        cout << "> NOVO AGENDAMENTO" << endl;
        cout << "pressione '0' para sair" << endl << endl;

        this->currentScheduling = make_shared<SchedulingModel>();

        if (!this->getDataFromStdIo(loggedUser)) return false;

        try {
            this->dao->insert(this->currentScheduling);
            cout << endl << "Agendamento criado com sucesso!" << endl;
            return true;

        } catch (invalid_argument error) {
            cout << endl << "Ops! Dados invalidos para adicionar agendamento" << endl;

        } catch (exception error) {
            cout << endl << "Falha inesperada ao tentar adicionar Ponto de Coleta" << endl;
        }

        if (!this->aksYesOrNoQuestionThroughStdIO("Realizar nova tentativa?")) return false;

    } while (true);
};

bool SchedulingController::getOptionsForScheduling(const bool loggedUserIsDonator) {

    this->availableMPoints = this->mPointDao->findAll();
    if (!this->availableMPoints.size()) throw domain_error("no-meeting-points");

    this->availableRejTypes = this->rejTypeDao->findAll();
    if (!this->availableRejTypes.size()) throw domain_error("no-reject-types");

    if (loggedUserIsDonator) {
        this->availableReceivers = this->userDao->findAllReceivers();
        if (!this->availableReceivers.size()) throw domain_error("no-receivers");
    }

    if (!loggedUserIsDonator) {
        this->availableDonators = this->userDao->findAllDonators();
        if (!this->availableDonators.size()) throw domain_error("no-donators");
    }
}

bool SchedulingController::getDataFromStdIo(const shared_ptr<UserModel> loggedUser) {

    // Define data
    this->setCurrentSchedulingDate();
    if (this->currentScheduling->getDate() == "") return false;

    // Define ponto de coleta
    this->setCurrentSchedulingMeetingPoint();
    if (!this->currentScheduling->getMeetingPointCode()) return false;

    // Define doador
    this->setCurrentSchedulingUser(loggedUser, true);
    if (!this->currentScheduling->getDonatorCode()) return false;

    // Define recpetor
    this->setCurrentSchedulingUser(loggedUser, false);
    if (!this->currentScheduling->getReceiverCode()) return false;

    // Define Residuos a serem trocados
    this->setCurrentSchedulingRejectsList();
    if (!this->currentScheduling->getRejectsToBeExchangedCodes().size()) return false;

    return true;
};

bool SchedulingController::update(shared_ptr<SchedulingModel> rejType) {

    // cout << endl << "> EDITAR PONTO de COLETA" << endl << endl;
    //
    // // Exibir dados atuais
    // cout << "Dados atuais cadastrados:" << endl;
    // this->service->showDataTableHeader();
    // this->service->showRegisterData(rejType);
    // cout << endl;
    //
    // // Confirmar desejo pela alteracao
    // if (!this->aksYesOrNoQuestionThroughStdIO("Alterar cadastro?")) return false;
    // cin.ignore();
    //
    // do {
    //     try {
    //
    //         this->currentScheduling = rejType;
    //         if (!this->getDataFromStdIo(false)) return false;
    //
    //         this->dao->update(this->currentScheduling);
    //         cout << "Dados atualizados com sucesso!" << endl;
    //         return true;
    //
    //     } catch (invalid_argument error) {
    //         cout << "Ops! Dados de Ponto de Coleta invalidos" << endl;
    //
    //     } catch (exception error) {
    //         cout << "Falha inesperada ao tentar atualizar Ponto de Coleta" << endl;
    //     }
    //
    //     if (!this->aksYesOrNoQuestionThroughStdIO("Realizar nova tentativa?")) return false;
    //
    // } while (true);
};

bool SchedulingController::showList(void) {

    // cout << "> PONTOS de COLETA" << endl
    //      << "Pressione '0' para sair..." << endl << endl;
    //
    // // Exibe listagem
    // this->service->showRegistersListData(this->dao->findAll());
    //
    // // Captura acao selecionada pelo usuario
    // string action = "";
    //
    // do {
    //
    //     if (action != "") cout << "Acao '" << action << "' invalida!" << endl << endl;
    //     cout << "Pressione 'e' (para editar) ou 'r' (para remover): ";
    //
    //     char readInput[100];
    //     scanf("%s", &readInput);
    //     action = string(readInput);
    //
    //     if (action == "0") return false;
    //
    // } while (action != "e" && action != "r");
    //
    // const bool remove = (action == "r");
    // const bool update = (action == "e");
    //
    // const string actionStr = (remove) ? "REMOVER" : "EDITAR";
    // cout << "Opcao selecionada: " << actionStr << endl << endl;
    //
    // // Seleciona item sobre o qual a acao sera executada
    // FindResult<SchedulingModel> mPointSearch;
    // string selectionDescMsg = "Informe o codigo do Ponto de Coleta a ser ";
    // selectionDescMsg += (remove) ? "removido" : "editado";
    //
    // do {
    //
    //     const int selectedMPointCode = this->getNumberFromStdIO(selectionDescMsg, "Codigo invalido: ");
    //     if (selectedMPointCode == 0) return false;
    //
    //     mPointSearch = this->dao->findOne(selectedMPointCode);
    //
    //     if (mPointSearch.foundRegister == nullptr) {
    //         cout << "Ponto de Coleta nao encontrado (codigo invalido)" << endl << endl;
    //         const auto tryAgain = this->aksYesOrNoQuestionThroughStdIO("Deseja tentar novamente?");
    //         if (!tryAgain) return false;
    //     }
    //
    // } while (mPointSearch.foundRegister == nullptr);
    //
    // // Executa edicao (se necessario)
    // if (update) return this->update(mPointSearch.foundRegister);
    //
    // // Executa remocao (se necessario)
    // this->dao->deleteOne(mPointSearch.line);
    // cout << "Ponto de Coleta removido com sucesso!" << endl;
    return true;
};

bool SchedulingController::runAction(int action, shared_ptr<UserModel> currentUser) {

    if (action != ControllerActionEnum::CREATE) throw invalid_argument("Acao invalida para controlador de agendamentos");

    try {

        this->getOptionsForScheduling(currentUser->getType() == UserTypeEnum::DONATOR);
        if (!this->create(currentUser)) cout << "Usuario selecionou: 'sair'..." << endl;
        return false;

    } catch (domain_error err) {

        string missingResource = "";

        if ((string)err.what() == "no-meeting-points") {
            missingResource = "Pontos de Coleta";

        } else if ((string)err.what() == "no-donators") {
            missingResource = "Doadores";

        } else if ((string)err.what() == "no-receivers") {
            missingResource = "Receptores";

        } else if ((string)err.what() == "no-reject-types") {
            missingResource = "Tipos de Residuo";
        }

        if (missingResource == "") throw err;

        cout << "Nao eh possivel cadastrar um agendamento, no momento :(" << endl
            << "Nao ha " << missingResource << " disponiveis..." << endl;

        return false;

    } catch (exception err) {
        cout << "Falha inesperada ao tentar Criar Agendamento" << endl;
        exit(1);
    }
};

void SchedulingController::setCurrentSchedulingDate(void) {
    cout << "Informe a data deste agendamento (nao eh validado): ";
    char readInput[100];
    cin.getline(readInput, sizeof(readInput));
    const string answer = string(readInput);
    if (answer!= "0") this->currentScheduling->setDate(answer);
};

void SchedulingController::setCurrentSchedulingMeetingPoint(void) {

    // Confirma intencao
    cout << endl;
    const bool goOn = this->aksYesOrNoQuestionThroughStdIO("Avancar para selecionar Ponto de Coleta?");
    if (!goOn) return;

    // Exibe opcoes disponiveis
    cout << ">> Pontos de Coleta disponiveis: " << endl;
    this->mPointService->showRegistersListData(this->availableMPoints);

    // Captura selecao do usuario
    shared_ptr<MeetingPointModel> selectedMPoint = nullptr;
    int selectedMPointCode;

    do {

        // Captura codigo
        selectedMPointCode = this->getNumberFromStdIO("Informe o codigo do Ponto de Coleta a ser selecionado", "Codigo invalido");
        bool found = false;

        for (uint i = 0; i < this->availableMPoints.size(); i++) {
            const auto currentMpoint = this->availableMPoints[i].foundRegister;
            if (currentMpoint->getCode() != selectedMPointCode) continue;
            found = true;
            selectedMPoint = currentMpoint;
            break;
        }

        if (found) break;

        // Notifica falha
        const bool tryAgain = this->aksYesOrNoQuestionThroughStdIO("Nao existe um Ponto de Coleta com este codigo. Deseja tentar novamente?");
        if (!tryAgain) return;
        cout << endl;

    } while (true);

    // Add Ponto de Coleta
    cout << "Ponto de Coleta selecionado: " << selectedMPoint->getName() << endl;
    this->currentScheduling->setMeetingPointCode(selectedMPointCode);
};

void SchedulingController::setCurrentSchedulingUser(const shared_ptr<UserModel> loggedUser, const bool setDonator) {

    // Define usuario logado como doador (se necessario)
    if (setDonator && loggedUser->getType() == UserTypeEnum::DONATOR) {
        this->currentScheduling->setDonatorCode(loggedUser->getCode());
        return;
    }

    // Define usuario logado como receptor (se necessario)
    if (!setDonator && loggedUser->getType() == UserTypeEnum::RECEIVER) {
        this->currentScheduling->setReceiverCode(loggedUser->getCode());
        return;
    }

    // Confirma intencao
    cout << endl;
    const string schedullingUserType = setDonator ? "Doador" : "Receptor";
    const bool goOn = this->aksYesOrNoQuestionThroughStdIO("Avancar para selecionar " + schedullingUserType + "?");
    if (!goOn) return;

    // Exibe opcoes disponiveis
    cout << ">> " + schedullingUserType + "s disponiveis: " << endl;
    const auto availableUsers = setDonator ? this->availableDonators : this->availableReceivers;
    this->userService->showRegistersListData(availableUsers);

    // Captura selecao do usuario
    shared_ptr<UserModel> selectedUser = nullptr;
    int selectedUserCode;

    do {

        // Captura codigo
        selectedUserCode = this->getNumberFromStdIO("Informe o codigo do " + schedullingUserType + " a ser selecionado", "Codigo invalido");
        bool found = false;

        for (uint i = 0; i < availableUsers.size(); i++) {
            const auto currentUser = availableUsers[i].foundRegister;
            if (currentUser->getCode() != selectedUserCode) continue;
            found = true;
            selectedUser = currentUser;
            break;
        }

        if (found) break;

        // Notifica falha
        const bool tryAgain = this->aksYesOrNoQuestionThroughStdIO("Nao existe um(a) " + schedullingUserType + " com este codigo. Deseja tentar novamente?");
        if (!tryAgain) return;
        cout << endl;

    } while (true);

    // Tudo OK
    cout << schedullingUserType << " selecionado(a): " << selectedUser->getName() << endl;

    if (setDonator) {
        this->currentScheduling->setDonatorCode(selectedUserCode);

    } else {
        this->currentScheduling->setReceiverCode(selectedUserCode);
    }
};

void SchedulingController::setCurrentSchedulingRejectsList(void) {

    // Confirma intencao
    cout << endl;
    const bool goOn = this->aksYesOrNoQuestionThroughStdIO("Avancar para selecionar Lista de Residuos a serem trocados?");
    if (!goOn) return;

    // Exibe opcoes disponiveis
    cout << ">> Tipos de Residuo disponiveis: " << endl;
    this->rejTypeService->showRegistersListData(this->availableRejTypes);

    // Captura selecao do usuario
    vector<shared_ptr<RejectTypeModel>> selectedRejTypes;
    bool repeat = true;

    do {

        // Captura
        const string selectedCodesStr = this->getStringFromStdIO("Insira lista de codigos (separados por virgula): ");

        stringstream ss(selectedCodesStr);
        string item;
        bool error = false;

        while (getline(ss, item, ',')) {

            try {

                // Captura codigo
                const int rejTypeCode = stoi(item);
                bool exists = false;

                for (uint i = 0; i < this->availableRejTypes.size(); i++) {
                    const auto currentRejType = this->availableRejTypes[i].foundRegister;
                    if (currentRejType->getCode() != rejTypeCode) continue;
                    selectedRejTypes.push_back(currentRejType);
                    exists = true;
                    break;
                }

                // Valida
                if (exists) continue;

                cout << "Tipo de Residuo de codigo '" << rejTypeCode << "' nao existe" << endl;
                error = true;

            } catch (exception err) {
                cout << "Valor invalido: '" << item << "'" << endl;
                error = true;
            }
        }

        // Valida
        if (!error && selectedRejTypes.size() > 0) {
            repeat = false;
            continue;
        }

        cout << endl;
        const bool tryAgain = this->aksYesOrNoQuestionThroughStdIO("Lista invalida. Deseja tentar novamente?");
        if (!tryAgain) return;

    } while (repeat);

    // Add tipos de residuo
    cout << "Residuos selecionados: ";

    for (uint i = 0; i < selectedRejTypes.size(); i++) {
        const auto selectedRejType = selectedRejTypes[i];
        this->currentScheduling->addRejectToBeExchangedCode(selectedRejType->getCode());
        if (i > 0) cout << ", ";
        cout << selectedRejType->getName();
    }

    cout << endl;
};

#endif