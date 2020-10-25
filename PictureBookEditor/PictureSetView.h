#pragma once

#include "ViewComponent.h"

class PictureSetView :
    public ViewComponent
{
private:
public:
    PictureSetView(std::shared_ptr<Controller> ctr) : ViewComponent(ctr) {}
    ~PictureSetView() {}

    virtual void pollEvent(int w_ratio, int h_ratio);
    virtual void draw();
};

