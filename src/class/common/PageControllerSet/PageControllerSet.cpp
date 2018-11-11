#ifndef _PAGE_SET_CPP_
#define _PAGE_SET_CPP_

#include "../Controller.h"

string PageControllerSet::getMenuString(void)
{
    return this->menuString;
};

Controller* PageControllerSet::getController(void)
{
    return this->controller;
};

#endif