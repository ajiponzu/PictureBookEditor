#pragma once
#include <Siv3D.hpp>

class ImageRect
{
private:
	RectF rectf;
	Texture img;
	Vec2 place;
	Font pos_inf_font;
	bool is_pressed = false;
public:
	ImageRect(const String& path, const Vec2& place)
	{
		img = Texture(path);
		this->place = place;
		pos_inf_font(60);
	}
	~ImageRect() {}

	Vec2 getPlace();
	void pollChangePlaceEvent(const double&, const int&, const int&);
	void move(const Vec2&, const double&);
	void draw();
};

