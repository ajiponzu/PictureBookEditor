#include "ScenarioSetView.h"

void ScenarioSetView::pollEvent()
{
	back_rect.draw(Palette::Whitesmoke).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Lightsalmon);
	pollButtonEvent();
	pollSliderEvent();
}

void ScenarioSetView::init()
{
	layout.init();
	back_rect = Rect(layout.X9, layout.Y11, layout.BACK_RECT_WID, layout.SCENARIO_BACK_RECT_HIGH);
	initButton();
}

void ScenarioSetView::initButton()
{
	text_btn1 = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y12, layout.BTN_WID, layout.BTN_HIGH, String(U"文字"), layout.BTN_F_SIZE));
	text_btn1d = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y13, layout.BTN_WID, layout.BTN_HIGH, String(U"削除"), layout.BTN_F_SIZE));
	text_btn2 = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y14, layout.BTN_WID, layout.BTN_HIGH, String(U"文字"), layout.BTN_F_SIZE));
	text_btn2d = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y15, layout.BTN_WID, layout.BTN_HIGH, String(U"削除"), layout.BTN_F_SIZE));
	text_btn3 = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y16, layout.BTN_WID, layout.BTN_HIGH, String(U"文字"), layout.BTN_F_SIZE));
	text_btn3d = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y18, layout.BTN_WID, layout.BTN_HIGH, String(U"削除"), layout.BTN_F_SIZE));
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
	if (SimpleGUI::Slider(U"サイズ ", text_size1, 0.0, 10.0, Vec2(layout.X11, layout.Y12), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		Print << U"text1_size was changed";
	}
	if (SimpleGUI::Slider(U"フェードイン {:.2f} "_fmt(text_fade_in1), text_fade_in1, 0.0, 60.0, Vec2(layout.X11, layout.Y13), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		Print << U"text1_fade_in was changed";
	}

	if (SimpleGUI::Slider(U"サイズ ", text_size2, 0.0, 10.0, Vec2(layout.X11, layout.Y14), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		Print << U"text2_size was changed";
	}
	if (SimpleGUI::Slider(U"フェードイン {:.2f} "_fmt(text_fade_in2), text_fade_in2, 0.0, 60.0, Vec2(layout.X11, layout.Y15), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		Print << U"text2_fade_in was changed";
	}

	if (SimpleGUI::Slider(U"サイズ ", text_size3, 0.0, 10.0, Vec2(layout.X11, layout.Y16), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		Print << U"text3_size was changed";
	}
	if (SimpleGUI::Slider(U"フェードイン {:.2f} "_fmt(text_fade_in3), text_fade_in3, 0.0, 60.0, Vec2(layout.X11, layout.Y18), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		Print << U"text3_fade_in was changed";
	}
}

