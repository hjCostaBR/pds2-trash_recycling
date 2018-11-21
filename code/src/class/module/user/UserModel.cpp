// #ifndef _USER_MODEL_H_
// #define _USER_MODEL_H_
//
// #include <string>
// #include <vector>
//
// #include "../reject-type/RejectTypeModel.cpp"
// #include "../../enum/UserTypeEnum.cpp"
//
// using namespace std;
//
// class UserModel
// {
// private:
//     int code;
//     string cpfCnpj;
//     UserTypeEnum type;
//     string name;
//     vector<RejectTypeModel> rejectTypesOfInterest;
//
// public:
//     UserModel(void){};
//     // ~UserModel() {};
//
//     // Codigo
//     void setCode(int code);
//     int getCode(void);
//
//     // Cpf/Cnpj
//     void setCpfCnpj(string code);
//     string getCpfCnpj(void);
//
//     // Tipo
//     void setType(UserTypeEnum type);
//     UserTypeEnum getType(void);
//
//     // Nome
//     void setName(string name);
//     string getName(void);
//
//     // Lista de Residuos
//     void resetRejectTypesOfInterest(void);
//     void addRejectTypeOfInterest(RejectTypeModel rejectType);
//     vector<RejectTypeModel> getRejectTypesOfInterest(void);
// };
//
// #endif