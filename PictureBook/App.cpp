#include "App.h"

void App::run()
{
	while (System::Update())
	{
		viewport_rect.draw(Palette::White);
		{
			const ScopedViewport2D viewport(viewport_rect);
			const Transformer2D transform(Mat3x2::Identity(), Mat3x2::Translate(viewport_rect.pos));
			if (!book.update()) break;
		}
	}
}

void App::init()
{
	setWindowInf();
	viewport_rect = Rect(0, 0, wid, high);
	book.add<Page>(U"Page");
	auto data = book.get();
	data->controller = std::make_shared<BookController>(BookController());
}

void App::setWindowInf()
{
	Window::SetTitle(U"PictureBookEditor");
	resolutions = Graphics::GetFullscreenResolutions();
	(void)Window::SetFullscreen(true, resolutions[resolutions.size() - 1]);
	Scene::SetScaleMode(ScaleMode::ResizeFill);
	Scene::SetBackground(Palette::White);
	wid = Window::ClientWidth();
	high = Window::ClientHeight();
}