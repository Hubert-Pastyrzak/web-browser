#include "UI.h"

UI::UI(UI_Backend& uiBackend)
	: uiBackend(uiBackend)
	, mainWindow(UI_MainWindow(uiBackend))
{
}

UI_MainWindow& UI::getMainWindow() {
	return this->mainWindow;
}
