#pragma once
#include <Siv3D.hpp>
#include "Layout.h"

class FontRect
{
public:
	Vec2 pos;
private:
	Vec2 relative;
	Layout layout{};
	RectF rectf{};
	String text{};
	Font font;
	bool is_pressed = false;
	bool is_size_changed = false;
	int size = 1;
	double expansion = 0.0;
public:
	FontRect(const String& text, const Vec2& relative) : text(text), relative(relative)
	{
		font = Font(layout.FONT_SIZE);
		size = layout.FONT_SIZE;
		this->pos = Vec2::Zero();
	}
	~FontRect() {}

	void setRelativePos(const Vec2&, const Vec2&);
	Vec2 getRelativePos();
	void changeSize(const double&);
	void changeTxt(const String&);
	void pollChangePlaceEvent(const double&);
	void move(const double&);
	void draw();
};

