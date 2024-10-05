#include "UI_Window_Windows.h"

#include "Globals_Windows.h"
#include "UI_Button_Windows.h"
#include "UI_Edit_Windows.h"

UI_Window_Windows::UI_Window_Windows(HINSTANCE hInstance, int nCmdShow, LPCWSTR title) {
	this->hInstance = hInstance;

	this->hWnd = CreateWindowEx(0, WINDOWS_CLASS_NAME, title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, hInstance, nullptr);
	SetWindowLongPtr(this->hWnd, GWLP_USERDATA, (LONG_PTR)this);
	ShowWindow(this->hWnd, nCmdShow);
}

UI_Window_Windows::~UI_Window_Windows() {
	DestroyWindow(this->hWnd);
}

UI_Size UI_Window_Windows::getClientAreaSize() {
	RECT clientRect = {};
	GetClientRect(this->hWnd, &clientRect);

	return UI_Size(clientRect.right, clientRect.bottom);
}

UI_Button& UI_Window_Windows::createButton(const wchar_t* text) {
	auto button = new UI_Button_Windows(this->hInstance, this->hWnd, text);
	this->controls.push_back(button);

	return *button;
}

UI_Edit& UI_Window_Windows::createEdit() {
	auto edit = new UI_Edit_Windows(this->hInstance, this->hWnd);
	this->controls.push_back(edit);

	return *edit;
}
