#include "Controller.h"

void Controller::selectImg(const int& idx)
{
	if (const auto open = Dialog::OpenFile())
	{
		img_path[idx-1] = open.value();
	}
}

String Controller::returnImgPath(const int& idx)
{
	return img_path[idx-1];
}

void Controller::init()
{
	img_path.push_back(U"");
	img_path.push_back(U"");
	img_path.push_back(U"");
}
