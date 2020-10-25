#pragma once

#include "ViewComponent.h"

class ScenarioSetView :
    public ViewComponent
{
private:
public:
    ScenarioSetView(std::shared_ptr<Controller> ctr) : ViewComponent(ctr) {}
    ~ScenarioSetView() {}

    virtual void pollEvent(int w_ratio, int h_ratio);
    virtual void draw();
};

