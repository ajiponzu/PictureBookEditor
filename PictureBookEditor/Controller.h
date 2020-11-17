#pragma once
#include <memory>
#include <Siv3D.hpp>

class Controller
{
private:
	Array<String> img_path;
public:
	Controller() 
	{
		init();
	}
	~Controller() {}
	
	void selectImg(const int&);
	String returnImgPath(const int&);
private:
	void init();
};

