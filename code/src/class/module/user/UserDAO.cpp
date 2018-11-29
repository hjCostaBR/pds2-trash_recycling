#ifndef _USER_DAO_CPP_
#define _USER_DAO_CPP_

#include <memory>
#include "../../../../header/module/user/UserDAO.h"

using namespace std;

shared_ptr<UserModel> UserDAO::insert(const shared_ptr<UserModel> model) {
    auto foo = make_shared<UserModel>();
    return foo;
}

#endif