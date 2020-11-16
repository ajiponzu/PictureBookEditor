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
    bool input_flag1 = false;
    bool input_flag2 = false;
    bool text_set_flag1 = false;
    bool text_set_flag1d = false;
    bool text_set_flag2 = false;
    bool text_set_flag2d = false;
    double text_size1 = 1.0f;
    double text_size2 = 1.0f;
    double text_fade_in1 = 0.0f;
    double text_fade_in2 = 0.0f;

    Rect back_rect;

public:
    ScenarioSetView(std::shared_ptr<Controller> ctr) : ViewComponent(ctr)
    {
        init();
    }
    ~ScenarioSetView() {}

    virtual void pollEvent() override;

private:
    void init();
    void initButton();
    void initInput();
    void pollButtonEvent();
    void pollSliderEvent();
    void pollInputEvent();
};
