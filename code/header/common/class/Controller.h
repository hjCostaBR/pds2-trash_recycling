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

protected:

    /** Codigo da acao do controller a ser realizada. */
    int action;


    /**
     * Interage com o usuario via cli para capturar 01 valor numerico.
     *
     * @param presentationMsg Mensagem de descricao do proposito do numero obtido.
     * @param invalidInputMsg Mensagem para caso de insercao de valor invalido.
     * @return Valor numerico valido obtido.
     */
    int getNumberFromStdIO(string presentationMsg, string invalidInputMsg) const;

public:

    Controller(void) {};
    ~Controller(void) {};

    /**
     * Encapsula procedimento de inicializacao do controlador.
     * @return Flag: Se execucao do programa do programa deve ser encerrada.
     */
    virtual bool runAction() = 0;

    /**
     * Encapsula procedimento de inicializacao do controlador.
     *
     * @param action Codigo da acao do controller a ser realizada.
     * @return Flag: Se execucao do programa do programa deve ser encerrada.
     */
    virtual bool runAction(int action) = 0;
};

#endif