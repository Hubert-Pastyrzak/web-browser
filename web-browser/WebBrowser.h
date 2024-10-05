#pragma once

#include "UI_Backend.h"
#include "UI.h"
#include "BrowserEngine.h"

class WebBrowser {
private:
	UI_Backend& uiBackend;

	UI ui;
	BrowserEngine browserEngine;

public:
	WebBrowser(UI_Backend& uiBackend);
	int run();
};
