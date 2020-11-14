#pragma once

#include "ImageRect.h"
#include "MyButton.h"
#include "ViewComponent.h"

class PageSetView : public ViewComponent
{
private:
    Rect back_rect;
    Rect boundary_rect;

    std::shared_ptr<MyButton> prev_btn;
    std::shared_ptr<MyButton> next_btn;
    bool prev_flag = false;
    bool next_flag = false;

    Vec2 abs_pos;
    Vec2 pre_abs_pos;
    Vec2 boundary_center_pos;
    Vec2 cur_pos;
    double expansion = 1.0;
    int wheel = 0;
    
    int max_x = 0;
    int max_y = 0;
    std::vector<std::shared_ptr<ImageRect>> img_rect_list;
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
    void initImgRect();
    void pollButtonEvent();
    void pollPageEvent();
    void pollZoomEvent();
    void pollChangeAbsPosEvent();
    void pollMoveRectEvent();
};

