#pragma once

//�摜��񂪕ύX���ꂽ���Ƃ�ʒm���邽�߂̃t���O
struct ImgInfFlag
{
	bool flag_s = false;
	bool flag_a = false;
	bool flag_p = false;

	//�ύX���������ꍇtrue
	bool eventFlag()
	{
		return flag_s || flag_a || flag_p;
	}

	//�������������邽�߂ɁC�S��true
	void reInit()
	{
		flag_s = true;
		flag_a = true;
		flag_p = true;
	}
};

//�摜���
struct ImgInf
{
	double size = 1.0;
	double alpha = 1.0;
	double fadein = 0.0;
	ImgInfFlag flags;
	String path;
	Vec2 pos;
};

//������񂪕ύX���ꂽ���Ƃ�ʒm���邽�߂̃t���O
struct TxtInfFlag
{
	bool flag_s = false;
	bool flag_t = false;

	bool eventFlag()
	{
		return flag_s || flag_t;
	}

	void reInit()
	{
		flag_s = true;
		flag_t = true;
	}
};

//�������
struct TxtInf
{
	double size = 60.0;
	double fadein = 0.0;
	TxtInfFlag flags;
	String txt;
	Vec2 pos;
};