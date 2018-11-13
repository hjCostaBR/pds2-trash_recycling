
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "class/common/MenuController/MenuController.cpp"
#include "class/common/PageControllerSet/PageControllerSet.cpp"
#include "class/module/login/LoginController/LoginController.cpp"

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
    
    menuItems.push_back(PageControllerSet("Login", new LoginController()));
    menuItems.push_back(PageControllerSet("Sair", NULL));
    
    MenuController menuController("Menu Principal", menuItems);
    menuController.initialize();

    // Fim da execucao
    cout << endl << "FIM" << endl;
    return 0;
}