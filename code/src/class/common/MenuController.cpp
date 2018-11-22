#ifndef _MENU_CONTROLLER_CPP_
#define _MENU_CONTROLLER_CPP_

#include <iostream>
#include "../../../header/common/MenuController.h"

using namespace std;

bool MenuController::isSelectedItemValid(int selectedCode) {
    return (selectedCode >= 0 && selectedCode < this->menuItems.size());
}

void MenuController::showMenuOptions(void) {

    cout << ">> Opcoes Disponiveis:" << endl;

    for (int i = 0; i < this->menuItems.size(); i++) {
        cout << "\t- " << (i + 1) << " " << this->menuItems[i].getMenuString() << endl;
    }

    cout << endl;
}

shared_ptr<Controller> MenuController::showOptionsAndGetSelectedController(void) {

    bool tried = false;
    string readInput;
    int selectedOptionCode;

    do {

        // Notifica tentativa invalida (se necessario)
        if (tried) cout << "Opção invalida '" << readInput << "'!" << endl << endl;
        tried = true;

        // Exibe menu
        cout << "> " << this->name << endl;
        this->showMenuOptions();

        // Captura selecao de 01 item do menu
        cin >> readInput;

        try {
            selectedOptionCode = (stoi(readInput) - 1);

        } catch(exception error) {
            selectedOptionCode = -1;
        }

    } while (!this->isSelectedItemValid(selectedOptionCode));

    // Exibe opcao selecionada
    PageControllerSet selectedOption = this->menuItems[selectedOptionCode];

    cout << endl
         << "Opcao selecionada: "
         << selectedOption.getMenuString() << endl
         << endl;

    // Retorna controller da opcao selecionada
    return selectedOption.getController();
}

void MenuController::initialize(void) {

    shared_ptr<Controller> selectedItemController = nullptr;

    do {

        selectedItemController = this->showOptionsAndGetSelectedController();

        if (selectedItemController != nullptr) {
            selectedItemController->initialize();
            cout << endl;
        }

    } while (selectedItemController != nullptr);
}

#endif
