#include "PageSetView.h"

constexpr auto EXPANSION = 1.5;

void PageSetView::pollEvent()
{
	pollButtonEvent();
	back_rect.draw(Palette::Lavenderblush).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Lightsalmon);
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
	boundary_rect = Rect(0, 0, layout.PAGE_BACK_RECT_WID, layout.PAGE_BACK_RECT_HIGH);
	initButton();
	initPageView();
	initImgRect();
}

void PageSetView::initButton()
{
	prev_btn = std::make_shared<MyButton>(MyButton(layout.X4, layout.Y17, layout.BTN_WID, layout.BTN_HIGH, String(U"ëOï≈"), layout.BTN_F_SIZE));
	next_btn = std::make_shared<MyButton>(MyButton(layout.X8, layout.Y17, layout.BTN_WID, layout.BTN_HIGH, String(U"éüçÄ"), layout.BTN_F_SIZE));
}

void PageSetView::initPageView()
{
	max_x = Window::ClientWidth();
	max_y = Window::ClientHeight();
	abs_pos = Vec2(0, 0);
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
	if (back_rect.contains(Cursor::Pos()))
	{
		pollZoomEvent();
		pollChangeAbsPosEvent();
		boundary_rect = Rect(abs_pos.x, abs_pos.y, layout.PAGE_BACK_RECT_WID * expansion, layout.PAGE_BACK_RECT_HIGH * expansion);
	}
	boundary_rect.draw(Palette::White).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Lightsalmon);
	pollMoveRectEvent();
}

void PageSetView::pollZoomEvent()
{
	wheel = static_cast<int>(Mouse::Wheel());
	if (wheel == 1)
	{
		if (expansion >= 0.35)
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
		if (expansion <= 2)
		{
			expansion *= EXPANSION;
		}
		else
		{
			expansion = 3;
		}
	}
}

void PageSetView::pollChangeAbsPosEvent()
{
	if (MouseR.pressed())
	{
		pre_abs_pos = abs_pos;
		abs_pos += Cursor::Delta();
	}
	boundary_center_pos = boundary_rect.center();
	if (boundary_center_pos.x <  0 || boundary_center_pos.x > layout.BACK_RECT_WID)
	{
		abs_pos = pre_abs_pos;
	}
	if (boundary_center_pos.y < 0 || boundary_center_pos.y > layout.PAGE_BACK_RECT_HIGH)
	{
		abs_pos = pre_abs_pos;
	}
}

void PageSetView::pollMoveRectEvent()
{
	for (auto rect : img_rect_list)
	{
		rect->pollChangePlaceEvent(expansion, abs_pos.x + boundary_rect.w, abs_pos.y + boundary_rect.h);
		cur_pos = abs_pos + rect->getPlace() * expansion;
		rect->move(cur_pos, expansion);
		rect->draw();
	}
}

