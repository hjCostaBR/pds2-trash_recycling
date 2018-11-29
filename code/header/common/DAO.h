#ifndef _DAO_H_
#define _DAO_H_

#include "IModel.h"

/**
 * DAO
 * Clase generica a ser extendida por classes que implementem a funcao de DAO no sistema
 * Trash Recycling System
 *
 * @author hjcostabr
 */
class DAO {

public:

    DAO(void) {};
    ~DAO(void) {};
    virtual void rename(void) = 0;

    /** Encapsula procedimento de inicializacao do controlador. */
    virtual shared_ptr<IModel> insert(const shared_ptr<IModel> model) {};
};

#endif