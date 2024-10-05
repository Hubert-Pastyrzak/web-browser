#pragma once

#include "UI_Backend.h"
#include "UI_MainWindow.h"

class UI {
private:
	UI_Backend& uiBackend;

	UI_MainWindow mainWindow;

public:
	UI(UI_Backend& uiBackend);

	UI_MainWindow& getMainWindow();
};
