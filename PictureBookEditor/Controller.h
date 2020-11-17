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
	ImgInf* returnImgInf(const int&);
private:
	void init();
};

