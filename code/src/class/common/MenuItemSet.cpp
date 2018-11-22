#ifndef _PAGE_SET_CPP_
#define _PAGE_SET_CPP_

#include <string>
#include <memory>
#include "../../../header/common/Controller.h"
#include "../../../header/common/MenuItemSet.h"


string MenuItemSet::getMenuString(void) {
    return this->menuString;
};

shared_ptr<Controller> MenuItemSet::getController(void) {
    return this->controller;
};

#endif