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
	bool is_size_changed = false;
	int size = 1;
	double expansion = 0.0;
	Layout layout;
public:
	FontRect(const String& text, const Vec2& place)
	{
		this->place = place;
		real_place = place;
		layout = Layout();
		layout.init();
		font = Font(layout.FONT_SIZE);
		rectf = RectF(place, layout.BTN_F_SIZE, layout.BTN_F_SIZE);
		size = layout.FONT_SIZE;
		this->text = text;
	}
	~FontRect() {}

	void changeSize(const double&);
	void changeTxt(const String&);
	Vec2 getPlace();
	void pollChangePlaceEvent(const double&, const int&, const int&);
	void move(const double&);
	void draw();
};

