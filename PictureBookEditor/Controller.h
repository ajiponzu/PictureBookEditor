#pragma once
#include <memory>
#include <Siv3D.hpp>
#include "Inf.h"

class Controller
{
private:
	int cur_page = 0;
	int max_page = 0;
	Array<ImgInf> img_inf;
	Array<TxtInf> txt_inf;
public:
	Controller() 
	{
		init();
	}
	~Controller() {}

	int returnCurrentPage();
	int returnMaxPage();
	void createPage();
	void nextPage();
	void prevPage();

	void selectImg(const int&);
	void deleteImg(const int&);
	void changeImgSize(const int&, const double&);
	void changeImgAlpha(const int&, const double&);
	void changeImgFadein(const int&, const double&);
	ImgInf* returnImgInf(const int&);

	void changeTxt(const int&, String&);
	void deleteTxt(const int&);
	void changeTxtSize(const int&, const double&);
	void changeTxtFadein(const int&, const double&);
	TxtInf* returnTxtInf(const int&);
private:
	void init();
};

