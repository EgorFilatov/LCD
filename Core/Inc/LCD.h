#ifndef LCD_H_
#define LCD_H_

#define E    (1 << 2) // Бит, по изменению состояния которого считывается информация
#define BACKLIGHT (1 << 3) // Управление подсветкой

#include "main.h"
#include "menu.h"
#include <string>
#include <cstring>

class LCD {
private:
	I2C_HandleTypeDef *i2cHandle;
	uint8_t lcdAddress;

public:
	LCD(I2C_HandleTypeDef *i2cHandle, uint8_t lcdAddress);
	void setCharPos(uint8_t row, uint8_t column);
	void sendByte(uint8_t byte, uint8_t isCharacter = 0);
	void sendInstruction(uint8_t instruction);
	void displayChar(uint8_t character, uint8_t row, uint8_t column);
	void displayString(char *string, uint8_t row, uint8_t column);
	void clearChar(uint8_t row, uint8_t column, uint8_t length = 1);
	void clear();
	uint8_t recodeRusChar(char rusChar);
	void showMenu(Menu menu, uint8_t columnsNum = 1);
};

#endif /* LCD_H_ */
