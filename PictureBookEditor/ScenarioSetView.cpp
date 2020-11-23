#include "ScenarioSetView.h"

//メインループで呼ばれる処理
void ScenarioSetView::pollEvent()
{
	//背景描画
	back_rect.draw(Palette::Whitesmoke).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Lightsalmon);
	pollGetTxtInfEvent();
	pollButtonEvent();
	pollSliderEvent();
	pollInputEvent();
}

//コンストラクタで呼ばれる初期化処理
void ScenarioSetView::init()
{
	back_rect = Rect(layout.X9, layout.Y11, layout.BACK_RECT_WID, layout.SCENARIO_BACK_RECT_HIGH);
	initParameter();
	initButton();
	initInput();
}

//パラメータ初期化
void ScenarioSetView::initParameter()
{
	input_flag.resize(2);
	text_size.push_back(layout.FONT_SIZE);
	text_size.push_back(layout.FONT_SIZE);
	text_fade_in.push_back(0.0);
	text_fade_in.push_back(0.0);
}

//ボタン作成
void ScenarioSetView::initButton()
{
	text_btn1 = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y12, layout.BTN_WID, layout.BTN_HIGH, String(U"文字"), layout.BTN_F_SIZE));
	text_btn1d = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y13, layout.BTN_WID, layout.BTN_HIGH, String(U"削除"), layout.BTN_F_SIZE));
	text_btn2 = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y15, layout.BTN_WID, layout.BTN_HIGH, String(U"文字"), layout.BTN_F_SIZE));
	text_btn2d = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y16, layout.BTN_WID, layout.BTN_HIGH, String(U"削除"), layout.BTN_F_SIZE));
}

//キーボード入力周辺の初期化
void ScenarioSetView::initInput()
{
	input_text.resize(2);
	input_font.push_back(Font(layout.BTN_F_SIZE));
	input_font.push_back(Font(layout.BTN_F_SIZE));
	input_rect.push_back(Rect(layout.X10, layout.Y14, layout.INPUT_ARER_WID, layout.INPUT_AREA_HIGH));
	input_rect.push_back(Rect(layout.X10, layout.Y18, layout.INPUT_ARER_WID, layout.INPUT_AREA_HIGH));
	palette.push_back(Palette::Lightsalmon);
	palette.push_back(Palette::Lightsalmon);
}

//文字情報取得
void ScenarioSetView::pollGetTxtInfEvent()
{
	pollGetTxtInfEvent(0);
	pollGetTxtInfEvent(1);
}

//文字情報変更の監視
void ScenarioSetView::pollGetTxtInfEvent(const int& idx)
{
	if (auto sp = controller.lock())
	{
		auto inf = sp->returnTxtInf(idx);
		if (inf != nullptr)
		{
			text_size[idx] = inf->size;
			text_fade_in[idx] = inf->fadein;
			input_text[idx] = inf->txt;
		}
	}
}

//文字情報更新ボタンが押されたか
void ScenarioSetView::pollButtonEvent()
{
	if (text_btn1->isClicked())
	{
		if (auto sp = controller.lock())
		{
			sp->changeTxt(0, input_text[0]);
		}
	}
	if (text_btn1d->isClicked())
	{
		if (auto sp = controller.lock())
		{
			sp->deleteTxt(0);
		}
	}
	if (text_btn2->isClicked())
	{
		if (auto sp = controller.lock())
		{
			sp->changeTxt(1, input_text[1]);
		}
	}
	if (text_btn2d->isClicked())
	{
		if (auto sp = controller.lock())
		{
			sp->deleteTxt(1);
		}
	}
}

//スライダーを動かしたか
void ScenarioSetView::pollSliderEvent()
{
	if (SimpleGUI::Slider(U"サイズ ", text_size[0], 0.0, layout.TXT_MAX_SIZE, Vec2(layout.X11, layout.Y12), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		if (auto sp = controller.lock())
		{
			sp->changeTxtSize(0, text_size[0]);
		}
	}
	if (SimpleGUI::Slider(U"フェードイン {:.2f} "_fmt(text_fade_in[0]), text_fade_in[0], 0.0, 60.0, Vec2(layout.X11, layout.Y13), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		if (auto sp = controller.lock())
		{
			sp->changeTxtFadein(0, text_fade_in[0]);
		}
	}

	if (SimpleGUI::Slider(U"サイズ ", text_size[1], 0.0, layout.TXT_MAX_SIZE, Vec2(layout.X11, layout.Y15), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		if (auto sp = controller.lock())
		{
			sp->changeTxtSize(1, text_size[1]);
		}
	}
	if (SimpleGUI::Slider(U"フェードイン {:.2f} "_fmt(text_fade_in[1]), text_fade_in[1], 0.0, 60.0, Vec2(layout.X11, layout.Y16), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		if (auto sp = controller.lock())
		{
			sp->changeTxtFadein(1, text_fade_in[1]);
		}
	}
}

//キーボード入力周辺の処理
void ScenarioSetView::pollInputEvent()
{
	//入力バーは二つ
	if (input_rect[0].mouseOver() || input_rect[1].mouseOver()) Cursor::RequestStyle(CursorStyle::Hand);
	input_rect[0].draw(Palette::White).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, palette[0]);
	//入力バーをクリックすることで，入力モードを切り替え
	if (input_rect[0].leftClicked())
	{
		input_flag[0] = !input_flag[0];
	}
	if (input_flag[0])
	{
		//どちらかが入力モードなら，もう片方をオフに
		input_flag[1] = false;
		palette[0] = Palette::Aqua;
		TextInput::UpdateText(input_text[0]);
	}
	else
	{
		palette[0] = Palette::Lightsalmon;
	}
	input_font[0](input_text[0]).draw(input_rect[0].stretched(1), Palette::Black);

	input_rect[1].draw(Palette::White).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, palette[1]);
	if (input_rect[1].leftClicked())
	{
		input_flag[1] = !input_flag[1];
	}
	if (input_flag[1])
	{
		input_flag[0] = false;
		palette[1] = Palette::Aqua;
		TextInput::UpdateText(input_text[1]);
	}
	else
	{
		palette[1] = Palette::Lightsalmon;
	}
	input_font[1](input_text[1]).draw(input_rect[1].stretched(1), Palette::Black);
}