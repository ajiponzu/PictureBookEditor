#include "App.h"
#define DEBUG

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
    resolutions = Graphics::GetFullscreenResolutions();
    (void)Window::SetFullscreen(true, resolutions[resolutions.size()-1]);
    Scene::SetScaleMode(ScaleMode::ResizeFill);
    Scene::SetBackground(Palette::Floralwhite);
}

