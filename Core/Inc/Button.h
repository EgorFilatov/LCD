#ifndef SRC_BUTTON_H_
#define SRC_BUTTON_H_

#include "main.h"
#include <vector>

extern TIM_HandleTypeDef htim6;

class Button {
private:
	static std::vector<GPIO_TypeDef*> GPIOx;
	static std::vector<uint16_t> pin;
	static std::vector<void (*)()> function;
	static std::vector<uint8_t> previousButtonState;
	static uint8_t isTimerOn;
	static TIM_HandleTypeDef* htimX;
	static TIM_TypeDef* TIMx;
public:
	Button(GPIO_TypeDef *GPIOx, uint16_t pin, void (*function)());
	static void setTimer(TIM_HandleTypeDef* htimX = &htim6, TIM_TypeDef* TIMx = TIM6);
	static TIM_TypeDef* getTIMx();
	static void shortPress();
};

#endif /* SRC_BUTTON_H_ */
