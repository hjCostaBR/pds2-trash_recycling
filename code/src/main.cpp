#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <memory>

#include "../header/common/MenuItemSet.h"
#include "../header/common/Controller.h"
#include "../header/common/MenuController.h"
#include "../header/module/login/LoginController.h"
#include "../header/module/user/UserController.h"
#include "../src/enum/ControllerActionEnum.cpp"

using namespace std;

/**
 * MAIN
 * Funcao principal do sistema
 * Trash Recycling System
 * 
 * @author hjcostabr
 */
int main(int argc, char const *argv[]) {

    // Cabecalho
    cout << endl
         << "-- SISTEMA DE CONTROLE DE RECICLAGEM DE LIXO --"
         << endl << endl;

    // Exibir menu principal
    vector<MenuItemSet> menuItems;

    menuItems.push_back(MenuItemSet("Login", make_shared<LoginController>()));
    menuItems.push_back(MenuItemSet("Cadastro", make_shared<UserController>()), (int)ControllerActionEnum::CREATE);
    menuItems.push_back(MenuItemSet("Sair", nullptr));
    
    MenuController menuController("Menu Principal", menuItems);
    menuController.initialize();

    // Fim da execucao
    cout << endl << "FIM" << endl;
    return 0;
}