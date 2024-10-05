#pragma once

#include "UI_Control.h"
#include <functional>

class UI_Edit : public UI_Control {
public:
	virtual ~UI_Edit() {}

	virtual void withText(std::function<void(const wchar_t*)> callback) = 0;
};
