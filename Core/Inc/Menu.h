#ifndef MENU_H_
#define MENU_H_

#include "main.h"
#include <vector>
#include <string>

class Menu {
private:
	Menu *parentMenu;
	std::string header;

	struct MenuItem {
		std::string text { "" };
		uint32_t value { 0 };
		Menu *childMenu { nullptr };
	};

	std::vector<MenuItem> menuItems;
	uint8_t cursorPos;
	uint8_t menuShift;

public:
	Menu(Menu *parentMenu);
	void addMenuItem(std::string text, uint32_t value, Menu *childMenu);
	void showMenuItemsNumbering();
	void showCursor();
	void moveUp();
	void moveDown();
	void moveForward();
	void moveBackward();
	void addMenuItem();
	void deleteMenuItem();
	uint8_t getMenuShift();
	void setMenuShift(uint8_t shiftVal);
	MenuItem getMenuItem(uint8_t num);
	uint8_t getMenuItemsNum();
};

#endif /* MENU_H_ */
