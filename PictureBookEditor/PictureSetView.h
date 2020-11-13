#pragma once

#include "MyButton.h"
#include "ViewComponent.h"

class PictureSetView : public ViewComponent
{
private:
    std::shared_ptr<MyButton> img_btn1;
    std::shared_ptr<MyButton> img_btn1d;
    std::shared_ptr<MyButton> img_btn2;
    std::shared_ptr<MyButton> img_btn2d;
    std::shared_ptr<MyButton> img_btn3;
    std::shared_ptr<MyButton> img_btn3d;
    std::shared_ptr<MyButton> img_btn4;
    std::shared_ptr<MyButton> img_btn4d;
    bool img_set_flag1 = false;
    bool img_set_flag1d = false;
    bool img_set_flag2 = false;
    bool img_set_flag2d = false;
    bool img_set_flag3 = false;
    bool img_set_flag3d = false;
    bool img_set_flag4 = false;
    bool img_set_flag4d = false;

    double img_size1 = 1.0f;
    double img_size2 = 1.0f;
    double img_size3 = 1.0f;
    double img_size4 = 1.0f;

    double img_alpha1 = 1.0f;
    double img_alpha2 = 1.0f;
    double img_alpha3 = 1.0f;
    double img_alpha4 = 1.0f;

    double img_fade_in1 = 0.0f;
    double img_fade_in2 = 0.0f;
    double img_fade_in3 = 0.0f;
    double img_fade_in4 = 0.0f;

    double img_fade_out1 = 0.0f;
    double img_fade_out2 = 0.0f;
    double img_fade_out3 = 0.0f;
    double img_fade_out4 = 0.0f;

    Rect back_rect;
    int x11 = 0;
    int x12 = 0;
    int y2 = 0;
    int y3 = 0;
    int y4 = 0;
    int y5 = 0;
    int y6 = 0;
    int y7 = 0;
    int y8 = 0;
    int y9 = 0;
    int slider_l_wid = 0;
    int slider_wid = 0;
public:
    PictureSetView(std::shared_ptr<Controller> ctr) : ViewComponent(ctr)
    {
        init();
    }
    ~PictureSetView() {}

    virtual void pollEvent() override;

private:
    void init();
    void initButton();
    void initMacro();
    void pollButtonEvent();
    void pollSliderEvent();
};
