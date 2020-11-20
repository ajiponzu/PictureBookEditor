#pragma once
#include <Siv3D.hpp>
#include "Layout.h"

class FontRect
{
public:
	Vec2 relative;
private:
	RectF rectf;
	String text;
	Font font;
	bool is_pressed = false;
	bool is_size_changed = false;
	int size = 1;
	double expansion = 0.0;
	Layout layout;
public:
	FontRect(const String& text, const Vec2& place) : text(text), relative(place)
	{
		layout = Layout();
		layout.init();
		font = Font(layout.FONT_SIZE);
		rectf = RectF(place, layout.BTN_F_SIZE, layout.BTN_F_SIZE);
		size = layout.FONT_SIZE;
	}
	~FontRect() {}

	void changeSize(const double&);
	void changeTxt(const String&);
	void pollChangePlaceEvent(const double&);
	void move(const double&);
	void draw();
};
