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
	String text;
	Font  font;
public:
	MyButton(int x, int y, int wid, int high, String txt, int font_size) : x(x), y(y), width(wid), height(high)
	{
		button = Rect(x, y, wid, high);
		text = txt;
		font = Font(font_size, Typeface::Bold);
	};
	~MyButton() {}

	bool isClicked(int&, int&);
private:
	void resize(int&, int&);
};

