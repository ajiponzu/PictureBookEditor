#include "BookController.h"

bool BookController::isBoot()
{
	return is_boot;
}

bool BookController::isTransition()
{
	return is_transition;
}

bool BookController::isEnd()
{
	return is_end;
}

void BookController::changeIsBoot(const bool& is_boot)
{
	this->is_boot = is_boot;
}

void BookController::resetIsTransition()
{
	is_transition = false;
}

void BookController::resetIsEnd()
{
	is_end = false;
}

void BookController::readPage()
{
	makeReadFilePath();
	readPageJson();
	changePos();
}

void BookController::prevPage()
{
	cur_page--;
	if (cur_page <= 0)
	{
		cur_page = 1;
	}
	else
	{
		makeReadFilePath();
		readPageJson();
		is_transition = true;
	}
}

void BookController::nextPage()
{
	cur_page++;
	if (cur_page > max_page)
	{
		cur_page--;
		is_end = true;
	}
	else
	{
		makeReadFilePath();
		readPageJson();
		is_transition = true;
	}
}

Array<ImgInf> BookController::returnImgInfArray()
{
	return img_inf;
}

Array<TxtInf> BookController::returnTxtInfArray()
{
	return txt_inf;
}

void BookController::initRatio()
{
	ratio_x = static_cast<double>(Window::ClientWidth()) / layout.PAGE_BACK_RECT_WID;
	ratio_y = static_cast<double>(Window::ClientHeight()) / layout.PAGE_BACK_RECT_HIGH;
	ratio = ratio_x / ratio_y;
}

void BookController::changePos()
{
	for (auto& inf : img_inf)
	{
		inf.pos.x *= ratio_x;
		inf.pos.y *= ratio_y;
		inf.size /= ratio;
	}
	for (auto& inf : txt_inf)
	{
		inf.pos.x *= ratio_x;
		inf.pos.y *= ratio_y;
		inf.size *= ratio;
	}
}
