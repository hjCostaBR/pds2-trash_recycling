#ifndef _DAO_H_
#define _DAO_H_

#include <iostream>
#include "Model.h"

using namespace std;

/**
 * DAO
 * Classes generica a ser extendida por classes que implementem a funcao de DAO no sistema
 * Trash Recycling System
 *
 * @author hjcostabr
 */
class DAO {

protected:

public:

    DAO(void) {};
    ~DAO(void) {};

    /** Encapsula procedimento de inicializacao do controlador. */
    virtual Model insert(const Model model) = 0;
};

#endif