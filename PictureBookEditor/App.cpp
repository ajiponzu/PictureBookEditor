#include "App.h"

void App::run()
{
    while (System::Update())
    {
        viewport_rect.draw(Palette::Floralwhite);
        {
            const ScopedViewport2D viewport(viewport_rect);
            const Transformer2D transform(Mat3x2::Identity(), Mat3x2::Translate(viewport_rect.pos));
            view->pollEvent();
        }
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
    (void)Window::SetFullscreen(true);
    Scene::SetScaleMode(ScaleMode::ResizeFill);
    viewport_rect = Rect(0, 0, Scene::Width(), Scene::Height());
}

