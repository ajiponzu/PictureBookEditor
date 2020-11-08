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
    std::shared_ptr<MyButton> text_btn3;
    std::shared_ptr<MyButton> text_btn3d;
    bool text_set_flag1 = false;
    bool text_set_flag1d = false;
    bool text_set_flag2 = false;
    bool text_set_flag2d = false;
    bool text_set_flag3 = false;
    bool text_set_flag3d = false;

    double text_size1 = 1.0f;
    double text_size2 = 1.0f;
    double text_size3 = 1.0f;

    double text_fade_in1 = 0.0f;
    double text_fade_in2 = 0.0f;
    double text_fade_in3 = 0.0f;

    double text_fade_out1 = 0.0f;
    double text_fade_out2 = 0.0f;
    double text_fade_out3 = 0.0f;

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
    void pollButtonEvent();
    void pollSliderEvent();
};
