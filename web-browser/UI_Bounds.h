#pragma once

struct UI_Bounds {
public:
	int x;
	int y;
	int width;
	int height;

	UI_Bounds(int x, int y, int width, int height)
		: x(x)
		, y(y)
		, width(width)
		, height(height)
	{};
};
