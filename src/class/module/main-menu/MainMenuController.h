#ifndef _MENU_CONTROLLER_H_
#define _MENU_CONTROLLER_H_

#include <vector>

#include "../../common/Controller.h"
#include "../../common/PageControllerSet/PageControllerSet.h"

/* 
 * CLASS: INTERFACE
 * Define interface da classe Controller de MENU PRINCIPAL
 * 
 * @author hjcostabr
 */
class MainMenuController: public Controller
{
private:
    vector<PageControllerSet> menuItems;
public:
    MainMenuController(vector<PageControllerSet> menuItems) : menuItems(menuItems) {};
    // ~MainMenuController() {};
    void initialize(void);
};

#endif