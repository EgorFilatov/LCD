#ifndef LCD_H_
#define LCD_H_

#include "main.h"
#include "menu.h"

class LCD {
private:
	I2C_HandleTypeDef *i2cHandle;
	uint8_t deviceAddress;

public:
	LCD();
	void showMenu(Menu menu);
};

#endif /* LCD_H_ */
