#pragma once

//画像情報が変更されたことを通知するためのフラグ
struct ImgInfFlag
{
	bool flag_s = false;
	bool flag_a = false;
	bool flag_p = false;

	//変更があった場合true
	bool eventFlag()
	{
		return flag_s || flag_a || flag_p;
	}

	//情報を初期化するために，全てtrue
	void reInit()
	{
		flag_s = true;
		flag_a = true;
		flag_p = true;
	}
};

//画像情報
struct ImgInf
{
	double size = 1.0;
	double alpha = 1.0;
	double fadein = 0.0;
	ImgInfFlag flags;
	String path;
	Vec2 pos;
};

//文字情報が変更されたことを通知するためのフラグ
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

//文字情報
struct TxtInf
{
	double size = 60.0;
	double fadein = 0.0;
	TxtInfFlag flags;
	String txt;
	Vec2 pos;
};