#include "PageSetView.h"

constexpr auto EXPANSION = 1.5;

void PageSetView::pollEvent()
{
	pollButtonEvent();
	back_rect.draw(Palette::White).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Lightsalmon);
	{
		const auto page_view = ScopedViewport2D(back_rect);
		const Transformer2D transform(Mat3x2::Identity(), Mat3x2::Translate(back_rect.pos));
		pollPageEvent();
	}
}

void PageSetView::init()
{
	layout.init();
	back_rect = Rect(layout.X1, layout.Y1, layout.PAGE_BACK_RECT_WID, layout.PAGE_BACK_RECT_HIGH);
	initButton();
	initPageView();
	initImgRect();
}

void PageSetView::initButton()
{
	prev_btn = std::make_shared<MyButton>(MyButton(layout.X4, layout.Y16, layout.BTN_WID, layout.BTN_HIGH, String(U"ëOï≈"), layout.BTN_F_SIZE));
	next_btn = std::make_shared<MyButton>(MyButton(layout.X8, layout.Y16, layout.BTN_WID, layout.BTN_HIGH, String(U"éüçÄ"), layout.BTN_F_SIZE));
}

void PageSetView::initPageView()
{
	max_x = Window::ClientWidth();
	max_y = Window::ClientHeight();
	absolute_pos = Vec2(layout.X1, layout.Y1);
}

void PageSetView::initImgRect()
{
	img_rect_list.push_back(std::make_shared<ImageRect>(ImageRect(U"", Vec2(layout.MOVE_RECT1_POS, layout.MOVE_RECT1_POS))));
	img_rect_list.push_back(std::make_shared<ImageRect>(ImageRect(U"", Vec2(layout.MOVE_RECT2_POS, layout.MOVE_RECT2_POS))));
	img_rect_list.push_back(std::make_shared<ImageRect>(ImageRect(U"", Vec2(layout.MOVE_RECT3_POS, layout.MOVE_RECT3_POS))));
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

