#pragma once
#include <Siv3D.hpp>
#include <memory>
#include "BookController.h"

//ページ間で共通のデータ，ファイルからページ情報を読み込んだりするのに使う
struct BookData
{
	BookController controller;
};

//シーンマネージャー
using Book = SceneManager<String, BookData>;

class Page : public Book::Scene
{
private:
	Array<Font> txt;
	Array<Texture> img;
	Array<ImgInf> img_inf;
	Array<TxtInf> txt_inf;
public:
	Page(const InitData& init) : IScene(init)
	{
		initPageInf();
	}
	~Page() {}

	void update() override;
	void draw() const override;
	void drawFadeIn(double) const override {};
	void drawFadeOut(double) const override {};
private:
	void initPageInf();
	void initImg();
	void initTxt();
	void drawImg() const;
	void drawTxt() const;
	void next();
	void prev();
	void resetStopWatch();
};