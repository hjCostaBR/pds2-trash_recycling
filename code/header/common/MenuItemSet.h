#ifndef _PAGE_SET_H_
#define _PAGE_SET_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>

#include "Controller.h"
#include "enums.h"

using namespace std;

/**
 * Define 01 'set' que padroniza 01 conjunto de parametros que, juntos, servem
 * para gerar 01 opcao dentro de 01 menu no sistema
 * Trash Recycling System
 *
 * @author hjcostabr
 */
class MenuItemSet {

private:

    /** Titulo/nome do item de menu. */
    string menuString;

    /** Controller associado ao item de menu. */
    shared_ptr<Controller> controller;

    /** Codigo da action do controller a ser executada (associada ao item de Menu). */
    int controllerAction;

public:

    /**
     * Construtor.
     *
     * @param menuString Titulo/nome do item de menu.
     * @param controller Controller associado ao item de menu.
     */
    MenuItemSet(const string menuString, const shared_ptr<Controller> controller)
        : menuString(menuString), controller(controller)
        {};

    /**
     * Construtor.
     *
     * @param menuString Titulo/nome do item de menu.
     * @param controller Controller associado ao item de menu.
     * @param controllerAction Codigo da action do controller a ser executada (associada ao item de Menu).
     */
    MenuItemSet(const string menuString, const shared_ptr<Controller> controller, const ControllerActionEnum controllerAction)
        : menuString(menuString), controller(controller), controllerAction(controllerAction)
        {};

    string getMenuString(void) const;
    shared_ptr<Controller> getController(void) const;
    int getControllerAction(void) const;
};

#endif