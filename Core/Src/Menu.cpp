#include "Menu.h"

Menu::Menu(Menu *parentMenu):
parentMenu(parentMenu), header(""), cursorPos(0), menuShift(0) {
}

void Menu::addMenuItem(std::string text, uint32_t value, Menu *childMenu) {
	menuItems.resize(menuItems.size() + 1);
	menuItems[menuItems.size() - 1].text = text;
	menuItems[menuItems.size() - 1].value = value;
	menuItems[menuItems.size() - 1].childMenu = childMenu;
}

void Menu::showMenuItemsNumbering() {
	if (cursorPos) {
		for (uint8_t i = 0; i < menuItems.size(); ++i) {
			menuItems[i].text.erase(0, 1);
			menuItems[i].text = std::to_string(i + 1) + "." + menuItems[i].text;
		}
		cursorPos = 1;
		for (uint8_t i = 1; i < menuItems.size(); ++i) {
			menuItems[i].text = " " + menuItems[i].text;
		}
		menuItems[0].text = ">" + menuItems[0].text;
	} else {
		for (uint8_t i = 0; i < menuItems.size(); ++i) {
			menuItems[i].text = std::to_string(i + 1) + "." + menuItems[i].text;
		}
	}
}

void Menu::showCursor() {
	if (!cursorPos) {
		cursorPos = 1;
		for (uint8_t i = 1; i < menuItems.size(); ++i) {
			menuItems[i].text = " " + menuItems[i].text;
		}
		menuItems[0].text = ">" + menuItems[0].text;
	}
}

void Menu::moveUp() {
	if (cursorPos) {
		menuItems[cursorPos - 1].text = " " + menuItems[cursorPos - 1].text.erase(0);
		menuItems[cursorPos].text = ">" + menuItems[cursorPos].text.erase(0);
		++cursorPos;
	} else {
		menuShift += 4;
	}
}

Menu::MenuItem Menu::getMenuItem(uint8_t num) {
	return menuItems[num];
}

uint8_t Menu::getMenuShift() {
	return menuShift;
}

uint8_t Menu::getMenuItemsNum() {
	return menuItems.size();
}





