#pragma once
#include <Siv3D.hpp>
#include "Layout.h"

class ImageRect
{
public:
	Vec2 pos;
private:
	Vec2 relative;
	Layout layout{};
	RectF rectf{};
	Texture img;
	String path{};
	bool is_pressed = false;
	double size = 1.0;
	double alpha = 1.0;
	double expansion = 0.0;
public:
	ImageRect(const String& path, const Vec2& relative) : relative(relative)
	{
		img = Texture(path);
		this->pos = Vec2::Zero();
	}
	~ImageRect() {}

	void setRelativePos(const Vec2&, const Vec2&);
	Vec2 getRelativePos();
	void changeSize(const double&);
	void changeAlpha(const double&);
	void changeImg(const String&);
	void pollChangePosEvent(const double&);
	void move(const double&);
	void draw();
};
