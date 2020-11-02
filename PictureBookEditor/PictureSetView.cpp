#include "PictureSetView.h"

constexpr auto B_POS_X = 2200;
constexpr auto B_WID = 120;
constexpr auto B_HIGH = 80;
constexpr auto B_GAP = B_HIGH + 60;
constexpr auto B_POS_Y = 170;
constexpr auto F_SIZE = 50;
constexpr auto B_OFFSET = 40;

void PictureSetView::pollEvent()
{
	if (img_btn1->isClicked())
	{
		Print << U"img1";
		img_set_flag1 = true;
	}
	if (img_btn2->isClicked())
	{
		Print << U"img2";
		img_set_flag2 = true;
	}
	if (img_btn3->isClicked())
	{
		Print << U"img3";
		img_set_flag3 = true;
	}
}

void PictureSetView::init()
{
	auto img1_y = B_POS_Y;
	auto img2_y = img1_y + B_GAP;
	auto img3_y = img2_y + B_GAP;
	img_btn1 = std::make_shared<MyButton>(MyButton(B_POS_X, img1_y, B_WID, B_HIGH, String(U"‰æ‘œ"), F_SIZE));
	img_btn2 = std::make_shared<MyButton>(MyButton(B_POS_X, img2_y, B_WID, B_HIGH, String(U"‰æ‘œ"), F_SIZE));
	img_btn3 = std::make_shared<MyButton>(MyButton(B_POS_X, img3_y, B_WID, B_HIGH, String(U"‰æ‘œ"), F_SIZE));
}
