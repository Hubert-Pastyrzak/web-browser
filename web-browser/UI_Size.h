#pragma once

struct UI_Size {
public:
	int width;
	int height;

	UI_Size()
		: width(0)
		, height(0)
	{}

	UI_Size(int width, int height)
		: width(width)
		, height(height)
	{}
};
