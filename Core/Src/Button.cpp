#include <Button.h>

Button::Button(GPIO_TypeDef *port, uint8_t pin, uint8_t debounceTime) {
	this->port = port;
	this->pin = pin;
	this->prevSt = 0;
	this->debounceTim.SetDefault(debounceTime);
	this->debounceTim.Off();
}

uint8_t Button::getPrevSt() {
	return this->prevSt;
}

void Button::setPrevSt(uint8_t prevSt) {
	this->prevSt = prevSt;
}

uint8_t Button::clicked() {
	if (this->port->IDR & (1 << pin)) {
		if (debounceTim.IsOff()) {
			debounceTim.Reset();
		} else if (debounceTim.GetEvent()) {
			debounceTim.Off();
			return 1;
		}
	}
	return 0;
}

uint8_t Button::unclicked() {
	if (!(this->port->IDR & (1 << pin))) {
		if (debounceTim.IsOff()) {
			debounceTim.Reset();
		} else if (debounceTim.GetEvent()) {
			debounceTim.Off();
			return 1;
		}
	}
	return 0;
}
