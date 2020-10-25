#pragma once
#include "ViewComponent.h"
class PageSetView :
    public ViewComponent
{
private:
public:
    PageSetView(std::shared_ptr<Controller> ctr) : ViewComponent(ctr) {}
    ~PageSetView() {}

    virtual void pollEvent(int w_ratio, int h_ratio);
    virtual void draw();
};

