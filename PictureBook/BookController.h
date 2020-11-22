#pragma once
#include "Controller.h"
#include "Layout.h"

class BookController : public Controller
{
private:
	double ratio_x = 0.0;
	double ratio_y = 0.0;
	double ratio = 0.0;
	bool is_transition = false;
	bool is_end = false;
	Layout layout{};
public:
	BookController() : Controller() { initRatio(); }
	~BookController() {}

	bool isBoot();
	bool isTransition();
	bool isEnd();
	void changeIsBoot(const bool&);
	void resetIsTransition();
	void resetIsEnd();
	void readPage();
	void prevPage();
	void nextPage();
	Array<ImgInf> returnImgInfArray();
	Array<TxtInf> returnTxtInfArray();
private:
	void initRatio();
	void changePos();
};
