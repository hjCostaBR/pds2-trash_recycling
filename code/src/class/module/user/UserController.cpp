#ifndef _USER_CONTROLLER_CPP_
#define _USER_CONTROLLER_CPP_

#include <memory>
#include <functional>
#include "../../../../header/module/user/UserController.h"
#include "../../../../header/module/user/UserModel.h"
#include "../../../enum/ControllerActionEnum.cpp"

using namespace std;

UserModel UserController::getDataToCreateUser(void) const {

    cout << "foo" << endl;

    UserModel user = UserModel();
    int code = this->getNumberFromStdIO("Informe um Codigo para o usuario", "Codigo invalido");

    // string cpfCnpj;
    // int type;
    // string name;
    // vector<RejectTypeModel> rejectTypesOfInterest;

    return user;
}

void UserController::initialize(void) {
    throw bad_function_call();
};

void UserController::initialize(int action) {

    switch (action) {
        case ControllerActionEnum::CREATE:
            this->getDataToCreateUser();
            break;

        case ControllerActionEnum::DEFAULT:
        default:
            this->initialize();
            break;
    }
};

#endif