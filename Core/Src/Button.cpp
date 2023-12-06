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
	Button::previousButtonState.push_back(0);
}

void Button::setTimer(TIM_HandleTypeDef* htimX, TIM_TypeDef* TIMx) {
	Button::htimX = htimX;
	Button::TIMx = TIMx;
}

std::vector<GPIO_TypeDef*> Button::getGPIOx() {
	return Button::GPIOx;
}
std::vector<uint16_t> Button::getPin() {
	return Button::pin;
}

std::vector<void (*)()> Button::getFunction() {
	return Button::function;
}

std::vector<uint8_t> Button::getPreviousButtonState() {
	return Button::previousButtonState;
}





TIM_TypeDef* Button::getTIMx() {
	return Button::TIMx;
}

void Button::shortPress() {
	for (uint8_t i = 0; i < Button::getPin().size(); ++i) {
		if (Button::getGPIOx()[i]->IDR & 1 << Button::getPin()[i]) {
			switch (Button::getPreviousButtonState()[i]) {
			case 0:
				Button::getPreviousButtonState()[i] = 1;
				break;
			case 1:
				Button::getFunction()[i]();
				break;
			}
		} else {
			if (Button::getPreviousButtonState()[i]) {
				Button::getPreviousButtonState()[i] = 0;
			}
		}
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == Button::getTIMx()) {
		Button::shortPress();
	}
}




