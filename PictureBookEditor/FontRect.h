#pragma once
#include <Siv3D.hpp>
#include "Layout.h"

//文字配置に使用する矩形クラス
class FontRect
{
public:
	Vec2 pos;
private:
	bool is_pressed = false;
	bool is_size_changed = false;
	int size = 1;
	double expansion = 0.0;
	Vec2 relative;
	Layout layout{};
	RectF rectf{};
	String text{};
	Font font;
	Transition transition = Transition(0.4s, 0.2s);
	ColorF palette = Palette::Lavender;
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
