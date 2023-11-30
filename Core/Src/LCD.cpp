#include "LCD.h"

LCD::LCD(I2C_HandleTypeDef *i2cHandle, uint8_t lcdAddress) :
		i2cHandle(i2cHandle), lcdAddress(lcdAddress) {

	sendInstruction(0b00110000); // 8ми битный интерфейс
	HAL_Delay(40);

	sendInstruction(0b00000010); // ”становка курсора в начале строки
	HAL_Delay(40);

	sendInstruction(0b00001100); // Ќормальный режим работы, выкл курсор
	HAL_Delay(40);

	sendInstruction(0b00000100);
	HAL_Delay(40);

	sendInstruction(0b00000001); // ќчистка диспле€
	HAL_Delay(2);
}

void LCD::setCharPos(uint8_t row, uint8_t column) {
	uint8_t ddramAddrArr[4][20];
	for (uint8_t i = 0; i < 20; i++) {
		ddramAddrArr[0][i] = i;
		ddramAddrArr[1][i] = 64 + i;
		ddramAddrArr[2][i] = 20 + i;
		ddramAddrArr[3][i] = 84 + i;
	}

	uint8_t ddramAddr = ddramAddrArr[row][column];

	uint8_t upperBite = (ddramAddr | 0x80) & 0xF0;
	uint8_t lowerBite = (ddramAddr << 4) & 0xF0;

	uint8_t byteArr[4] { };

	byteArr[0] = upperBite | E;
	byteArr[1] = 0;
	byteArr[2] = lowerBite | E;
	byteArr[3] = 0;

	HAL_I2C_Master_Transmit_DMA(i2cHandle, lcdAddress, byteArr, 4);
	while (i2cHandle->State == HAL_I2C_STATE_BUSY_TX) {
	}
}

void LCD::sendByte(uint8_t byte, uint8_t isCharacter) {
	uint8_t upperBite = byte & 0xF0;
	uint8_t lowerBite = (byte << 4) & 0xF0;

	uint8_t byteArr[4] { };

	byteArr[0] = upperBite | isCharacter | E /*| BACKLIGHT */;
	byteArr[1] = 0;
	byteArr[2] = lowerBite | isCharacter | E /*| BACKLIGHT */;
	byteArr[3] = 0;

	HAL_I2C_Master_Transmit_DMA(i2cHandle, lcdAddress, byteArr, 4);
	while (i2cHandle->State == HAL_I2C_STATE_BUSY_TX) {
	}
}

void LCD::sendInstruction(uint8_t instruction) {
	sendByte(instruction);
}

void LCD::displayChar(uint8_t character, uint8_t row, uint8_t column) {
	setCharPos(row, column);
	sendByte(recodeRusChar(character), 1);
}

void LCD::displayString(char *string, uint8_t row, uint8_t column) {
	setCharPos(row, column);
	while (*string) {
		sendByte(recodeRusChar(*string), 1);
		++string;
	}
}

void LCD::clearChar(uint8_t row, uint8_t column, uint8_t length) {
	for (uint8_t i = 0; i < length; ++i) {
		displayChar(128, row, column + i);
	}
}

void LCD::clear() {
	uint8_t byteArr[4] { 4, 0, 20, 0 };

	HAL_I2C_Master_Transmit_DMA(i2cHandle, lcdAddress, byteArr, 4);
	while (i2cHandle->State == HAL_I2C_STATE_BUSY_TX) {
	}
}

uint8_t LCD::recodeRusChar(char character) {
	const char *rusAlphabetLower = "абвгдеЄжзийклмнопрстуфхцчшщъыьэю€";
	const char *rusAlphabetUpper = "јЅ¬√ƒ≈®∆«»… ЋћЌќѕ–—“”‘’÷„ЎўЏџ№Ёёя";

	uint8_t lcdCodesLower[] = { 'a', 0xB2, 0xB3, 0xB4, 0xE3, 'e', 0xB5, 0xB6,
			0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 'o', 0xBE, 'p', 'c', 0xBF,
			'y', 0xE4, 'x', 0xE5, 0xC0, 0xC1, 0xE6, 0xC2, 0xC3, 0xC4, 0xC5,
			0xC6, 0xC7 };

	uint8_t lcdCodesUpper[] = { 'A', 0xA0, 'B', 0xA1, 0xE0, 'E', 0xA2, 0xA3,
			0xA4, 0xA5, 0xA6, 'K', 0xA7, 'M', 'H', 'O', 0xA8, 'P', 'C', 'T',
			0xA9, 0xAA, 'X', 0xE1, 0xAB, 0xAC, 0xE2, 0xAD, 0xAE, 'b', 0xAF,
			0xB0, 0xB1 };

	char *rusCharPtr;
	rusCharPtr = strchr(rusAlphabetLower, character);
	if (rusCharPtr != nullptr) {
		return lcdCodesLower[rusCharPtr - rusAlphabetLower];
	}

	rusCharPtr = strchr(rusAlphabetUpper, character);
	if (rusCharPtr != nullptr) {
		return lcdCodesUpper[rusCharPtr - rusAlphabetUpper];
	}
	return character;
}

void LCD::showMenu(Menu menu, uint8_t columnsNum) {
	for (uint8_t i = 0; i < 4; ++i) {
		displayString(&menu.getMenuItem(i).text[0], i, 0);
	}
}


