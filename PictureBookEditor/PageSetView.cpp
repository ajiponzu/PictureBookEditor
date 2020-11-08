#include "PageSetView.h"

constexpr auto LEFT_X = 40;
constexpr auto TOP_Y = 150;
constexpr auto BACK_WID = 2500;
constexpr auto BACK_HIGH = 1700;

constexpr auto B_POS_X = 600;
constexpr auto B_WID = 200;
constexpr auto B_HIGH = 120;
constexpr auto B_GAP = B_WID + 1000;
constexpr auto B_POS_Y = 1950;
constexpr auto F_SIZE = 50;
constexpr auto B_OFFSET = 40;

void PageSetView::pollEvent()
{
	back_rect.draw(Palette::White).drawFrame(4, 4, Palette::Lightsalmon);
	pollButtonEvent();
}

void PageSetView::init()
{
	back_rect = Rect(LEFT_X, TOP_Y, BACK_WID, BACK_HIGH);
	initButton();
}

void PageSetView::initButton()
{
	prev_btn = std::make_shared<MyButton>(MyButton(B_POS_X, B_POS_Y, B_WID, B_HIGH, String(U"‘O•Å"), F_SIZE));
	next_btn = std::make_shared<MyButton>(MyButton(B_POS_X + B_GAP, B_POS_Y, B_WID, B_HIGH, String(U"ŽŸ€"), F_SIZE));
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

