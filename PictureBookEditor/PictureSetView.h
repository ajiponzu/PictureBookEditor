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

    std::vector<double> img_size;
    std::vector<double> img_alpha;
    std::vector<double> img_fade_in;

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
    void initParameter();
    void initButton();
    void pollGetImgInfEvent();
    void pollGetImgInfEvent(const int&);
    void pollButtonEvent();
    void pollSliderEvent();
};
