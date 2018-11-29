#ifndef _MENU_ITEM_SET_CPP_
#define _MENU_ITEM_SET_CPP_

#include <string>
#include <memory>
#include "../../../header/common/Controller.h"
#include "../../../header/common/MenuItemSet.h"


string MenuItemSet::getMenuString(void) const {
    return this->menuString;
};

shared_ptr<Controller> MenuItemSet::getController(void) const {
    return this->controller;
};

int MenuItemSet::getControllerAction(void) const {
    return this->controllerAction;
}

#endif