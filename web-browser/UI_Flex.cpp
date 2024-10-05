#include "UI_Flex.h"

int UI_Flex::getMinWidth() {
	return this->minWidth;
}

void UI_Flex::addControl(UI_Control& control, bool grow, int width) {
	if (!grow) {
		this->minWidth += width;
	}

	if (this->controlInfos.size() > 0) {
		this->minWidth += this->gap;
	}

	this->controlInfos.push_back(UI_Flex::ControlInfo(control, grow, width));
}

void UI_Flex::addControl(UI_Control& control, bool grow, int width, int growMinWidthPx) {
	this->addControl(control, grow, width);

	if (grow) {
		this->minWidth += growMinWidthPx;
	}
}

void UI_Flex::handleBounds(UI_Bounds bounds) {
	int currentX = bounds.x;

	int growDenominator = 0;
	int growTotalWidth = bounds.width;
	for (auto& controlInfo : this->controlInfos) {
		if (controlInfo.grow) {
			growDenominator += controlInfo.width;
		}
		else {
			growTotalWidth -= controlInfo.width + this->gap;
		}
	}

	for (auto& controlInfo : this->controlInfos) {
		if (controlInfo.grow) {
			int width = (controlInfo.width * growTotalWidth) / growDenominator;

			controlInfo.control.setBounds(currentX, bounds.y, width, bounds.height);
			currentX += width;
		}
		else {
			controlInfo.control.setBounds(currentX, bounds.y, controlInfo.width, bounds.height);
			currentX += controlInfo.width;
		}

		currentX += this->gap;
	}
}
