#pragma once
#include <memory>
#include <Siv3D.hpp>
#include "Inf.h"

class Controller
{
private:
	int cur_page = 1;
	int max_page = 1;
	Vec2 base_pos;
	Array<ImgInf> img_inf;
	Array<TxtInf> txt_inf;
	bool is_boot = true;
public:
	Controller()
	{
		init();
	}
	~Controller() {}

	int returnCurrentPage();
	int returnMaxPage();
	void createPage();
	void deletePage();
	void nextPage();
	void prevPage();
	void writePageJson();
	void readPageJson();

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

	Vec2 returnBasePos();
	void changePos(Vec2&);
	void changePos(const int&, Vec2&);
private:
	void init();
	void setInitFlag();
};
