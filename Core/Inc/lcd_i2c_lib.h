#ifndef INC_LCD_I2C_LIB_H_
#define INC_LCD_I2C_LIB_H_

#include <main.h>

#define EN  0b00000100 // ��� EN
#define LED 0b00001000 // ��� ��������� ������������ ���������
#define DDRAM_ADDR_COMMAND 0b10000000 // ������� ������ ������ DDRAM ������ � �������� ���������

struct I2CSettings {
	I2C_HandleTypeDef *hi2c;
	uint8_t i2cAddr;
};

/* ������� ����������� ������������� ��������
 ******************************************************************************
 * cyrillic_character- ������ ��� �����������
 */
char *recodeCyr(char *charCyr);


/* ������� ������ ������ i2c ������� */
void ScanI2C(I2C_HandleTypeDef *hi2c);


void sendLcdInstruction(uint8_t instruction, I2CSettings settings);
void sendLcdChar(uint8_t character, uint8_t ddramAddr, I2CSettings settings);
void sendLcdByte(uint8_t character, I2CSettings settings);


/* ������� �������� ������
 ******************************************************************************
 * str- ������������ ������
 * cyrillic = 0- ��� ������������� ��������, cyrillic = 1- ���� ������������� �������
 */
void sendLcdStr(char *string, uint8_t ddramAddr, I2CSettings settings);
void sendLcdStrAB(char *string, uint8_t a, uint8_t b, uint8_t ddramAddr, I2CSettings settings);


/* ������� ������� ������� */
void clearLcd(I2CSettings settings);

/* ������� ������� ������� �� ������� */
void clearChar(uint8_t charPos, I2CSettings settings);


/* ������� ������ ������ DDRAM ������ � �������� ���������
 ******************************************************************************
 * ddram_addr- ����� ������
 */
void setDdramAddr(uint8_t ddramAddr, I2CSettings settings);


/* ������� ������������� ������� */
void lcdInit(I2CSettings settings);

#endif
