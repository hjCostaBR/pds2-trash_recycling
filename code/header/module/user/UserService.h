#ifndef _USER_SERVICE_H_
#define _USER_SERVICE_H_

#include <string>
#include <memory>
#include "../../module/user/UserModel.h"
#include "../../common/interface/IService.h"
#include "../../common/enums.h"

using namespace std;

class UserService: IService {

public:
    UserService(void) {};

    /**
     * @inherit
     */
    bool validateStoredRegister(const vector<string> lineProps) const override;

    /**
     * @inherit
     */
    virtual void showRegisterData(const shared_ptr<UserModel> register) const;

    /**
     * Informa se 01 usuario eh PJ ou PJ.
     *
     * @param cpfCnpj Documento cadastrado do usuario.
     * @return
     */
    PersonTypeEnum getUserPersonType(const string cpfCnpj) const;

    /**
     * Verifica se 01 valor corresopnde a 01 tipo valido de usuario.
     * @param type
     * @return
     */
    bool validateUserType(const int type) const;

    /**
     * Gera & retorna label para exibicao de 01 tipo de usuario.
     * @param typeCode Codigo do tipo
     * @return Label
     */
    string getUserTypeLabel(const UserTypeEnum typeCode) const;
};

#endif