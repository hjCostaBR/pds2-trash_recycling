#ifndef _SCHEDULLING_SERVICE_H_
#define _SCHEDULLING_SERVICE_H_

#include <string>
#include <memory>
#include <vector>
#include "../../common/interface/IService.h"
#include "../../common/FindResult.h"
#include "../../common/enums.h"
#include "SchedulingModel.h"

using namespace std;

class SchedulingService: IService {

public:

    SchedulingService(void) {};

    /**
     * @inherit
     */
    bool validateStoredRegister(const vector<string> lineProps) const override;

    /**
     * @inherit
     */
    virtual void showRegisterData(const shared_ptr<SchedulingModel> register) const;

    /**
     * Monta & Exibe 01 tabela listando dados de varios registros.
     * @param scheduling Itens a serem exibidos.
     */
    void showRegistersListData(const vector<FindResult<SchedulingModel>> scheduling) const;

    /**
     * @inherit
     */
    shared_ptr<SchedulingModel> getModelFromStorageLine(const vector<string> lineProps);

    /** Exibe cabecalho para exibicao tabular de dados. */
    void showDataTableHeader(void) const;
};

#endif