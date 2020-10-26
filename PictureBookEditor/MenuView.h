#pragma once

#include "MyButton.h"
#include "ViewComponent.h"

class MenuView :
    public ViewComponent
{
private:
    std::shared_ptr<MyButton> create_btn;
    std::shared_ptr<MyButton> delete_btn;
    std::shared_ptr<MyButton> reset_btn;
    std::shared_ptr<MyButton> save_btn;
    std::shared_ptr<MyButton> run_btn;
public:
    MenuView(std::shared_ptr<Controller> ctr) : ViewComponent(ctr)
    {
        init();
    }
    ~MenuView() {}

    virtual void pollEvent();
    virtual void draw();
private:
    void init();
};

