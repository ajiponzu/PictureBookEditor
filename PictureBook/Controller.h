#pragma once
#include <memory>
#include <Siv3D.hpp>
#include "Inf.h"

//内部処理クラス
class Controller
{
protected:
	bool is_boot = true;
	int cur_page = 1;
	int max_page = 1;
	Vec2 base_pos;
	String path;
	Array<ImgInf> img_inf;
	Array<TxtInf> txt_inf;
public:
	Controller()
	{
		init();
	}
	~Controller()
	{
		//無効にしないと，Editorから起動したとき，一時ファイルが削除されてしまう
		//deleteTempJson();
	}

	int returnCurrentPage();
	int returnMaxPage();;
	void initReadPage();
	void createPage();
	void deletePage();
	void savePage();
	void resetPage();
	void nextPage();
	void prevPage();
	void runBook();

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
protected:
	void init();
	void setInitFlag();
	void makeReadFilePath();
	void makeReadFilePath(const int&);
	void makeFilePath();
	void makeFilePath(const int&);
	void makeTempPath();
	void makeTempPath(const int&);
	void writePageJson();
	void readPageJson();
	void deleteTempJson();
};