#ifndef _REJECTTYPE_SERVICE_CPP_
#define _REJECTTYPE_SERVICE_CPP_

#include <vector>
#include <map>
#include "../../../../header/module/reject-type/RejectTypeService.h"
#include "../../../../header/common/FindResult.h"

bool RejectTypeService::validateStoredRegister(const vector<string> lineProps) const {

    if (lineProps.size() != 3 && lineProps.size() != 4) return false;

    // Valida codigo
    try { stoi(lineProps[0]); }
    catch (exception err) { return false; }

    // Valida codigo do residuo 'pai' (se necessario)
    if (lineProps.size() == 4) {
        try { stoi(lineProps[3]); }
        catch (exception err) { return false; }
    }

    return true;
};

void RejectTypeService::showRegisterData(const shared_ptr<RejectTypeModel> rejectType) const {

    cout << "|\t" << rejectType->getCode() << "\t"
         << "| " << rejectType->getName() << "\t";

    if (rejectType->getName().size() < 8) cout << "\t";
    if (rejectType->getName().size() < 15) cout << "\t";

    cout << "|";

    if (rejectType->getParentRejType() != nullptr) {
        cout << " " << rejectType->getParentRejType()->getName();
        if (rejectType->getParentRejType()->getName().size() < 22) cout << "\t";
        if (rejectType->getParentRejType()->getName().size() < 15) cout << "\t";
        if (rejectType->getParentRejType()->getName().size() < 8) cout << "\t";
        cout << " | ";

    } else {
        cout << "\t\t\t| ";
    }

    cout << rejectType->getStorageSpecification() << endl;
};

void RejectTypeService::showDataTableHeader(void) const {
    cout << "| Codigo\t|"
         << "\tNome\t\t|"
         << "\tSubtipo de\t|"
         << "\tInstrucao de armazenamento\t\t\t\t|"
         << endl;
};

void RejectTypeService::showRegistersListData(const vector<FindResult<RejectTypeModel>> rejTypesList) const {

    if (!rejTypesList.size()) {
        cout << "Nenhum registro encontrado..." << endl;
        return;
    }

    this->showDataTableHeader();

    for (uint i = 0; i < rejTypesList.size(); i++)
        this->showRegisterData(rejTypesList[i].foundRegister);

    cout << endl;
};

shared_ptr<RejectTypeModel> RejectTypeService::getModelFromStorageLine(const vector<string> lineProps) {

    if (!this->validateStoredRegister(lineProps))
        throw invalid_argument("Tentativa de gerar Tipo de Residuo a partir de dados invalidos");

    auto rejType = make_shared<RejectTypeModel>();
    rejType->setCode(stoi(lineProps[0]));
    rejType->setName(lineProps[1]);
    rejType->setStorageSpecification(lineProps[2]);

    if (lineProps.size() == 4)
        rejType->setParentRejTypeCode(stoi(lineProps[3]));

    return rejType;
};

vector<RejectTypeModel> RejectTypeService::get2RejTypesListIntersection(const vector<RejectTypeModel> list1, const vector<RejectTypeModel> list2) {

    vector<RejectTypeModel> returnList;
    map<int, RejectTypeModel> listOneMap;

    for (uint i = 0; i < list1.size(); i++) {
        const auto rejType = list1[i];
        listOneMap[rejType.getCode()] = rejType;
    }

    for (uint i = 0; i < list2.size(); i++) {
        const auto rejType = list2[i];
        if (listOneMap.find(rejType.getCode()) == listOneMap.end()) continue;
        returnList.push_back(rejType);
    }

    return returnList;
}

vector<int> RejectTypeService::get2RejTypesCodesListIntersection(const vector<int> list1, const vector<int> list2) {

    vector<int> returnList;

    for (uint i = 0; i < list1.size(); i++) {
        for (uint j = 0; j < list2.size(); j++) {
            if (list1[j] != list1[i]) continue;
            returnList.push_back(list1[i]);
            break;
        }
    }

    return returnList;
}

#endif