#pragma once

#include "MyButton.h"
#include "ViewComponent.h"

class PageSetView : public ViewComponent
{
private:
    std::shared_ptr<MyButton> prev_btn;
    std::shared_ptr<MyButton> next_btn;
    bool prev_flag = false;
    bool next_flag = false;

    Rect back_rect;
public:
    PageSetView(std::shared_ptr<Controller> ctr) : ViewComponent(ctr)
    {
        init();
    }
    ~PageSetView() {}

    virtual void pollEvent() override;
private:
    void init();
    void initButton();
    void pollButtonEvent();
};

