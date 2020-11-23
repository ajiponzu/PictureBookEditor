#include "App.h"

//�A�v���P�[�V�����J�n
void App::run()
{
	while (System::Update())
	{
		viewport_rect.draw(Palette::White);
		//���؂�Ă��C�`�悪�܂邲�ƃL�����Z������Ȃ��悤��
		{
			const ScopedViewport2D viewport(viewport_rect);
			const Transformer2D transform(Mat3x2::Identity(), Mat3x2::Translate(viewport_rect.pos));
			if (!book.update()) break;
		}
	}
}

//�R���X�g���N�^����Ă΂�鏉��������
void App::init()
{
	setWindowInf();
	viewport_rect = Rect(0, 0, wid, high);
	book.add<Page>(U"Page");
}

//�E�B���h�E����ݒ� (�^�C�g���C�w�i�F, �𑜓x)
//���C�A�E�g�̓s����C�t���X�N���[���ɐݒ�
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