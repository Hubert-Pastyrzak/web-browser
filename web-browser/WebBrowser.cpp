#include "WebBrowser.h"
#include <Windows.h>

WebBrowser::WebBrowser(UI_Backend& uiBackend)
	: uiBackend(uiBackend)
	, ui(UI(uiBackend))
	, browserEngine(BrowserEngine())
{
	UI_MainWindow& uiMainWindow = this->ui.getMainWindow();
	BrowserEngine& browserEngine = this->browserEngine;

	uiMainWindow.onClose = [this]() {
		this->uiBackend.requestMessageLoopQuit(0);
	};

	uiMainWindow.onBackButtonClicked = [&browserEngine]() {
		browserEngine.goBack();
	};

	uiMainWindow.onForwardButtonClicked = [&browserEngine]() {
		browserEngine.goForward();
	};

	uiMainWindow.onAddressEntered = [&browserEngine](const wchar_t* address) {
		browserEngine.navigate(address);
	};

	browserEngine.onBackButtonStatusChanged = [&uiMainWindow](bool enabled) {
		uiMainWindow.setBackButtonEnabled(enabled);
	};

	browserEngine.onForwardButtonStatusChanged = [&uiMainWindow](bool enabled) {
		uiMainWindow.setForwardButtonEnabled(enabled);
	};
}

int WebBrowser::run() {
	int exitCode = this->uiBackend.runMessageLoop();
	return exitCode;
}
