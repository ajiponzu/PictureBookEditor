#pragma once

struct ImgInfFlag
{
	bool flag_s = false;
	bool flag_a	 = false;
	bool flag_p = false;

	bool eventFlag()
	{
		return flag_s || flag_a || flag_p;
	}
};

struct ImgInf
{
	double size = 0.0;
	double alpha = 0.0;
	double fadein = 0.0;
	ImgInfFlag flags;
	String path;
};

struct TxtInfFlag
{
	bool flag_s = false;
	bool flag_t = false;

	bool eventFlag()
	{
		return flag_s || flag_t;
	}
};

struct TxtInf
{
	double size = 0.0;
	double fadein = 0.0;
	TxtInfFlag flags;
	String txt;
};

