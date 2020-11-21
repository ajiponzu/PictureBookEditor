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
}

void Page::initPageInf()
{
	Print << U"init";
	auto& controller = getData().controller;
	controller.readPage();
	img_inf = controller.returnImgInfArray();
	txt_inf = controller.returnTxtInfArray();
	controller.changeIsBoot(false);
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
		auto msg = System::ShowMessageBox(U"‚¨‚µ‚Ü‚¢", MessageBoxStyle::Info, MessageBoxButtons::OKCancel);
		if (msg == MessageBoxSelection::OK)
		{
			controller.resetIsEnd();
			System::Exit();
		}
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