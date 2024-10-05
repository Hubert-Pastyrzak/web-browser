#pragma once

#include "UI_Backend.h"
#include "UI_Window.h"
#include "UI_Flex.h"
#include "UI_Button.h"
#include "UI_Edit.h"
#include "UI_Size.h"
#include <functional>

class UI_MainWindow {
private:
	UI_Backend& uiBackend;

	UI_Window& window;
	UI_Flex toolbarFlex;

	UI_Button* backButton;
	UI_Button* forwardButton;
	UI_Edit* addressBar;

	void handleClientAreaSize(UI_Size clientAreaSize);

public:
	UI_MainWindow(UI_Backend& uiBackend);

	std::function<void()> onClose;

	std::function<void()> onBackButtonClicked;
	std::function<void()> onForwardButtonClicked;
	std::function<void(const wchar_t* address)> onAddressEntered;

	void setBackButtonEnabled(bool enabled);
	void setForwardButtonEnabled(bool enabled);
};
