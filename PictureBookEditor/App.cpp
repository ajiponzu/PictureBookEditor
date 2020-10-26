#include "App.h"

void App::run()
{
    while (System::Update())
    {
        view->pollEvent();
        view->draw();
    }
}

void App::init()
{
    setWindowInf();
    controller = std::make_shared<Controller>(Controller());
    view = std::make_unique<View>(View(controller));
    model = std::make_unique<Model>(Model(controller));
}

void App::setWindowInf()
{
    Window::Resize(wid, high);
    Window::SetTitle(U"PictureBookEditor");
     Scene::SetBackground(ColorF(1.0, 1.0, 1.0));
    Window::SetStyle(WindowStyle::Sizable);
    Scene::SetScaleMode(ScaleMode::ResizeFill);
    Window::Maximize();
}

