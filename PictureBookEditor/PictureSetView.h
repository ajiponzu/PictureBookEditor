#pragma once

#include "MyButton.h"
#include "ViewComponent.h"

class PictureSetView :
    public ViewComponent
{
private:
    std::shared_ptr<MyButton> img_btn1;
    std::shared_ptr<MyButton> img_btn2;
    std::shared_ptr<MyButton> img_btn3;
    bool img_set_flag1 = false;
    bool img_set_flag2 = false;
    bool img_set_flag3 = false;
public:
    PictureSetView(std::shared_ptr<Controller> ctr) : ViewComponent(ctr)
    {
        init();
    }
    ~PictureSetView() {}

    virtual void pollEvent() override;
    virtual void draw() {}
private:
    void init();
};

