#pragma once
#include "MyButton.h"
#include "ViewComponent.h"

//文字情報設定画面管理クラス
class ScenarioSetView : public ViewComponent
{
private:
	std::shared_ptr<MyButton> text_btn1;
	std::shared_ptr<MyButton> text_btn1d;
	std::shared_ptr<MyButton> text_btn2;
	std::shared_ptr<MyButton> text_btn2d;
	std::vector<double> text_size;
	std::vector<double> text_fade_in;
	std::vector<double> input_flag;
	Array<Font> input_font;
	Array<String> input_text;
	Array<Rect> input_rect;
	Array<ColorF> palette;
	Rect back_rect;
public:
	ScenarioSetView(std::weak_ptr<Controller> ctr) : ViewComponent(ctr)
	{
		init();
	}
	~ScenarioSetView() {}

	virtual void pollEvent() override;

private:
	void init();
	void initParameter();
	void initButton();
	void initInput();
	void pollGetTxtInfEvent();
	void pollGetTxtInfEvent(const int&);
	void pollButtonEvent();
	void pollSliderEvent();
	void pollInputEvent();
};
