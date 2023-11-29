#ifndef LCD_H_
#define LCD_H_

#define E    (1 << 2)         // Бит, по изменению состояния которого считывается информация
#define BACKLIGHT (1 << 3)     // Управление подсветкой

#include "main.h"
#include "menu.h"
#include <cstring>

class LCD {
private:
	I2C_HandleTypeDef *i2cHandle;
	uint8_t lcdAddress;

public:
	LCD();
	uint8_t setCharPos(uint8_t row, uint8_t column);
	uint8_t sendByte(uint8_t byte, uint8_t isCharacter = 0);
	uint8_t sendInstruction(uint8_t instruction);
	uint8_t displayChar(uint8_t character, uint8_t row, uint8_t column);
	uint8_t displayString(char *string, uint8_t row, uint8_t column);
	uint8_t recodeRusChar(char rusChar);
	uint8_t clear();
	void showMenu(Menu menu);
	void showMenuColumn(Menu menu, uint8_t columnsNum);
};

#endif /* LCD_H_ */
