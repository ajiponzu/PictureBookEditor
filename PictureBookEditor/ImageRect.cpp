#include "ImageRect.h"

Vec2 ImageRect::getPlace()
{
	return place;
}

void ImageRect::pollChangePlaceEvent(const double &expansion, const int &max_x, const int &max_y)
{
	if (rectf.mouseOver()) Cursor::RequestStyle(CursorStyle::Hand);
	if (rectf.leftClicked())
	{
		is_pressed = true;
	}
	if (MouseL.up())
	{
		is_pressed = false;
	}
	if (is_pressed)
	{
		place += Cursor::Delta() / expansion;
	}

	if (place.x < 0)
	{
		place.x = 0;
	}
	else if (place.x > max_x)
	{
		place.x = max_x;
	}
	if (place.y < 0)
	{
		place.y = 0;
	}
	else if (place.y > max_y)
	{
		place.y = max_y;
	}
}

void ImageRect::move(const Vec2 &cur_pos, const double &expansion)
{
	rectf = RectF(cur_pos, img.width() * expansion, img.height() * expansion);
}

void ImageRect::draw()
{
	if (is_pressed)
	{
		rectf.draw(AlphaF(0)).drawFrame(5, 5, Palette::Aqua);
	}
	else
	{
		rectf.draw(AlphaF(0)).drawFrame(5, 5, Palette::Blueviolet);
	}
}
