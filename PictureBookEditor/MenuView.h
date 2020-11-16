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
    std::shared_ptr<MyButton> close_btn;
    Rect menu_rect;
    Texture close_btn_img;
public:
    MenuView(std::weak_ptr<Controller> ctr) : ViewComponent(ctr)
    {
        init();
    }
    ~MenuView() {}

    virtual void pollEvent() override;
private:
    void init();
    void initButton();
    void pollButtonEvent();
    void pollCloseEvent();
};

