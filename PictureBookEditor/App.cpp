#include "App.h"

void App::run()
{
    while (System::Update())
    {
        view->pollEvent();
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
    Window::SetTitle(U"PictureBookEditor");
    Scene::SetBackground(Palette::Floralwhite);
    Scene::SetScaleMode(ScaleMode::ResizeFill);
    Window::SetFullscreen(true);
}

