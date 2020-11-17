#include "FontRect.h"

Vec2 FontRect::getPlace()
{
	return place;
}

void FontRect::pollChangePlaceEvent(const double& expansion, const int& max_x, const int& max_y)
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

void FontRect::move(const double& expansion)
{
	rectf = RectF(place * expansion, font.fontSize() * text.length() * expansion, font.fontSize() * expansion);
}

void FontRect::draw()
{
	if (text != U"")
	{
		if (is_pressed)
		{
			rectf.draw(AlphaF(0)).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Violet);
		}
		else
		{
			rectf.draw(AlphaF(0)).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, AlphaF(0));
		}
		font(text).draw(rectf.stretched(1), Palette::Black);
	}
}

