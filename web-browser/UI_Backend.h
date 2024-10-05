#pragma once

#include "UI_Window.h"
#include <functional>

class UI_Backend {
public:
	virtual UI_Window& createWindow(const wchar_t* title) = 0;

	virtual int runMessageLoop() = 0;
	virtual void requestMessageLoopQuit(int exitCode) = 0;
};
