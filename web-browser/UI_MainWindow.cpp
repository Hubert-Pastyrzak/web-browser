#include "UI_MainWindow.h"
#include "Globals.h"
#include <Windows.h>
#include <memory>

UI_MainWindow::UI_MainWindow(UI_Backend& uiBackend)
	: uiBackend(uiBackend)
	, window(uiBackend.createWindow(BROWSER_NAME))
	, toolbarFlex(UI_Flex(8))
{
	this->window.onResize = [this](UI_Size clientAreaSize) {
		this->handleClientAreaSize(clientAreaSize);
	};

	this->window.onClose = [this]() {
		if (this->onClose) {
			this->onClose();
		}
	};

	this->backButton = &(this->window.createButton(L"Back"));
	this->toolbarFlex.addControl(*backButton, false, 64);
	this->backButton->setEnabled(false);
	this->backButton->onClick = [this]() {
		if (this->onBackButtonClicked) {
			this->onBackButtonClicked();
		}
	};

	this->forwardButton = &(this->window.createButton(L"Forward"));
	this->toolbarFlex.addControl(*forwardButton, false, 64);
	this->forwardButton->setEnabled(false);
	this->forwardButton->onClick = [this]() {
		if (this->onForwardButtonClicked) {
			this->onForwardButtonClicked();
		}
	};

	this->addressBar = &(this->window.createEdit());
	this->toolbarFlex.addControl(*addressBar, true, 1, 128);

	auto addressBar = this->addressBar;

	auto& goButton = this->window.createButton(L"Go");
	this->toolbarFlex.addControl(goButton, false, 64);
	goButton.onClick = [this, addressBar]() {
		if (this->onAddressEntered) {
			addressBar->withText([this](const wchar_t* address) {
				this->onAddressEntered(address);
			});
		}
	};

	auto& bookmarksButton = this->window.createButton(L"Bookmarks");
	this->toolbarFlex.addControl(bookmarksButton, false, 128);

	this->window.minClientAreaSize.width = this->toolbarFlex.getMinWidth() + 16;
	this->window.minClientAreaSize.height = 40;

	UI_Size clientAreaSize = this->window.getClientAreaSize();
	this->handleClientAreaSize(clientAreaSize);
}

void UI_MainWindow::handleClientAreaSize(UI_Size clientAreaSize) {
	UI_Bounds toolbarBounds(8, 8, clientAreaSize.width - 16, 24);
	this->toolbarFlex.handleBounds(toolbarBounds);
}

void UI_MainWindow::setBackButtonEnabled(bool enabled) {
	this->backButton->setEnabled(enabled);
}

void UI_MainWindow::setForwardButtonEnabled(bool enabled) {
	this->forwardButton->setEnabled(enabled);
}
