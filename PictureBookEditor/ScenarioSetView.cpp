#include "ScenarioSetView.h"

void ScenarioSetView::pollEvent()
{
	back_rect.draw(Palette::Whitesmoke).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Lightsalmon);
	pollButtonEvent();
	pollSliderEvent();
	pollInputEvent();
}

void ScenarioSetView::init()
{
	layout.init();
	back_rect = Rect(layout.X9, layout.Y11, layout.BACK_RECT_WID, layout.SCENARIO_BACK_RECT_HIGH);
	initButton();
	initInput();
}

void ScenarioSetView::initButton()
{
	text_btn1 = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y12, layout.BTN_WID, layout.BTN_HIGH, String(U"文字"), layout.BTN_F_SIZE));
	text_btn1d = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y13, layout.BTN_WID, layout.BTN_HIGH, String(U"削除"), layout.BTN_F_SIZE));
	text_btn2 = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y15, layout.BTN_WID, layout.BTN_HIGH, String(U"文字"), layout.BTN_F_SIZE));
	text_btn2d = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y16, layout.BTN_WID, layout.BTN_HIGH, String(U"削除"), layout.BTN_F_SIZE));
}

void ScenarioSetView::initInput()
{
	input_font1 = Font(layout.BTN_F_SIZE);
	input_font2 = Font(layout.BTN_F_SIZE);
	input_text1 = String(U"");
	input_text2 = String(U"");
	input_rect1 = Rect(layout.X10, layout.Y14, layout.INPUT_ARER_WID, layout.INPUT_AREA_HIGH);
	input_rect2 = Rect(layout.X10, layout.Y18, layout.INPUT_ARER_WID, layout.INPUT_AREA_HIGH);
	palette1 = Palette::Lightsalmon;
	palette2 = Palette::Lightsalmon;
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

	if (SimpleGUI::Slider(U"サイズ ", text_size2, 0.0, 10.0, Vec2(layout.X11, layout.Y15), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		Print << U"text2_size was changed";
	}
	if (SimpleGUI::Slider(U"フェードイン {:.2f} "_fmt(text_fade_in2), text_fade_in2, 0.0, 60.0, Vec2(layout.X11, layout.Y16), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		Print << U"text2_fade_in was changed";
	}
}

void ScenarioSetView::pollInputEvent()
{
        input_rect1.draw(Palette::White).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, palette1);
		if (input_rect1.leftClicked())
		{
			input_flag1 = !input_flag1;
		}
		if (input_flag1)
		{
			input_flag2 = false;
			palette1 = Palette::Aqua;
			TextInput::UpdateText(input_text1);
		}
		else
		{
			palette1 = Palette::Lightsalmon;
		}
        input_font1(input_text1).draw(input_rect1.stretched(1), Palette::Black);

		input_rect2.draw(Palette::White).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, palette2);
		if (input_rect2.leftClicked())
		{
			input_flag2 = !input_flag2;
		}
		if (input_flag2)
		{
			input_flag1 = false;
			palette2 = Palette::Aqua;
			TextInput::UpdateText(input_text2);
		}
		else
		{
			palette2 = Palette::Lightsalmon;
		}
        input_font2(input_text2).draw(input_rect2.stretched(1), Palette::Black);
}

