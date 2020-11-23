#pragma once
///
//���𑜓x�f�B�X�v���C�g�p�̍ہC���L���R�����g�A�E�g
//�������C�ꕔ��gui�p�[�c���������Ȃ�o�O����
//���ƁC���삪�s����ɂȂ�C�ꕔ�̏����������ɂȂ�Ȃǂ̃o�O����
///
//#define SIV3D_WINDOWS_HIGH_DPI
#include <Siv3D.hpp>
#include "BookController.h"
#include "Page.h"

//�A�v���P�[�V�����Ǘ��N���X
class App
{
private:
	int wid = 0;
	int high = 0;
	Book book;
	Rect viewport_rect;
	Array<Size> resolutions;
public:
	App() { init(); }
	~App() {}

	void run();
private:
	void init();
	void setWindowInf();
};
