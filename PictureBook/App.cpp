#include "App.h"

//アプリケーション開始
void App::run()
{
	while (System::Update())
	{
		viewport_rect.draw(Palette::White);
		//見切れても，描画がまるごとキャンセルされないように
		{
			const ScopedViewport2D viewport(viewport_rect);
			const Transformer2D transform(Mat3x2::Identity(), Mat3x2::Translate(viewport_rect.pos));
			if (!book.update()) break;
		}
	}
}

//コンストラクタから呼ばれる初期化処理
void App::init()
{
	setWindowInf();
	viewport_rect = Rect(0, 0, wid, high);
	book.add<Page>(U"Page");
}

//ウィンドウ情報を設定 (タイトル，背景色, 解像度)
//レイアウトの都合上，フルスクリーンに設定
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