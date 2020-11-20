#include "PageSetView.h"

constexpr auto EXPANSION = 1.5;

void PageSetView::pollEvent()
{
	back_rect.draw(Palette::Lavenderblush).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Lightsalmon);
	{
		const auto page_view = ScopedViewport2D(back_rect);
		const Transformer2D transform(Mat3x2::Identity(), Mat3x2::Translate(back_rect.pos));
		pollGetImgInfEvent();
		pollGetTxtInfEvent();
		pollPagePosEvent();
	}
}

void PageSetView::init()
{
	back_rect = Rect(layout.X1, layout.Y1, layout.PAGE_BACK_RECT_WID, layout.PAGE_BACK_RECT_HIGH);
	if (auto sp = controller.lock())
	{
		sp->readPageJson();
	}
	initPageView();
	initImgRect();
	initFontRect();
}

void PageSetView::initPageView()
{
	boundary_rect = Rect(0, 0, layout.PAGE_BACK_RECT_WID, layout.PAGE_BACK_RECT_HIGH);
	boundary_rect_pos = Vec2::Zero();
}

void PageSetView::initImgRect()
{
	img_rect_list.push_back(std::make_shared<ImageRect>(ImageRect(U"", Vec2(layout.MOVE_RECT1_POS, layout.MOVE_RECT1_POS))));
	img_rect_list.push_back(std::make_shared<ImageRect>(ImageRect(U"", Vec2(layout.MOVE_RECT2_POS, layout.MOVE_RECT2_POS))));
	img_rect_list.push_back(std::make_shared<ImageRect>(ImageRect(U"", Vec2(layout.MOVE_RECT3_POS, layout.MOVE_RECT3_POS))));
}

void PageSetView::initFontRect()
{
	font_rect_list.push_back(std::make_shared<FontRect>(FontRect(U"", Vec2(layout.FONT_RECT1_POS, layout.FONT_RECT1_POS))));
	font_rect_list.push_back(std::make_shared<FontRect>(FontRect(U"", Vec2(layout.FONT_RECT2_POS, layout.FONT_RECT2_POS))));
}

void PageSetView::pollGetImgInfEvent()
{
	pollGetImgInfEvent(0);
	pollGetImgInfEvent(1);
	pollGetImgInfEvent(2);
}

void PageSetView::pollGetImgInfEvent(const int& idx)
{
	if (auto sp = controller.lock())
	{
		auto img_inf_ptr = sp->returnImgInf(idx);
		if (img_inf_ptr != nullptr)
		{
			img_rect_list[idx]->changeSize(img_inf_ptr->size);
			img_rect_list[idx]->changeAlpha(img_inf_ptr->alpha);
			img_rect_list[idx]->changeImg(img_inf_ptr->path);
			img_inf_ptr->flags.flag_s = false;
			img_inf_ptr->flags.flag_a = false;
			img_inf_ptr->flags.flag_p = false;
		}
	}
}

void PageSetView::pollGetTxtInfEvent()
{
	pollGetTxtInfEvent(0);
	pollGetTxtInfEvent(1);
}

void PageSetView::pollGetTxtInfEvent(const int& idx)
{
	if (auto sp = controller.lock())
	{
		auto txt_inf_ptr = sp->returnTxtInf(idx);
		if (txt_inf_ptr != nullptr)
		{
			font_rect_list[idx]->changeSize(txt_inf_ptr->size);
			font_rect_list[idx]->changeTxt(txt_inf_ptr->txt);
			txt_inf_ptr->flags.flag_s = false;
			txt_inf_ptr->flags.flag_t = false;
		}
	}
}

void PageSetView::pollPagePosEvent()
{
	if (back_rect.contains(Cursor::Pos()))
	{
		pollZoomEvent();
		pollChangeBoundaryRectPosEvent();
		boundary_rect = Rect(boundary_rect_pos.x, boundary_rect_pos.y, layout.PAGE_BACK_RECT_WID * expansion, layout.PAGE_BACK_RECT_HIGH * expansion);
	}
	boundary_rect.draw(Palette::White).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Lightsalmon);
	pollMoveRectEvent();
	pollFontRectEvent();
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
		boundary_rect_pos /= EXPANSION;
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
		boundary_rect_pos *= EXPANSION;
	}
}

void PageSetView::pollChangeBoundaryRectPosEvent()
{
	Vec2 delta{};
	if (MouseR.pressed())
	{
		delta = Cursor::Delta();
		boundary_rect_pos += delta;
	}

	if (boundary_rect_pos.x + boundary_rect.w < 0)
	{
		boundary_rect_pos.x = -boundary_rect.w;
		delta = Vec2::Zero();
	}
	else if (boundary_rect_pos.x > layout.PAGE_BACK_RECT_WID)
	{
		boundary_rect_pos.x = layout.PAGE_BACK_RECT_WID;
		delta = Vec2::Zero();
	}

	if (boundary_rect_pos.y + boundary_rect.h < 0)
	{
		boundary_rect_pos.y = -boundary_rect.h;
		delta = Vec2::Zero();
	}
	else if (boundary_rect_pos.y > layout.PAGE_BACK_RECT_HIGH)
	{
		boundary_rect_pos.y = layout.PAGE_BACK_RECT_HIGH;
		delta = Vec2::Zero();
	}

	for (auto& img : img_rect_list)
	{
		img->pos = boundary_rect_pos;
	}
	for (auto& font : font_rect_list)
	{
		font->pos = boundary_rect_pos;
	}
}

void PageSetView::pollMoveRectEvent()
{
	for (auto& rect : img_rect_list)
	{
		rect->pollChangePosEvent(expansion);
		rect->move(expansion);
		rect->draw();
	}
}

void PageSetView::pollFontRectEvent()
{
	for (auto& rect : font_rect_list)
	{
		rect->pollChangePlaceEvent(expansion);
		rect->move(expansion);
		rect->draw();
	}
}