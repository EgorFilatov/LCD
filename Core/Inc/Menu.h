#ifndef MENU_H_
#define MENU_H_

#include "main.h"
#include <vector>

class Menu {
private:
	Menu *parentMenu;
	std::vector<MenuItem> menuItems;
	uint8_t isCursorEnabled;
	uint8_t cursorPos;
	uint8_t numOfMenuItems;
	uint8_t shiftUp;

public:
	Menu(Menu *parentMenu);
	void showMenuItemsNumbering();
	void showCursor();
	void moveUp();
	void moveDown();
	void moveForward();
	void moveBackward();
	void addMenuItem();
	void deleteMenuItem();
};

#endif /* MENU_H_ */
