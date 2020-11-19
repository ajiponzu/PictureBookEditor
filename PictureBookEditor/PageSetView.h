#pragma once

#include "FontRect.h"
#include "ImageRect.h"
#include "MyButton.h"
#include "ViewComponent.h"

class PageSetView : public ViewComponent
{
private:
    Rect back_rect;
    Rect boundary_rect;
    Rect page_rect;

    Vec2 abs_pos;
    Vec2 cur_pos;
    double expansion = 1.0;
    int wheel = 0;

    Font font;

    std::vector<std::shared_ptr<ImageRect>> img_rect_list;
    std::vector<std::shared_ptr<FontRect>> font_rect_list;
public: 
    PageSetView(std::weak_ptr<Controller> ctr) : ViewComponent(ctr)
    {
        init();
    }
    ~PageSetView() {}

    virtual void pollEvent() override;
private:
    void init();
    void initPageView();
    void initImgRect();
    void initFontRect();
    void displayPageNum();
    void pollGetImgInfEvent();
    void pollGetImgInfEvent(const int&);
    void pollGetTxtInfEvent();
    void pollGetTxtInfEvent(const int&);
    void pollPageEvent();
    void pollZoomEvent();
    void pollChangeAbsPosEvent();
    void pollMoveRectEvent();
    void pollFontRectEvent();
};

