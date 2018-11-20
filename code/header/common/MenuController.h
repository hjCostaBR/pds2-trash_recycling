#ifndef _MENU_CONTROLLER_H_
#define _MENU_CONTROLLER_H_

#include <vector>

#include "Controller.h"
#include "PageControllerSet.h"

/* 
 * CLASS: INTERFACE
 * Define interface da classe Controller de MENU no sistema
 * Trash Recycling System
 * 
 * @author hjcostabr
 */
class MenuController: public Controller
{
private:
    string name;
    vector<PageControllerSet> menuItems;
public:
    MenuController(string name, vector<PageControllerSet> menuItems) :
        name(name),
        menuItems(menuItems){};

    void initialize(void);
    bool isSelectedItemValid(int selectedCode);
    void showMenuOptions(void);
};

#endif