#include "ScenarioSetView.h"

constexpr auto B_POS_X = 2650;
constexpr auto B_WID = 120;
constexpr auto B_HIGH = 80;
constexpr auto B_GAP = B_HIGH + 20;
constexpr auto BD_GAP = 45;
constexpr auto B_POS_Y = 1400;
constexpr auto F_SIZE = 50;
constexpr auto B_OFFSET = 40;

constexpr auto TOP_Y = B_POS_Y - 20;
constexpr auto TXT1_Y = B_POS_Y;
constexpr auto TXT1D_Y = TXT1_Y + B_GAP;
constexpr auto TXT2_Y = TXT1D_Y + B_GAP + BD_GAP;
constexpr auto TXT2D_Y = TXT2_Y + B_GAP;
constexpr auto TXT3_Y = TXT2D_Y + B_GAP + BD_GAP;
constexpr auto TXT3D_Y = TXT3_Y + B_GAP;
constexpr auto BACK_HIGH = TXT3D_Y + 100 - TOP_Y;

constexpr auto LEFT_X = B_POS_X - 50;
constexpr auto LEFT_SLIDER_X = B_WID + B_POS_X + 50;
constexpr auto RIGHT_SLIDER_X = LEFT_SLIDER_X + 500;
constexpr auto SLIDER_LABEL_WID = 200.0;
constexpr auto SLIDER_WID = 250.0;
constexpr auto BACK_WID = RIGHT_SLIDER_X + 500 - LEFT_X;

void ScenarioSetView::pollEvent()
{
	back_rect.draw(Palette::Whitesmoke).drawFrame(4, 4, Palette::Lightsalmon);
	pollButtonEvent();
	pollSliderEvent();
}

void ScenarioSetView::init()
{
	back_rect = Rect(LEFT_X, TOP_Y, BACK_WID, BACK_HIGH);
	initButton();
}

void ScenarioSetView::initButton()
{
	text_btn1 = std::make_shared<MyButton>(MyButton(B_POS_X, TXT1_Y, B_WID, B_HIGH, String(U"文字"), F_SIZE));
	text_btn1d = std::make_shared<MyButton>(MyButton(B_POS_X, TXT1D_Y, B_WID, B_HIGH, String(U"削除"), F_SIZE));
	text_btn2 = std::make_shared<MyButton>(MyButton(B_POS_X, TXT2_Y, B_WID, B_HIGH, String(U"文字"), F_SIZE));
	text_btn2d = std::make_shared<MyButton>(MyButton(B_POS_X, TXT2D_Y, B_WID, B_HIGH, String(U"削除"), F_SIZE));
	text_btn3 = std::make_shared<MyButton>(MyButton(B_POS_X, TXT3_Y, B_WID, B_HIGH, String(U"文字"), F_SIZE));
	text_btn3d = std::make_shared<MyButton>(MyButton(B_POS_X, TXT3D_Y, B_WID, B_HIGH, String(U"削除"), F_SIZE));
}

void ScenarioSetView::pollButtonEvent()
{
	if (text_btn1->isClicked())
	{
		Print << U"text1";
		text_set_flag1 = true;
	}
	if (text_btn1d->isClicked())
	{
		Print << U"text1d";
		text_set_flag1d = true;
	}
	if (text_btn2->isClicked())
	{
		Print << U"text2";
		text_set_flag2 = true;
	}
	if (text_btn2d->isClicked())
	{
		Print << U"text2d";
		text_set_flag2d = true;
	}
	if (text_btn3->isClicked())
	{
		Print << U"text3";
		text_set_flag3 = true;
	}
	if (text_btn3d->isClicked())
	{
		Print << U"text3d";
		text_set_flag3d = true;
	}
}

void ScenarioSetView::pollSliderEvent()
{
	if (SimpleGUI::Slider(U"サイズ {:.2f} "_fmt(text_size1), text_size1, 0.0, 10.0, Vec2(LEFT_SLIDER_X, TXT1_Y), SLIDER_LABEL_WID, SLIDER_WID))
	{
		Print << U"text1_size was changed";
	}
	if (SimpleGUI::Slider(U"フェードイン {:.2f} "_fmt(text_fade_in1), text_fade_in1, 0.0, 60.0, Vec2(LEFT_SLIDER_X, TXT1D_Y), SLIDER_LABEL_WID, SLIDER_WID))
	{
		Print << U"text1_fade_in was changed";
	}
	if (SimpleGUI::Slider(U"フェードアウト {:.2f} "_fmt(text_fade_out1), text_fade_out1, 0.0, 120.0, Vec2(RIGHT_SLIDER_X, TXT1D_Y), SLIDER_LABEL_WID, SLIDER_WID))
	{
		Print << U"text1_fade_out was changed";
	}

	if (SimpleGUI::Slider(U"サイズ {:.2f} "_fmt(text_size2), text_size2, 0.0, 10.0, Vec2(LEFT_SLIDER_X, TXT2_Y), SLIDER_LABEL_WID, SLIDER_WID))
	{
		Print << U"text2_size was changed";
	}
	if (SimpleGUI::Slider(U"フェードイン {:.2f} "_fmt(text_fade_in2), text_fade_in2, 0.0, 60.0, Vec2(LEFT_SLIDER_X, TXT2D_Y), SLIDER_LABEL_WID, SLIDER_WID))
	{
		Print << U"text2_fade_in was changed";
	}
	if (SimpleGUI::Slider(U"フェードアウト {:.2f} "_fmt(text_fade_out2), text_fade_out2, 0.0, 120.0, Vec2(RIGHT_SLIDER_X, TXT2D_Y), SLIDER_LABEL_WID, SLIDER_WID))
	{
		Print << U"text2_fade_out was changed";
	}

	if (SimpleGUI::Slider(U"サイズ {:.2f} "_fmt(text_size3), text_size3, 0.0, 10.0, Vec2(LEFT_SLIDER_X, TXT3_Y), SLIDER_LABEL_WID, SLIDER_WID))
	{
		Print << U"text3_size was changed";
	}
	if (SimpleGUI::Slider(U"フェードイン {:.2f} "_fmt(text_fade_in3), text_fade_in3, 0.0, 60.0, Vec2(LEFT_SLIDER_X, TXT3D_Y), SLIDER_LABEL_WID, SLIDER_WID))
	{
		Print << U"text3_fade_in was changed";
	}
	if (SimpleGUI::Slider(U"フェードアウト {:.2f} "_fmt(text_fade_out3), text_fade_out3, 0.0, 120.0, Vec2(RIGHT_SLIDER_X, TXT3D_Y), SLIDER_LABEL_WID, SLIDER_WID))
	{
		Print << U"text3_fade_out was changed";
	}
}

