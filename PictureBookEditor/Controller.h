#pragma once
#include <memory>
#include <Siv3D.hpp>
#include "Inf.h"

class Controller
{
private:
	Array<ImgInf> img_inf;
public:
	Controller() 
	{
		init();
	}
	~Controller() {}
	
	void selectImg(const int&);
	void deleteImg(const int&);
	void changeImgSize(const int&, const double&);
	void changeImgAlpha(const int&, const double&);
	void changeImgFadein(const int&, const double&);
	ImgInf* returnImgInf(const int&);
private:
	void init();
};

