#pragma once

#include <vector>
#include "UI_Control.h"
#include "UI_Bounds.h"

class UI_Flex {
	struct ControlInfo {
		UI_Control& control;
		bool grow;
		int width;

		ControlInfo(UI_Control& control, bool grow, int width)
			: control(control)
			, grow(grow)
			, width(width)
		{}
	};

private:
	int gap;

	int minWidth = 0;
	std::vector<UI_Flex::ControlInfo> controlInfos;

public:
	UI_Flex()
		: gap(0)
	{}

	UI_Flex(int gap)
		: gap(gap)
	{}

	int getMinWidth();

	void addControl(UI_Control& control, bool grow, int width);
	void addControl(UI_Control& control, bool grow, int width, int growMinWidthPx);

	void handleBounds(UI_Bounds bounds);
};
