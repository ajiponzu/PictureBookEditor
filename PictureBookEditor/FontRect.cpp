#include "FontRect.h"

void FontRect::setRelativePos(const Vec2& pos, const Vec2& relative)
{
	this->pos = pos;
	this->relative = relative;
}

Vec2 FontRect::getRelativePos()
{
	return relative;
}

void FontRect::changeSize(const double& size)
{
	this->size = size;
	is_size_changed = true;
}

void FontRect::changeTxt(const String& text)
{
	this->text = text;
}

void FontRect::pollChangePlaceEvent(const double& expansion)
{
	if (text == U"") return;
	transition.update(rectf.mouseOver());
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

void FontRect::move(const double& expansion)
{
	if (text == U"") return;
	if (this->expansion != expansion)
	{
		this->expansion = expansion;
		is_size_changed = true;
	}
	if (is_size_changed)
	{
		font = Font(size * this->expansion);
		is_size_changed = false;
	}
	rectf = RectF(pos + relative * expansion, layout.BTN_F_SIZE, layout.BTN_F_SIZE);
}

void FontRect::draw()
{
	if (text == U"") return;
	auto color = ColorF(palette.r, palette.g * (1 - transition.value()), palette.b, transition.value());
	if (is_pressed)
	{
		rectf.draw(color).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Aqua);
	}
	else
	{
		rectf.draw(color).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Violet);
	}
	font(text).draw(pos + relative * expansion, Palette::Black);
}