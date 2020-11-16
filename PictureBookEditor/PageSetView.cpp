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
	initButton();
	initPageView();
	initImgRect();
	initFontRect();
}

void PageSetView::initButton()
{
	prev_btn = std::make_shared<MyButton>(MyButton(layout.X4, layout.Y17, layout.BTN_WID, layout.BTN_HIGH, String(U"ëOï≈"), layout.BTN_F_SIZE));
	next_btn = std::make_shared<MyButton>(MyButton(layout.X8, layout.Y17, layout.BTN_WID, layout.BTN_HIGH, String(U"éüçÄ"), layout.BTN_F_SIZE));
}

void PageSetView::initPageView()
{
	boundary_rect = Rect(0, 0, layout.PAGE_BACK_RECT_WID, layout.PAGE_BACK_RECT_HIGH);
	abs_pos = Vec2(0, 0);
}

void PageSetView::initImgRect()
{
	img_rect_list.push_back(std::make_shared<ImageRect>(ImageRect(U"", Vec2(layout.MOVE_RECT1_POS, layout.MOVE_RECT1_POS))));
	img_rect_list.push_back(std::make_shared<ImageRect>(ImageRect(U"", Vec2(layout.MOVE_RECT2_POS, layout.MOVE_RECT2_POS))));
	img_rect_list.push_back(std::make_shared<ImageRect>(ImageRect(U"", Vec2(layout.MOVE_RECT3_POS, layout.MOVE_RECT3_POS))));
}

void PageSetView::initFontRect()
{
	font_rect_list.push_back(std::make_shared<FontRect>(FontRect(U"font1", Vec2(layout.FONT_RECT1_POS, layout.FONT_RECT1_POS))));
	font_rect_list.push_back(std::make_shared<FontRect>(FontRect(U"font2", Vec2(layout.FONT_RECT2_POS, layout.FONT_RECT2_POS))));
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
	{
		const auto page_view2 = ScopedViewport2D(boundary_rect);
		const Transformer2D transform2(Mat3x2::Translate(back_rect.pos), Mat3x2::Translate(boundary_rect.pos));
		pollMoveRectEvent();
		pollFontRectEvent();
	}
}

void PageSetView::pollZoomEvent()
{
	wheel = static_cast<int>(Mouse::Wheel());
	if (wheel == 1)
	{
		if (expansion >= 0.45)
		{
			expansion /= EXPANSION; 
		}
		else
		{
			expansion = 0.30;
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
		abs_pos += Cursor::Delta();
	}

	if (abs_pos.x + boundary_rect.w < 0)
	{
		abs_pos.x = -boundary_rect.w;
	}
	else if (abs_pos.x > layout.PAGE_BACK_RECT_WID)
	{
		abs_pos.x = layout.PAGE_BACK_RECT_WID;
	}

	if (abs_pos.y + boundary_rect.h < 0)
	{
		abs_pos.y = -boundary_rect.h;
	}
	else if (abs_pos.y > layout.PAGE_BACK_RECT_HIGH)
	{
		abs_pos.y = layout.PAGE_BACK_RECT_HIGH;
	}
}

void PageSetView::pollMoveRectEvent()
{
	for (auto &rect : img_rect_list)
	{
		rect->pollChangePlaceEvent(expansion, boundary_rect.w, boundary_rect.h);
		rect->move(expansion);
		rect->draw();
	}
}

void PageSetView::pollFontRectEvent()
{
	for (auto& rect : font_rect_list)
	{
		rect->pollChangePlaceEvent(expansion, boundary_rect.w, boundary_rect.h);
		rect->move(expansion);
		rect->draw();
	}
}

