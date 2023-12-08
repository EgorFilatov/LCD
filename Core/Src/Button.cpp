#include "Button.h"

extern I2C_HandleTypeDef hi2c1;

uint8_t Button::isTimerOn = 0;
TIM_HandleTypeDef* Button::htimX = &htim6;
TIM_TypeDef* Button::TIMx = TIM6;

std::vector<GPIO_TypeDef*> Button::GPIOx;
std::vector<uint16_t> Button::pin;
std::vector<void (*)()> Button::function;
std::vector<uint8_t> Button::previousButtonState;

Button::Button(GPIO_TypeDef *GPIOx, uint16_t pin, void (*function)()) {
	if (Button::isTimerOn == 0) {
		HAL_TIM_Base_Start_IT(htimX);
		Button::isTimerOn = 1;
	}
	Button::GPIOx.push_back(GPIOx);
	Button::pin.push_back(pin);
	Button::function.push_back(function);
	Button::previousButtonState.push_back(0);
}

void Button::setTimer(TIM_HandleTypeDef* htimX, TIM_TypeDef* TIMx) {
	Button::htimX = htimX;
	Button::TIMx = TIMx;
}

TIM_TypeDef* Button::getTIMx() {
	return Button::TIMx;
}

void Button::shortPress() {
	for (uint8_t i = 0; i < Button::pin.size(); ++i) {
		if (Button::GPIOx[i]->IDR & 1 << Button::pin[i]) {
			switch (Button::previousButtonState[i]) {
			case 0:
				Button::previousButtonState[i] = 1;
				break;
			case 1:
				Button::previousButtonState[i] = 2;
				Button::function[i]();
				break;
			}

		} else {
			if (Button::previousButtonState[i]) {
				Button::previousButtonState[i] = 0;
			}
		}
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == Button::getTIMx()) {
		Button::shortPress();
	}
}





