#pragma once
#include <Siv3D.hpp>
#include "Layout.h"

class ImageRect
{
private:
	RectF rectf;
	Texture img;
	String path;
	Vec2 place;
	Vec2 real_place;
	bool is_pressed = false;
	Layout layout;
	double size = 1.0;
	double alpha = 1.0;
public:
	ImageRect(const String& path, const Vec2& place)
	{
		img = Texture(path);
		this->place = place;
		real_place = place;
		layout = Layout();
		layout.init();
	}
	~ImageRect() {}

	void changeSize(const double&);
	void changeAlpha(const double&);
	void changeImg(const String&);
	Vec2 getPlace();
	void pollChangePlaceEvent(const double&, const int&, const int&);
	void move(const double&);
	void draw();
};

