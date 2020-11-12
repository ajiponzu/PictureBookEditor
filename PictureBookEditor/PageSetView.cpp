#include "PageSetView.h"

constexpr auto LEFT_X = 40;
constexpr auto TOP_Y = 150;
constexpr auto BACK_WID = 2500;
constexpr auto BACK_HIGH = 1700;
constexpr auto RIGHT_X = LEFT_X + BACK_WID;
constexpr auto BOTTOM_Y = TOP_Y + BACK_HIGH;

constexpr auto B_POS_X = 600;
constexpr auto B_WID = 200;
constexpr auto B_HIGH = 120;
constexpr auto B_GAP = B_WID + 1000;
constexpr auto B_POS_Y = 1950;
constexpr auto F_SIZE = 50;
constexpr auto B_OFFSET = 40;

constexpr auto EXPANSION = 1.5;

void PageSetView::pollEvent()
{
	back_rect.draw(Palette::White).drawFrame(4, 4, Palette::Lightsalmon);
	{
		const auto page_view = ScopedViewport2D(back_rect);
		const Transformer2D transform(Mat3x2::Identity(), Mat3x2::Translate(back_rect.pos));
		pollButtonEvent();
		pollPageEvent();
	}
}

void PageSetView::init()
{
	back_rect = Rect(LEFT_X, TOP_Y, BACK_WID, BACK_HIGH);
	initButton();
	initPageView();
	initImgRect();
}

void PageSetView::initButton()
{
	prev_btn = std::make_shared<MyButton>(MyButton(B_POS_X, B_POS_Y, B_WID, B_HIGH, String(U"ëOï≈"), F_SIZE));
	next_btn = std::make_shared<MyButton>(MyButton(B_POS_X + B_GAP, B_POS_Y, B_WID, B_HIGH, String(U"éüçÄ"), F_SIZE));
}

void PageSetView::initPageView()
{
	max_x = Window::ClientWidth();
	max_y = Window::ClientHeight();
	absolute_pos = Vec2(LEFT_X, TOP_Y);
}

void PageSetView::initImgRect()
{
	img_rect_list.push_back(std::make_shared<ImageRect>(ImageRect(U"", Vec2(50, 50))));
	img_rect_list.push_back(std::make_shared<ImageRect>(ImageRect(U"", Vec2(100, 100))));
	img_rect_list.push_back(std::make_shared<ImageRect>(ImageRect(U"", Vec2(200, 200))));
}

void PageSetView::pollButtonEvent()
{
	if (prev_btn->isClicked())
	{
		Print << U"prev page";
		prev_flag = true;
	}
	if (next_btn->isClicked())
	{
		Print << U"next page";
		next_flag = true;
	}
}

void PageSetView::pollPageEvent()
{	
	pollZoomEvent();
	pollChangeAbsPosEvent();
	pollMoveRectEvent();
	//Print << U"abs: {}, place: {}, max: ({}, {})"_fmt(absolute_pos, place, max_x, max_y);
}

void PageSetView::pollZoomEvent()
{
	wheel = static_cast<int>(Mouse::Wheel());
	if (wheel == 1)
	{
		if (expansion >= 0.25)
		{
			expansion /= EXPANSION; 
		}
		else
		{
			expansion = 0.25;
		}
	}
	else if (wheel == -1)
	{
		if (expansion <= 4)
		{
			expansion *= EXPANSION;
		}
		else
		{
			expansion = 4;
		}
	}
}

void PageSetView::pollChangeAbsPosEvent()
{
	if (MouseR.pressed())
	{
		absolute_pos += Cursor::Delta();
	}
	if (absolute_pos.x < -max_x)
	{
		absolute_pos.x = -max_x;
	}
	else if (absolute_pos.x > max_x)
	{
		absolute_pos.x = max_x;
	}
	if (absolute_pos.y < -max_y)
	{
		absolute_pos.y = -max_y;
	}
	else if (absolute_pos.y > max_y)
	{
		absolute_pos.y = max_y;
	}
}

void PageSetView::pollMoveRectEvent()
{
	for (auto rect : img_rect_list)
	{
		rect->pollChangePlaceEvent(expansion, max_x, max_y);
		cur_pos = absolute_pos + rect->getPlace() * expansion;
		rect->move(cur_pos, expansion);
		rect->draw();
	}
}

