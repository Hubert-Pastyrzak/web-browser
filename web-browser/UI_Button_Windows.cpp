#include "UI_Button_Windows.h"

UI_Button_Windows::UI_Button_Windows(HINSTANCE hInstance, HWND hWndParent, LPCWSTR text) {
	this->hWnd = CreateWindowEx(0, L"BUTTON", text, WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 0, 1, 1, hWndParent, nullptr, hInstance, nullptr);
	SetWindowLongPtr(this->hWnd, GWLP_USERDATA, (LONG_PTR)this);
}

UI_Button_Windows::~UI_Button_Windows() {
	DestroyWindow(this->hWnd);
}

void* UI_Button_Windows::getRawControl() {
	return this->hWnd;
}

void UI_Button_Windows::setEnabled(bool enabled) {
	EnableWindow(this->hWnd, enabled);
}

void UI_Button_Windows::setBounds(int x, int y, int width, int height) {
	MoveWindow(this->hWnd, x, y, width, height, true);
}
