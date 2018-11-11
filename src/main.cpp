
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "class/module/main-menu/MainMenuController.cpp"
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
    cout << endl
         << "-- SISTEMA DE CONTROLE DE RECICLAGEM DE LIXO --"
         << endl;

    vector<PageControllerSet> menuItems;
    // menuItems.pushBack(pageControllerSet())

    MainMenuController menuController(menuItems);
    menuController.initialize();

    cout << endl << "FIM" << endl;

    return 0;
}