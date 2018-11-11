
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "class/module/menu/MenuController.cpp"
#include "class/common/PageControllerSet/PageControllerSet.cpp"

using namespace std;

/**
 * MAIN
 * Arquivo principal do sistema
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
    menuItems.push_back(PageControllerSet("Login", NULL));

    MenuController menuController("Menu Principal", menuItems);
    menuController.initialize();

    // Fim da execucao
    cout << endl << "FIM" << endl;
    return 0;
}