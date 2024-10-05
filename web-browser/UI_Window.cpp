#include "UI_Window.h"

UI_Window::~UI_Window() {
	for (auto& control : this->controls) {
		delete control;
	}
}
