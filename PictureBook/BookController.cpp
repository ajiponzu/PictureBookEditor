#include "BookController.h"

//ページ遷移が行われるか
bool BookController::isTransition()
{
	return is_transition;
}

//終わりのページで次ページ遷移を行ったか，つまり終了するか
bool BookController::isEnd()
{
	return is_end;
}

//ページ遷移フラグをfalseに
void BookController::resetIsTransition()
{
	is_transition = false;
}

//終了フラグをfalseに
void BookController::resetIsEnd()
{
	is_end = false;
}

//ファイル読み込み
void BookController::readPage()
{
	makeReadFilePath2();
	readPageJson();
}

//前ページへ
void BookController::prevPage()
{
	cur_page--;
	//不正なページ番号なら
	if (cur_page <= 0)
	{
		//遷移無効
		cur_page = 1;
	}
	else
	{
		//ファイル読み込み
		makeReadFilePath2();
		readPageJson();
		is_transition = true;
	}
}

//次ページへ
void BookController::nextPage()
{
	cur_page++;
	//総ページ数以上なら
	if (cur_page > max_page)
	{
		//遷移無効
		cur_page--;
		is_end = true;
	}
	else
	{
		//ファイル読み込み
		makeReadFilePath2();
		readPageJson();
		is_transition = true;
	}
}

//ファイルパス作成
void BookController::makeReadFilePath2()
{
	//一時ファイルがあったら，そっちを読み込む
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

//画像情報を返す
Array<ImgInf> BookController::returnImgInfArray()
{
	return img_inf;
}

//文字情報を返す
Array<TxtInf> BookController::returnTxtInfArray()
{
	return txt_inf;
}