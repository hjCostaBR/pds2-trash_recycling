#ifndef _USER_MODEL_H_
#define _USER_MODEL_H_

#include <string>
#include <vector>

#include "../reject-type/RejectTypeModel.h"

using namespace std;

class UserModel
{
private:
    int code;
    string cpfCnpj;
    int type;
    string name;
    vector<RejectTypeModel> rejectTypesOfInterest;

public:
    UserModel(void) {};

    // Codigo
    void setCode(int code);
    int getCode(void);

    // Cpf/Cnpj
    void setCpfCnpj(string code);
    string getCpfCnpj(void);

    // Tipo
    void setType(int type);
    int getType(void);

    // Nome
    void setName(string name);
    string getName(void);

    // Lista de Residuos
    void resetRejectTypesOfInterest(void);
    void addRejectTypeOfInterest(RejectTypeModel rejectType);
    vector<RejectTypeModel> getRejectTypesOfInterest(void);
};

#endif