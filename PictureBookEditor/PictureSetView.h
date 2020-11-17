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
    bool img_set_flag1 = false;
    bool img_set_flag1d = false;
    bool img_set_flag2 = false;
    bool img_set_flag2d = false;
    bool img_set_flag3 = false;
    bool img_set_flag3d = false;

    double img_size1 = 1.0;
    double img_size2 = 1.0;
    double img_size3 = 1.0;

    double img_alpha1 = 1.0;
    double img_alpha2 = 1.0;
    double img_alpha3 = 1.0;

    double img_fade_in1 = 0.0;
    double img_fade_in2 = 0.0;
    double img_fade_in3 = 0.0;

    Rect back_rect;
public:
    PictureSetView(std::weak_ptr<Controller> ctr) : ViewComponent(ctr)
    {
        init();
    }
    ~PictureSetView() {}

    virtual void pollEvent() override;

private:
    void init();
    void initButton();
    void pollButtonEvent();
    void pollSliderEvent();
};
