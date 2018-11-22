#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <memory>

#include "../header/common/PageControllerSet.h"
#include "../header/common/Controller.h"
#include "../header/common/MenuController.h"
#include "../header/module/login/LoginController.h"

using namespace std;

/**
 * MAIN
 * Funcao principal do sistema
 * Trash Recycling System
 * 
 * @author hjcostabr
 */
int main(int argc, char const *argv[])
{
    // Cabecalho
    cout << endl
         << "-- SISTEMA DE CONTROLE DE RECICLAGEM DE LIXO --"
         << endl << endl;

    // Exibir menu principal
    vector<PageControllerSet> menuItems;

    menuItems.push_back(PageControllerSet("Login", make_shared<LoginController>()));
    menuItems.push_back(PageControllerSet("Sair", nullptr));
    
    MenuController menuController("Menu Principal", menuItems);
    menuController.initialize();

    // Fim da execucao
    cout << endl << "FIM" << endl;
    return 0;
}