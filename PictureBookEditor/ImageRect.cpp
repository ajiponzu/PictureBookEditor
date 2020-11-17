#include "ImageRect.h"

void ImageRect::changeSize(const double& size)
{
	this->size = size;
}

void ImageRect::changeAlpha(const double& alpha)
{
	this->alpha = alpha;
}

void ImageRect::changeImg(const String& path)
{
	this->path = path;
	img = Texture(path);
	if (!img)
    {
		this->path = U"";
		img = Texture(this->path);
    }
}

Vec2 ImageRect::getPlace()
{
	return place;
}

void ImageRect::pollChangePlaceEvent(const double& expansion, const int& max_x, const int& max_y)
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

void ImageRect::move(const double& expansion)
{
	rectf = RectF(place * expansion, img.width() * size * expansion, img.height() * size * expansion);
}

void ImageRect::draw()
{
	if (path != U"")
	{
		if (is_pressed)
		{
			rectf.draw(AlphaF(0)).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Blue);
		}
		else
		{
			rectf.draw(AlphaF(0)).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, AlphaF(0));
		}
		img.scaled(size).draw(rectf.x, rectf.y, AlphaF(alpha));
	}
}

