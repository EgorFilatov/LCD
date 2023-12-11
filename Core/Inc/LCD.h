#ifndef LCD_H_
#define LCD_H_

#define E    (1 << 2) // Бит, по изменению состояния которого считывается информация
#define BACKLIGHT (1 << 3) // Управление подсветкой

#define I2C_READY 0
#define I2C_BUSY 1

#include "main.h"
#include "menu.h"
#include <string>
#include <cstring>

extern uint8_t i2cMasterTxFlag;

class LCD {
private:
	I2C_HandleTypeDef *i2cHandle;
	uint8_t lcdAddress;
	uint8_t columnsNum;

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
	void displayMenu(Menu menu, uint8_t columnsNum = 1);
	I2C_HandleTypeDef* getI2cHandle();
	uint8_t getColumnsNum();
};

#endif /* LCD_H_ */
