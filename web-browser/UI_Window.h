#pragma once

#include <vector>
#include <functional>
#include "UI_Size.h"
#include "UI_Button.h"
#include "UI_Edit.h"

class UI_Window {
protected:
	std::vector<UI_Control*> controls;

public:
	virtual ~UI_Window();

	std::function<void(UI_Size clientAreaSize)> onResize;
	std::function<void()> onClose;

	UI_Size minClientAreaSize = UI_Size(0, 0);

	virtual UI_Size getClientAreaSize() = 0;

	virtual UI_Button& createButton(const wchar_t* text) = 0;
	virtual UI_Edit& createEdit() = 0;
};
