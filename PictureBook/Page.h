#pragma once
#include <Siv3D.hpp>
#include <memory>
#include "BookController.h"

struct BookData
{
	std::weak_ptr<BookController> cotroller;
};

using Book = SceneManager<String, BookData>;

class Page : Book::Scene
{
private:
	Array<ImgInf> img_inf;
	Array<TxtInf> txt_inf;
public:
	Page(const InitData& init_data) : IScene(init_data)
	{
		init();
	}
	~Page() {}

	void update() override;
	void draw() const override;
private:
	void init();
};
