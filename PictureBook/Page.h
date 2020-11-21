#pragma once
#include <Siv3D.hpp>
#include <memory>
#include "BookController.h"

struct BookData
{
	std::weak_ptr<BookController> controller;
	int page = 1;
};

using Book = SceneManager<String, BookData>;

class Page : public Book::Scene
{
private:
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
	void next();
	void prev();
};
