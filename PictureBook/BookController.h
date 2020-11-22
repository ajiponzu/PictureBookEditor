#pragma once
#include "Controller.h"

class BookController : public Controller
{
private:
	bool is_transition = false;
	bool is_end = false;
public:
	BookController() : Controller() {}
	~BookController() {}

	bool isTransition();
	bool isEnd();
	void resetIsTransition();
	void resetIsEnd();
	void readPage();
	void prevPage();
	void nextPage();
	Array<ImgInf> returnImgInfArray();
	Array<TxtInf> returnTxtInfArray();
};
