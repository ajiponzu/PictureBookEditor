#pragma once
#include <Siv3D.hpp>
#include "Layout.h"

class MyButton
{
private:
	int x = 0, y = 0;
	int width = 0, height = 0;
	Rect button;
	String text;
	Font  font;
	Layout layout;
public:
	MyButton(const int& x, const int& y, const int& wid, const int& high, const String& txt, const int& font_size) : x(x), y(y), width(wid), height(high)
	{
		button = Rect(x, y, wid, high);
		text = txt;
		font = Font(font_size, Typeface::Bold);
		layout = Layout();
		layout.init();
	};
	~MyButton() {}

	bool isClicked();
	bool isClickedInvBtn();
};

