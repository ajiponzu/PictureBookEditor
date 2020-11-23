#pragma once
#include <Siv3D.hpp>
#include "Layout.h"

//オリジナルボタンクラス
class MyButton
{
private:
	int x = 0, y = 0;
	int width = 0, height = 0;
	Layout layout{};
	Rect button;
	String text;
	Font  font;
	Transition transition = Transition(0.4s, 0.2s);
	ColorF palette = Palette::Lavender;
public:
	MyButton(const int& x, const int& y, const int& wid, const int& high, const String& txt, const int& font_size) : x(x), y(y), width(wid), height(high)
	{
		button = Rect(x, y, wid, high);
		text = txt;
		font = Font(font_size, Typeface::Bold);
	};
	~MyButton() {}

	bool isClicked();
	bool isClickedInvBtn();
};
