#pragma once

#include "UI_Backend.h"
#include <Windows.h>

class UI_Backend_Windows : public UI_Backend {
private:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	HINSTANCE hInstance;
	int nCmdShow;

public:
	UI_Backend_Windows(HINSTANCE hInstance, int nCmdShow);
	~UI_Backend_Windows();

	UI_Window& createWindow(const wchar_t* title) override;

	int runMessageLoop() override;
	void requestMessageLoopQuit(int exitCode) override;
};
