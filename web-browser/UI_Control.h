#pragma once

class UI_Control {
public:
	virtual ~UI_Control() {}

	virtual void* getRawControl() = 0;

	virtual void setEnabled(bool enabled) = 0;
	virtual void setBounds(int x, int y, int width, int height) = 0;
};
