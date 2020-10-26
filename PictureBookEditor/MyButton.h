#pragma once
#define SIV3D_WINDOWS_HIGH_DPI
#include <Siv3D.hpp>

#include "ViewComponent.h"

class MyButton
{
private:
	int x = 0, y = 0;
	int width = 0, height = 0;
	Rect button;
public:
	MyButton(int x, int y, int wid, int high) : x(x), y(y), width(wid), height(high)
	{
		button = Rect(x, y, wid, high);
	};
	~MyButton() {}

	bool isClicked(int&, int&);
private:
	void resize(int&, int&);
	bool isMouseOver();
};

