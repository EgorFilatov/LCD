#include <lcd_i2c_lib.h>

uint8_t i2cLcdState { };

char *recodeCyr(char *charCyr) {
	if (*charCyr == 'À') {
		*charCyr = 'A';
	} else if (*charCyr == 'à') {
		*charCyr = 'a';
	} else if (*charCyr == 'Á') {
		*charCyr = 0b10100000;
	} else if (*charCyr == 'á') {
		*charCyr = 0b10110010;
	} else if (*charCyr == 'Â') {
		*charCyr = 'B';
	} else if (*charCyr == 'â') {
		*charCyr = 0b10110011;
	} else if (*charCyr == 'Ã') {
		*charCyr = 0b10100001;
	} else if (*charCyr == 'ã') {
		*charCyr = 0b10110100;
	} else if (*charCyr == 'Ä') {
		*charCyr = 0b11100000;
	} else if (*charCyr == 'ä') {
		*charCyr = 0b11100011;
	} else if (*charCyr == 'Å') {
		*charCyr = 'E';
	} else if (*charCyr == 'å') {
		*charCyr = 'e';
	} else if (*charCyr == '¨') {
		*charCyr = 0b10100010;
	} else if (*charCyr == '¸') {
		*charCyr = 0b10110101;
	} else if (*charCyr == 'Æ') {
		*charCyr = 0b10100011;
	} else if (*charCyr == 'æ') {
		*charCyr = 0b10110110;
	} else if (*charCyr == 'Ç') {
		*charCyr = 0b10100100;
	} else if (*charCyr == 'ç') {
		*charCyr = 0b10110111;
	} else if (*charCyr == 'È') {
		*charCyr = 0b10100101;
	} else if (*charCyr == 'è') {
		*charCyr = 0b10111000;
	} else if (*charCyr == 'É') {
		*charCyr = 0b10100110;
	} else if (*charCyr == 'é') {
		*charCyr = 0b10111001;
	} else if (*charCyr == 'Ê') {
		*charCyr = 'K';
	} else if (*charCyr == 'ê') {
		*charCyr = 0b10111010;
	} else if (*charCyr == 'Ë') {
		*charCyr = 0b10100111;
	} else if (*charCyr == 'ë') {
		*charCyr = 0b10111011;
	} else if (*charCyr == 'Ì') {
		*charCyr = 'M';
	} else if (*charCyr == 'ì') {
		*charCyr = 0b10111100;
	} else if (*charCyr == 'Í') {
		*charCyr = 'H';
	} else if (*charCyr == 'í') {
		*charCyr = 0b10111101;
	} else if (*charCyr == 'Î') {
		*charCyr = 'O';
	} else if (*charCyr == 'î') {
		*charCyr = 'o';
	} else if (*charCyr == 'Ï') {
		*charCyr = 0b10101000;
	} else if (*charCyr == 'ï') {
		*charCyr = 0b10111110;
	} else if (*charCyr == 'Ð') {
		*charCyr = 'P';
	} else if (*charCyr == 'ð') {
		*charCyr = 'p';
	} else if (*charCyr == 'Ñ') {
		*charCyr = 'C';
	} else if (*charCyr == 'ñ') {
		*charCyr = 'c';
	} else if (*charCyr == 'Ò') {
		*charCyr = 'T';
	} else if (*charCyr == 'ò') {
		*charCyr = 0b10111111;
	} else if (*charCyr == 'Ó') {
		*charCyr = 0b10101001;
	} else if (*charCyr == 'ó') {
		*charCyr = 'y';
	} else if (*charCyr == 'Ô') {
		*charCyr = 0b10101010;
	} else if (*charCyr == 'ô') {
		*charCyr = 0b11100100;
	} else if (*charCyr == 'Õ') {
		*charCyr = 'X';
	} else if (*charCyr == 'õ') {
		*charCyr = 'x';
	} else if (*charCyr == 'Ö') {
		*charCyr = 0b11100001;
	} else if (*charCyr == 'ö') {
		*charCyr = 0b11100101;
	} else if (*charCyr == '×') {
		*charCyr = 0b10101011;
	} else if (*charCyr == '÷') {
		*charCyr = 0b11000000;
	} else if (*charCyr == 'Ø') {
		*charCyr = 0b10101100;
	} else if (*charCyr == 'ø') {
		*charCyr = 0b11000001;
	} else if (*charCyr == 'Ù') {
		*charCyr = 0b11100010;
	} else if (*charCyr == 'ù') {
		*charCyr = 0b11100110;
	} else if (*charCyr == 'ú') {
		*charCyr = 0b11000010;
	} else if (*charCyr == 'Û') {
		*charCyr = 0b10101110;
	} else if (*charCyr == 'û') {
		*charCyr = 0b11000011;
	} else if (*charCyr == 'ü') {
		*charCyr = 0b11000100;
	} else if (*charCyr == 'Ý') {
		*charCyr = 0b10101111;
	} else if (*charCyr == 'ý') {
		*charCyr = 0b11000101;
	} else if (*charCyr == 'Þ') {
		*charCyr = 0b10110000;
	} else if (*charCyr == 'þ') {
		*charCyr = 0b11000110;
	} else if (*charCyr == 'ß') {
		*charCyr = 0b10110001;
	} else if (*charCyr == 'ÿ') {
		*charCyr = 0b11000111;
	}

	return charCyr;
}


