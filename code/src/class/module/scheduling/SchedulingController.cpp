#ifndef _SCHEDULING_CONTROLLER_CPP_
#define _SCHEDULING_CONTROLLER_CPP_

#include "../../../../header/module/user/UserModel.h"
#include "../../../../header/module/scheduling/SchedulingController.h"
#include "../../../../header/module/scheduling/SchedulingModel.h"

using namespace std;

bool SchedulingController::create(void) {

    // do {
    //
    //     cout << "> CADASTRO" << endl;
    //     cout << "pressione '0' para sair" << endl << endl;
    //
    //     this->currentScheduling = make_shared<SchedulingModel>();
    //
    //     if (!this->getDataFromStdIo(true)) return false;
    //
    //     try {
    //         this->dao->insert(this->currentScheduling);
    //         cout << "Ponto de Coleta criado com sucesso!" << endl;
    //         return true;
    //
    //     } catch (invalid_argument error) {
    //         cout << endl << "Ops! Dados de Tipo de Residuo invalidos" << endl;
    //
    //     } catch (exception error) {
    //         cout << endl << "Falha inesperada ao tentar adicionar Ponto de Coleta" << endl;
    //     }
    //
    //     if (!this->aksYesOrNoQuestionThroughStdIO("Realizar nova tentativa?")) return false;
    //
    // } while (true);
    return false;
};

bool SchedulingController::getDataFromStdIo(const bool insert) {

    // Captura codigo (se necessario)
    // if (insert) {
    //     int code = this->getNumberFromStdIO("Informe um Codigo para o Ponto de Coleta", "Codigo invalido");
    //     if (!code) return false;
    //     this->currentScheduling->setCode(code);
    // }
    //
    // // Define nome
    // this->setCurrentSchedulingName();
    // if (this->currentScheduling->getName() == "") return false;

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

bool SchedulingController::runAction(int action) {

    // if (action != ControllerActionEnum::CREATE && action != ControllerActionEnum::RETRIVE)
    //     throw invalid_argument("Acao invalida para controlador de pontos de coleta");
    //
    // bool exit = false;
    //
    // switch (action) {
    //     case ControllerActionEnum::CREATE:
    //         exit = !this->create();
    //         break;
    //
    //     case ControllerActionEnum::RETRIVE:
    //         exit = !this->showList();
    //         break;
    // }
    //
    // if (exit) cout << "Usuario selecionou: 'sair'..." << endl;
    return false;
};

void SchedulingController::setCurrentSchedulingName(void) {
    // cout << "Informe nome para o Ponto de Coleta: ";
    // char readInput[100];
    // cin.getline(readInput, sizeof(readInput));
    // if (readInput != "0") this->currentScheduling->setName(string(readInput));
};

#endif