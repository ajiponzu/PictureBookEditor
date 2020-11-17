#include "Controller.h"

int Controller::returnCurrentPage()
{
	return cur_page;
}

int Controller::returnMaxPage()
{
	return max_page;
}

void Controller::createPage()
{
	cur_page++;
	max_page++;
}

void Controller::nextPage()
{
	cur_page++;
	if (cur_page > max_page)
	{
		cur_page = max_page;
	}
}

void Controller::prevPage()
{
	cur_page--;
	if (cur_page <= 0)
	{
		cur_page = 1;
	}
}

void Controller::selectImg(const int& idx)
{
	if (const auto open = Dialog::OpenFile())
	{
		img_inf[idx].path = open.value();
		img_inf[idx].flags.flag_p = true;
		Print << img_inf[idx].path;
	}
}

void Controller::deleteImg(const int& idx)
{
	img_inf[idx].path = U"";
	img_inf[idx].flags.flag_p = true;
}

void Controller::changeImgSize(const int& idx, const double& size)
{
	img_inf[idx].size = size;
	img_inf[idx].flags.flag_s = true;
}

void Controller::changeImgAlpha(const int& idx, const double& alpha)
{
	img_inf[idx].alpha = alpha;
	img_inf[idx].flags.flag_a = true;
}

void Controller::changeImgFadein(const int& idx, const double& fadein)
{
	img_inf[idx].fadein = fadein;
}

ImgInf* Controller::returnImgInf(const int& idx)
{
	if (img_inf[idx].flags.eventFlag())
	{
		return &img_inf[idx];
	}

	return nullptr;
}

void Controller::changeTxt(const int& idx, String& txt)
{
	txt_inf[idx].txt = txt;
	txt_inf[idx].flags.flag_t = true;
}

void Controller::deleteTxt(const int& idx)
{
	txt_inf[idx].txt = U"";
	txt_inf[idx].flags.flag_t = true;
}

void Controller::changeTxtSize(const int& idx, const double& size)
{
	txt_inf[idx].size = size;
	txt_inf[idx].flags.flag_s = true;
}

void Controller::changeTxtFadein(const int& idx, const double& fadein)
{
	txt_inf[idx].fadein = fadein;
}

TxtInf* Controller::returnTxtInf(const int& idx)
{
	if (txt_inf[idx].flags.eventFlag())
	{
		return &txt_inf[idx];
	}

	return nullptr;
}

void Controller::init()
{
	img_inf.resize(3);
	txt_inf.resize(2);
}

