#pragma once

#include "UI_Edit.h"
#include <Windows.h>

class UI_Edit_Windows : public UI_Edit {
private:
	HWND hWnd = nullptr;

public:
	UI_Edit_Windows(HINSTANCE hInstance, HWND hWndParent);
	~UI_Edit_Windows();

	void* getRawControl() override;

	void setEnabled(bool enabled) override;
	void setBounds(int x, int y, int width, int height) override;

	void withText(std::function<void(const wchar_t*)> callback) override;
};
