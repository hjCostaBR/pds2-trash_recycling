#ifndef _PAGE_SET_H_
#define _PAGE_SET_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "../Controller.h"

using namespace std;

class PageControllerSet
{
private:
    string menuString;
    Controller *controller;
public:
    PageControllerSet(string menuString, Controller* controller) : menuString(menuString), controller(controller) {};
  //   ~PageControllerSet();
    string getMenuString();
    Controller* getController();
};

#endif