#include "App.h"

//アプリケーション開始
void App::run()
{
	while (System::Update())
	{
		view->pollEvent();
	}
}

//コンストラクタから呼ばれる初期化処理
void App::init()
{
	setWindowInf();
	controller = std::make_shared<Controller>(Controller());
	view = std::make_unique<View>(View(controller));
}

//ウィンドウ情報を設定 (タイトル，背景色, 解像度)
//レイアウトの都合上，フルスクリーンに設定
void App::setWindowInf()
{
	Window::SetTitle(U"PictureBookEditor");
	resolutions = Graphics::GetFullscreenResolutions();
	(void)Window::SetFullscreen(true, resolutions[resolutions.size() - 1]);
	Scene::SetScaleMode(ScaleMode::ResizeFill);
	Scene::SetBackground(Palette::Floralwhite);
}