#pragma once

#include "UI_Window.h"
#include <Windows.h>

class UI_Window_Windows : public UI_Window {
private:
	HINSTANCE hInstance;
	HWND hWnd;

public:
	UI_Window_Windows(HINSTANCE hInstance, int nCmdShow, LPCWSTR title);
	~UI_Window_Windows();

	UI_Size getClientAreaSize() override;

	UI_Button& createButton(const wchar_t* text) override;
	UI_Edit& createEdit() override;
};
