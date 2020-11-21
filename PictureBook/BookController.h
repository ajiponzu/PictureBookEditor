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
};
