#pragma once
#include <Siv3D.hpp>
#include "Layout.h"

class FontRect
{
private:
	RectF rectf;
	String text;
	Font font;
	Vec2 place;
	Vec2 real_place;
	bool is_pressed = false;
	int size = 0;
	Layout layout;
public:
	FontRect(const String& text, const Vec2& place)
	{
		this->place = place;
		real_place = place;
		layout = Layout();
		layout.init();
		font = Font(layout.BTN_F_SIZE);
		size = layout.BTN_F_SIZE;
		this->text = text;
	}
	~FontRect() {}

	Vec2 getPlace();
	void pollChangePlaceEvent(const double&, const int&, const int&);
	void move(const double&);
	void draw();
};

