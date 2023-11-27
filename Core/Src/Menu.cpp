#include "Menu.h"

//Menu::Menu() {
//}

void Menu::addMenuItem(std::string text, uint8_t value, Menu *childMenu) {
	menuItems.resize(menuItems.size() + 1);
	menuItems[menuItems.size() - 1].text = text;
	menuItems[menuItems.size() - 1].value = value;
	menuItems[menuItems.size() - 1].childMenu = childMenu;
}

void Menu::showMenuItemsNumbering() {

}




