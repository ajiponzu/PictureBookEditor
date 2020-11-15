#pragma once
#include <Siv3D.hpp>
#include "Layout.h"

class ImageRect
{
private:
	RectF rectf;
	Texture img;
	Vec2 place;
	Vec2 real_place;
	Font pos_inf_font;
	bool is_pressed = false;
	Layout layout;
public:
	ImageRect(const String& path, const Vec2& place)
	{
		img = Texture(path);
		this->place = place;
		real_place = place;
		pos_inf_font(60);
		layout = Layout();
		layout.init();
	}
	~ImageRect() {}

	Vec2 getPlace();
	void pollChangePlaceEvent(const double&, const int&, const int&);
	void move(const double&);
	void draw();
};

