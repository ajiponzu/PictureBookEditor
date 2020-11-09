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
	pollButtonEvent();
	pollPageEvent();
}

void PageSetView::init()
{
	back_rect = Rect(LEFT_X, TOP_Y, BACK_WID, BACK_HIGH);
	initButton();
	initPageView();
}

void PageSetView::initButton()
{
	prev_btn = std::make_shared<MyButton>(MyButton(B_POS_X, B_POS_Y, B_WID, B_HIGH, String(U"‘O•Å"), F_SIZE));
	next_btn = std::make_shared<MyButton>(MyButton(B_POS_X + B_GAP, B_POS_Y, B_WID, B_HIGH, String(U"ŽŸ€"), F_SIZE));
}

void PageSetView::initPageView()
{
	max_x = Window::ClientWidth();
	max_y = Window::ClientHeight();
	absolute_pos = Vec2(LEFT_X, TOP_Y);
	place = Vec2(0, 0);
	font = Font(30);
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
	pollChangePlaceEvent();
	pollChangeAbsPosEvent();
	pollMoveRectEvent();
	rectf.draw(isPressed ? Palette::Red : Palette::Gray);
	font(place).draw(absolute_pos + (place + Vec2(0, -60)) * expansion, Palette::Orange);
	Print << U"abs: {}, place: {}, max: ({}, {})"_fmt(absolute_pos, place, max_x, max_y);
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

void PageSetView::pollChangePlaceEvent()
{
	if (rectf.leftClicked())
	{
		isPressed = true;
	}
	if (MouseL.up())
	{
		isPressed = false;
	}
	if (isPressed)
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

void PageSetView::pollZoomEvent()
{
	wheel = Mouse::Wheel();
	if (wheel == 1)
	{
		if (expansion >= 0.25)
		{
			expansion = expansion / 1.5; 
			absolute_pos = Window::ClientCenter();
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
			expansion = expansion * EXPANSION;
			absolute_pos = Window::ClientCenter();
		}
		else
		{
			expansion = 4;
		}
	}
}

void PageSetView::pollMoveRectEvent()
{
	cur_pos = absolute_pos + place * expansion;
	if (cur_pos.x < LEFT_X || cur_pos.x > RIGHT_X || cur_pos.y < TOP_Y || cur_pos.y > BOTTOM_Y)
	{
		rectf = RectF(Arg::center(-1, -1), 0, 0);
	}
	else
	{
		rectf = RectF(Arg::center(cur_pos), 500 * expansion, 500 * expansion);
	}
}

