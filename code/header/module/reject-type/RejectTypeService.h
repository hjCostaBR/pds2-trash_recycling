#ifndef _REJECTTYPE_SERVICE_H_
#define _REJECTTYPE_SERVICE_H_

#include <string>
#include <memory>
#include "../user/UserModel.h"
#include "../../common/interface/IService.h"
#include "../../common/enums.h"

using namespace std;

class RejectTypeService: IService {

public:
    RejectTypeService(void) {};

    /**
     * @inherit
     */
    bool validateStoredRegister(const vector<string> lineProps) const override;

    /**
     * @inherit
     */
    virtual void showRegisterData(const shared_ptr<RejectTypeModel> register) const;
};

#endif
