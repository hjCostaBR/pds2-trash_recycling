#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <iostream>

using namespace std;

class Controller
{
public:
    Controller(void) {};
    ~Controller() {};

    virtual void initialize() = 0;
};

#endif