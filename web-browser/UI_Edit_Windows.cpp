#include "UI_Edit_Windows.h"

UI_Edit_Windows::UI_Edit_Windows(HINSTANCE hInstance, HWND hWndParent) {
	this->hWnd = CreateWindowEx(0, L"EDIT", nullptr, WS_CHILD | WS_VISIBLE | WS_BORDER, 0, 0, 1, 1, hWndParent, nullptr, hInstance, nullptr);
}

UI_Edit_Windows::~UI_Edit_Windows() {
	DestroyWindow(this->hWnd);
}

void* UI_Edit_Windows::getRawControl() {
	return this->hWnd;
}

void UI_Edit_Windows::setEnabled(bool enabled) {
	EnableWindow(this->hWnd, enabled);
}

void UI_Edit_Windows::setBounds(int x, int y, int width, int height) {
	MoveWindow(this->hWnd, x, y, width, height, true);
}

void UI_Edit_Windows::withText(std::function<void(const wchar_t*)> callback) {
	int textLength = GetWindowTextLength(this->hWnd);
	wchar_t* text = new wchar_t[textLength + 1];

	GetWindowText(this->hWnd, text, textLength + 1);
	callback(text);

	delete[] text;
}
