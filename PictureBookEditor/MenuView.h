#pragma once

#include "ViewComponent.h"

class MenuView :
    public ViewComponent
{
private:
public:
    MenuView(std::shared_ptr<Controller> ctr) : ViewComponent(ctr) {}
    ~MenuView() {}

    virtual void pollEvent(int w_ratio, int h_ratio);
    virtual void draw();
};

