#pragma once

#include "MyButton.h"
#include "ViewComponent.h"

class ScenarioSetView : public ViewComponent
{
private:
    std::shared_ptr<MyButton> text_btn1;
    std::shared_ptr<MyButton> text_btn1d;
    std::shared_ptr<MyButton> text_btn2;
    std::shared_ptr<MyButton> text_btn2d;

    Font input_font1;
    Font input_font2;
    String input_text1;
    String input_text2;
    Rect input_rect1;
    Rect input_rect2;
    ColorF palette1;
    ColorF palette2;

    std::vector<double> input_flag;
    std::vector<double> text_size;
    std::vector<double> text_fade_in;

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