/*
void i2c_addr_scan(I2C_HandleTypeDef *hi2c) {
	for (uint16_t i = 0; i < 128; i++) {
		if ((HAL_I2C_IsDeviceReady(hi2c, i << 1, 1, HAL_MAX_DELAY))
				== HAL_OK) {
			addr = i;
			i = 129;
		}
	}
}
*/

void sendLcdInstruction(uint8_t instruction, I2CSettings settings) {
	uint8_t upperBite = instruction & 0xF0;
	uint8_t lowerBite = (instruction << 4) & 0xF0;

	uint8_t ByteArr[4] {};

	ByteArr[0] = upperBite | LED | EN;
	ByteArr[1] = 0;
	ByteArr[2] = lowerBite | LED | EN;
	ByteArr[3] = 0;

	i2cLcdState = 1;
	HAL_I2C_Master_Transmit_DMA(settings.hi2c, settings.i2cAddr, ByteArr, 4);
	while (i2cLcdState == 1) {
	}
}


void sendLcdChar(uint8_t character, uint8_t ddramAddr, I2CSettings settings) {
	setDdramAddr(ddramAddr, settings);

	uint8_t upperBite = character & 0xF0;
	uint8_t lowerBite = (character << 4) & 0xF0;

	uint8_t ByteArr[4] {};

	ByteArr[0] = upperBite | 1 | LED | EN;
	ByteArr[1] = 0;
	ByteArr[2] = lowerBite | 1 | LED | EN;
	ByteArr[3] = 0;

	i2cLcdState = 1;
	HAL_I2C_Master_Transmit_DMA(settings.hi2c, settings.i2cAddr, ByteArr, 4);
	while (i2cLcdState == 1) {
	}
}

void sendLcdByte(uint8_t character, I2CSettings settings) {
	uint8_t upperBite = character & 0xF0;
	uint8_t lowerBite = (character << 4) & 0xF0;

	uint8_t ByteArr[4] {};

	ByteArr[0] = upperBite | 1 | LED | EN;
	ByteArr[1] = 0;
	ByteArr[2] = lowerBite | 1 | LED | EN;
	ByteArr[3] = 0;

	i2cLcdState = 1;
	HAL_I2C_Master_Transmit_DMA(settings.hi2c, settings.i2cAddr, ByteArr, 4);
	while (i2cLcdState == 1) {
	}
}

void sendLcdStr(char *string, uint8_t ddramAddr, I2CSettings settings) {
	setDdramAddr(ddramAddr, settings);
	while (*string) {
		char stringCopy = *string;
		stringCopy = *recodeCyr(&stringCopy);
		sendLcdByte(uint8_t(stringCopy), settings);
		++string;
	}
}


void sendLcdStrAB(char *string, uint8_t a, uint8_t b, uint8_t ddramAddr, I2CSettings settings) {
	setDdramAddr(ddramAddr, settings);
	for (uint8_t i = a; i < b; ++i) {
		char stringCopy = *string;
		stringCopy = *recodeCyr(&stringCopy);
		sendLcdByte(uint8_t(stringCopy), settings);
		++string;
	}
}

void clearLcd(I2CSettings settings) {
	uint8_t ByteArr[4] { 4, 0, 20, 0 };

	i2cLcdState = 1;
	HAL_I2C_Master_Transmit_DMA(settings.hi2c, settings.i2cAddr, ByteArr, 4);
	while (i2cLcdState == 1) {
	}
}

void clearChar(uint8_t charPos, I2CSettings settings) {
	sendLcdChar(0b10000000, charPos, settings);
}

void setDdramAddr(uint8_t ddramAddr, I2CSettings settings) {
	uint8_t upperBite = (ddramAddr | 0x80) & 0xF0;
	uint8_t lowerBite = (ddramAddr << 4) & 0xF0;

	uint8_t ByteArr[4]{};

	ByteArr[0] = upperBite | EN;
	ByteArr[1] = 0;
	ByteArr[2] = lowerBite | EN;
	ByteArr[3] = 0;

	i2cLcdState = 1;
	HAL_I2C_Master_Transmit_DMA(settings.hi2c, settings.i2cAddr, ByteArr, 4);
	while (i2cLcdState == 1) {
	}
}

void lcdInit(I2CSettings settings) {
	HAL_Delay(50);

	sendLcdInstruction(0b00110000, settings);   // 8ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	HAL_Delay(40);

	sendLcdInstruction(0b00000010, settings);   // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	HAL_Delay(40);

	sendLcdInstruction(0b00001100, settings);   // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½, ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	HAL_Delay(40);

	sendLcdInstruction(0b00000100, settings);
	HAL_Delay(40);

	sendLcdInstruction(0b00000001, settings);   // ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	HAL_Delay(2);
}
