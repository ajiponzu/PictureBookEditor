#include "FontRect.h"

void FontRect::changeSize(const double& size)
{
	this->size = size;
	is_size_changed = true;
}

void FontRect::changeTxt(const String& text)
{
	this->text = text;
	is_size_changed = true;
}

void FontRect::pollChangePlaceEvent(const double& expansion)
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
		relative += Cursor::Delta() / expansion;
	}
}

void FontRect::move(const double& expansion)
{
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
	rectf = RectF(relative * expansion, layout.BTN_F_SIZE, layout.BTN_F_SIZE);
}

void FontRect::draw()
{
	if (text != U"")
	{
		if (is_pressed)
		{
			rectf.draw(AlphaF(0)).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Aqua);
		}
		else
		{
			rectf.draw(AlphaF(0)).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Violet);
		}
		font(text).draw(relative * expansion, Palette::Black);
	}
}