#include "Button.h"

uint8_t isTimerOn = 0;
TIM_HandleTypeDef* Button::htimX = nullptr;
TIM_TypeDef* Button::TIMx = nullptr;

Button::Button(GPIO_TypeDef *GPIOx, uint16_t pin, void (*function)()) {
	if (Button::isTimerOn == 0) {
		HAL_TIM_Base_Start_IT(htimX);
		Button::isTimerOn = 1;
	}
	Button::GPIOx.push_back(GPIOx);
	Button::pin.push_back(pin);
	Button::function.push_back(function);
}

void Button::setTimer(TIM_HandleTypeDef* htimX, TIM_TypeDef* TIMx) {
	Button::htimX = htimX;
	Button::TIMx = TIMx;
}

TIM_TypeDef* Button::getTIMx() {
	return Button::TIMx;
}

void Button::shortPress(void (*function)()) {
	if (GPIOx->IDR & 1 << pin) {
		switch (previousButtonState) {
		case 0:
			previousButtonState = 1;
			break;
		case 1:
			function();
			break;
		}
	} else {
		if (previousButtonState) {
			previousButtonState = 0;
		}
	}
}

/*
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == Button::getTIMx()) {
		for (uint8_t i = 0; i < numOfButtons; ++i) {
			Button::shortPress();
		}
	}
}
*/



