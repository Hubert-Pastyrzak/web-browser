#pragma once

#include <functional>

class BrowserEngine {
public:
	BrowserEngine();

	std::function<void(bool)> onBackButtonStatusChanged;
	std::function<void(bool)> onForwardButtonStatusChanged;

	void goBack();
	void goForward();
	void navigate(const wchar_t* address);
};
