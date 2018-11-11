#ifndef _MENU_CONTROLLER_CPP_
#define _MENU_CONTROLLER_CPP_

#include <iostream>
#include "MenuController.h"

using namespace std;

// Valida 01 opcao do menu selecionada
bool MenuController::isSelectedItemValid(int selectedCode)
{
    int actualValue = (selectedCode - 1);
    return (actualValue >= 0 && actualValue < this->menuItems.size());
}

// Exibe opcoes de 01 menu
void MenuController::showMenuOptions(void)
{
    cout << ">> Opcoes Disponiveis:" << endl;

    for (int i = 0; i < this->menuItems.size(); i++) {
        cout << "\t- " << (i + 1) << " " << this->menuItems[i].getMenuString() << endl;
    }

    cout << endl;
}

// Incializa a exibicao de 01 menu
void MenuController::initialize(void)
{
    // Exibe menu
    cout << "> " << this->name << endl;
    
    bool tried = false;
    string readInput;
    int selectedOption;

    do {

        // Notifica tentativa invalida (se necessario)
        if (tried) {
            cout << "Opção invalida '" << readInput << "'!" << endl << endl;

        } else {
            tried = true;
        }

        // Captura selecao de 01 item do menu
        this->showMenuOptions();
        cin >> readInput;

        try {
            selectedOption = stoi(readInput);

        } catch(exception error) {
            selectedOption = -1;
        }

    } while (!this->isSelectedItemValid(selectedOption));

    // Tudo OK
    cout << endl << "Opcao selecionada: " << selectedOption << endl;
}

#endif