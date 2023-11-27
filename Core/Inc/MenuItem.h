#ifndef INC_MENUITEM_H_
#define INC_MENUITEM_H_

#include "main.h"
#include <string>

class Menu;// Forward-декларация класса

class MenuItem {
private:
	std::string text;
	uint8_t value;
	Menu *childMenu;

public:
	MenuItem();
	std::string getText();
	void setText(std::string text);
	void get();
};

#endif /* INC_MENUITEM_H_ */
