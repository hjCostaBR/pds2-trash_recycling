#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <iostream>

using namespace std;

/**
 * CONTROLLER
 * Classes generica a ser extendida por classes que implementem a funcao de Controlador no sistema
 * Trash Recycling System
 *
 * @author hjcostabr
 */
class Controller {

public:

    /** Encapsula procedimento de inicializacao do controlador. */
    virtual void initialize() = 0;
};

#endif