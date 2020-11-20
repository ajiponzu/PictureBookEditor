#include "ImageRect.h"

void ImageRect::setRelativePos(const Vec2& pos, const Vec2& relative)
{
	this->pos = pos;
	this->relative = relative;
}

Vec2 ImageRect::getRelativePos()
{
	return relative;
}

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

void ImageRect::pollChangePosEvent(const double& expansion)
{
	if (path == U"") return;
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
		relative += Cursor::Delta() / expansion;
	}
}

void ImageRect::move(const double& expansion)
{
	if (path == U"") return;
	this->expansion = expansion;
	rectf = RectF(pos + relative * expansion, img.width() * size * expansion, img.height() * size * expansion);
}

void ImageRect::draw()
{
	if (path == U"") return;
	if (is_pressed)
	{
		rectf.draw(AlphaF(0)).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Blue);
	}
	else
	{
		rectf.draw(AlphaF(0)).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, AlphaF(0));
	}
	img.scaled(size * expansion).draw(rectf.x, rectf.y, AlphaF(alpha));
}