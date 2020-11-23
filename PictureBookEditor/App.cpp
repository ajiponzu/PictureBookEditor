#include "App.h"

//�A�v���P�[�V�����J�n
void App::run()
{
	while (System::Update())
	{
		view->pollEvent();
	}
}

//�R���X�g���N�^����Ă΂�鏉��������
void App::init()
{
	setWindowInf();
	controller = std::make_shared<Controller>(Controller());
	view = std::make_unique<View>(View(controller));
}

//�E�B���h�E����ݒ� (�^�C�g���C�w�i�F, �𑜓x)
//���C�A�E�g�̓s����C�t���X�N���[���ɐݒ�
void App::setWindowInf()
{
	Window::SetTitle(U"PictureBookEditor");
	resolutions = Graphics::GetFullscreenResolutions();
	(void)Window::SetFullscreen(true, resolutions[resolutions.size() - 1]);
	Scene::SetScaleMode(ScaleMode::ResizeFill);
	Scene::SetBackground(Palette::Floralwhite);
}