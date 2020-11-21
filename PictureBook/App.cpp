#include "App.h"

void App::run()
{
	while (System::Update())
	{
	}
}

void App::init()
{
	setWindowInf();
	controller = std::make_shared<BookController>(BookController());
}

void App::setWindowInf()
{
	Window::SetTitle(U"PictureBookEditor");
	resolutions = Graphics::GetFullscreenResolutions();
	(void)Window::SetFullscreen(true, resolutions[resolutions.size() - 1]);
	Scene::SetScaleMode(ScaleMode::ResizeFill);
	Scene::SetBackground(Palette::White);
}