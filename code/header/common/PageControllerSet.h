#ifndef _PAGE_SET_H_
#define _PAGE_SET_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>

#include "Controller.h"

using namespace std;

class PageControllerSet
{
private:
    string menuString;
    shared_ptr<Controller> controller;

public:
    PageControllerSet(string menuString, shared_ptr<Controller> controller)
        : menuString(menuString), controller(controller)
        {};

    string getMenuString();
    shared_ptr<Controller> getController();
};

#endif