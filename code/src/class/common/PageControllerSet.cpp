#ifndef _PAGE_SET_CPP_
#define _PAGE_SET_CPP_

#include <string>
#include <memory>
#include "../../../header/common/Controller.h"
#include "../../../header/common/PageControllerSet.h"


string PageControllerSet::getMenuString(void) {
    return this->menuString;
};

shared_ptr<Controller> PageControllerSet::getController(void) {
    return this->controller;
};

#endif