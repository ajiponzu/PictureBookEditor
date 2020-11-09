#pragma once

#include "MyButton.h"
#include "ViewComponent.h"

class PageSetView : public ViewComponent
{
private:
    Rect back_rect;

    std::shared_ptr<MyButton> prev_btn;
    std::shared_ptr<MyButton> next_btn;
    bool prev_flag = false;
    bool next_flag = false;

    Vec2 absolute_pos;
    Vec2 place;
    Vec2 cur_pos;
    Point delta;
    RectF rectf;
    Font font;
    bool isPressed = false;
    double expansion = 1.0;
    int wheel = 0;

    int max_x = 0;
    int max_y = 0;
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
    void initPageView();
    void pollButtonEvent();
    void pollPageEvent();
    void pollChangeAbsPosEvent();
    void pollChangePlaceEvent();
    void pollZoomEvent();
    void pollMoveRectEvent();
};

