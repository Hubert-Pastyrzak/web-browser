#pragma once

#include "UI_Control.h"
#include <functional>

class UI_Button : public UI_Control {
public:
	virtual ~UI_Button() {}

	std::function<void()> onClick;
};
