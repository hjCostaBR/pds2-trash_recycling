#ifndef _SERVICE_H_
#define _SERVICE_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * SERVICO
 * Interface a ser implementada por classes que implementem a funcao de SERVICO no sistema
 * Trash Recycling System
 *
 * @author hjcostabr
 */
class IService {

public:
    IService(void) {};
    ~IService(void) {};

    /**
     * Informa se dados contidos numa linha do arquivo de armazenamento correspondem a 01 registro valido.
     *
     * @param lineProps
     * @return
     */
    virtual bool validateStoredRegister(const vector<string> lineProps) const = 0;
};

#endif