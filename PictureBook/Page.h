#pragma once
#include <Siv3D.hpp>
#include <memory>
#include "BookController.h"

struct BookData
{
	BookController controller;
};

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