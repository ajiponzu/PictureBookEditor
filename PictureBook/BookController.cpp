#include "BookController.h"

bool BookController::isTransition()
{
	return is_transition;
}

bool BookController::isEnd()
{
	return is_end;
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
	makeReadFilePath2();
	readPageJson();
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
		makeReadFilePath2();
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
		makeReadFilePath2();
		readPageJson();
		is_transition = true;
	}
}

void BookController::makeReadFilePath2()
{
	makeTempPath2();
	if (!FileSystem::Exists(path))
	{
		makeFilePath2();
	}
}

void BookController::makeFilePath2()
{
	path = U"page{}.json"_fmt(cur_page);
}

void BookController::makeTempPath2()
{
	path = U"temp{}.json"_fmt(cur_page);
}

Array<ImgInf> BookController::returnImgInfArray()
{
	return img_inf;
}

Array<TxtInf> BookController::returnTxtInfArray()
{
	return txt_inf;
}