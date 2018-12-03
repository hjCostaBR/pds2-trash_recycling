#ifndef _SCHEDULLING_SERVICE_CPP_
#define _SCHEDULLING_SERVICE_CPP_

#include <vector>
#include "../../../../header/module/scheduling/SchedulingModel.h"
#include "../../../../header/module/scheduling/SchedulingService.h"
#include "../../../../header/common/FindResult.h"

bool SchedulingService::validateStoredRegister(const vector<string> lineProps) const {

    if (lineProps.size() != 6) return false;

    // Valida codigos de: Ponto de Coleta, Doador & Receptor
    for (int i = 1; i <= 5; i++) {
        if (i == 4) continue;
        try { stoi(lineProps[i]); }
        catch (exception err) { return false; }
    }

    // Valida flag Concluido?
    int done = stoi(lineProps[5]);
    if (done != 0 && done != 1) return false;

    return true;
};

void SchedulingService::showRegisterData(const shared_ptr<SchedulingModel> scheduling) const {

    // Captura relacionamentos
    const auto mPointSearch = this->mPointDao->findOne(scheduling->getMeetingPointCode());
    const auto mPoint = mPointSearch.foundRegister;
    if (mPoint == nullptr) throw domain_error("meeting-point");

    const auto donatorSearch = this->userDao->findOne(scheduling->getDonatorCode());
    const auto donator = donatorSearch.foundRegister;
    if (donator == nullptr) throw domain_error("donator");

    const auto receiverSearch = this->userDao->findOne(scheduling->getReceiverCode());
    const auto receiver = receiverSearch.foundRegister;
    if (receiver == nullptr) throw domain_error("receiver");

    const string doneFlagValue = scheduling->isDone() ? "Realizado" : "Nao Realizado";

    // Exibe dados
    cout << "|\t" << scheduling->getDate() << "\t|"
         << " " << mPoint->getName() << "\t|"
         << " " << donator->getName() << "\t|"
         << " " << receiver->getName() << "\t|";
         << " " << doneFlagValue << "\t|"
         << endl;

    // const vector<RejectTypeModel> rejTypes;

    // for (uint i = 0; i < scheduling->getRejectsToBeExchangedCodes().size(); i++) {
    //     const auto rejTypeSearch = this->rejTypeDao->findOne(scheduling->getRejectsToBeExchangedCodes());
    //     const auto currentRejType = rejTypeSearch.foundRegister;
    //     if (currentRejType == nullptr) throw domain_error("reject-type");
    //     rejTypes.push_back(currentRejType);
    // }
};

void SchedulingService::showDataTableHeader(void) const {
    cout << "|\tData\t|"
         << "\tDoador\t|"
         << "\tReceptor\t|"
         << "\tRealizado?\t|"
         << endl;
};

void SchedulingService::showRegistersListData(const vector<FindResult<SchedulingModel>> schedulingList) const {

    if (!schedulingList.size()) {
        cout << "Nenhum registro encontrado..." << endl;
        return;
    }

    this->showDataTableHeader();

    for (uint i = 0; i < schedulingList.size(); i++) {
        this->showRegisterData(schedulingList[i].foundRegister);
    }

    cout << endl;
};

shared_ptr<SchedulingModel> SchedulingService::getModelFromStorageLine(const vector<string> lineProps) {

    if (!this->validateStoredRegister(lineProps))
        throw invalid_argument("Tentativa de gerar Agendamento a partir de dados invalidos");

    // auto scheduling = make_shared<SchedulingModel>();
    // scheduling->setCode(stoi(lineProps[0]));
    // scheduling->setName(lineProps[1]);
    // return scheduling;
    return nullptr;
};

#endif
