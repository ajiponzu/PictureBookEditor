#include "Page.h"

void Page::update()
{
	if (MouseL.down())
	{
		next();
	}
	if (MouseR.down())
	{
		prev();
	}
}

void Page::draw() const
{
	Scene::SetBackground(Palette::White);
	drawImg();
	drawText();
}

void Page::initPageInf()
{
	auto& controller = getData().controller;
	controller.readPage();
	img_inf = controller.returnImgInfArray();
	txt_inf = controller.returnTxtInfArray();
	initImg();
	initText();
	controller.changeIsBoot(false);
}

void Page::initImg()
{
	img.resize(3);
	auto idx = 0;
	for (const auto& inf : img_inf)
	{
		img[idx] = Texture(inf.path);
		idx++;
	}
}

void Page::initText()
{
	text.resize(2);
	auto idx = 0;
	for (const auto& inf : txt_inf)
	{
		text[idx] = Font(inf.size);
		idx++;
	}
}

void Page::drawImg() const
{
	auto idx = 0;
	for (const auto& inf : img_inf)
	{
		if (inf.path != U"")
		{
			img[idx].scaled(inf.size).draw(inf.pos, AlphaF(inf.alpha));
		}
		idx++;
	}
}

void Page::drawText() const
{
	auto idx = 0;
	for (const auto& inf : txt_inf)
	{
		if (inf.txt != U"")
		{
			text[idx](inf.txt).draw(inf.pos, Palette::Black);
		}
		idx++;
	}
}

void Page::next()
{
	auto& controller = getData().controller;
	controller.nextPage();
	if (controller.isTransition())
	{
		controller.resetIsTransition();
		changeScene(U"Page");
	}
	if (controller.isEnd())
	{
		//auto msg = System::ShowMessageBox(U"‚¨‚µ‚Ü‚¢", MessageBoxStyle::Info, MessageBoxButtons::OKCancel);
		//if (msg == MessageBoxSelection::OK)
		//{
		//	controller.resetIsEnd();
		//	System::Exit();
		//}
		System::Exit();
	}
}

void Page::prev()
{
	auto& controller = getData().controller;
	controller.prevPage();
	if (controller.isTransition())
	{
		controller.changeIsBoot(true);
		changeScene(U"Page");
	}
}