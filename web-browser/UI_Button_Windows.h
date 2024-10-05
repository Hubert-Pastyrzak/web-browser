#pragma once

#include "UI_Button.h"
#include <Windows.h>

class UI_Button_Windows : public UI_Button {
private:
	HWND hWnd = nullptr;

public:
	UI_Button_Windows(HINSTANCE hInstance, HWND hWndParent, LPCWSTR text);
	~UI_Button_Windows();

	void* getRawControl() override;

	void setEnabled(bool enabled) override;
	void setBounds(int x, int y, int width, int height) override;
};
