#ifndef _REJECTTYPE_SERVICE_H_
#define _REJECTTYPE_SERVICE_H_

#include <string>
#include <memory>
#include <vector>
#include "../user/UserModel.h"
#include "../../common/interface/IService.h"
#include "../../common/FindResult.h"
#include "../../common/enums.h"

using namespace std;

class RejectTypeService: IService {

public:

    /** Construtor */
    RejectTypeService(void) {};

    /**
     * @inherit
     */
    bool validateStoredRegister(const vector<string> lineProps) const override;

    /**
     * @inherit
     */
    virtual void showRegisterData(const shared_ptr<RejectTypeModel> register) const;

    /**
     * Monta & Exibe 01 tabela listando dados de varios registros.
     * @param rejTypesList Itens a serem exibidos.
     */
    void showRegistersListData(const vector<FindResult<RejectTypeModel>> rejTypesList) const;

    /**
     * @inherit
     */
    shared_ptr<RejectTypeModel> getModelFromStorageLine(const vector<string> lineProps);

    /** Exibe cabecalho para exibicao tabular de dados. */
    void showDataTableHeader(void) const;

    /**
     * Analisa 02 listas de tipos de residuo & retorna a intersecao entre elas.
     *
     * @param list1
     * @param list2
     * @return
     */
    vector<RejectTypeModel> get2RejTypesListIntersection(const vector<RejectTypeModel> list1, const vector<RejectTypeModel> list2);

    /**
     * Analisa 02 listas de codigos de tipos de residuo & retorna a intersecao entre elas.
     *
     * @param list1
     * @param list2
     * @return
     */
    vector<int> get2RejTypesCodesListIntersection(const vector<int> list1, const vector<int> list2);
};

#endif
