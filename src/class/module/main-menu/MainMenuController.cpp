#ifndef _MENU_CONTROLLER_CPP_
#define _MENU_CONTROLLER_CPP_

#include <iostream>
#include "MainMenuController.h"

using namespace std;

void MainMenuController::initialize(void)
{
    cout << "\n> Menu principal";
    
    cout << "\nSelecionar opcao:";
    cout << "\n\t1: Realizar Login;";
    cout << "\n\t2: Cadstra novo usuário;";
    
    string foo;
    cin >> foo;

    cout << "\n\nOpcao informada: " << foo;
}

#endif