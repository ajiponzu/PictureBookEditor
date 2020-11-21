#include "Page.h"

void Page::update()
{
	Print << getData().page;
	if (auto sp = getData().controller.lock())
	{
		if (sp->isBoot())
		{
			initPageInf();
		}
	}
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
	if (auto sp = getData().controller.lock())
	{
		Print << U"init";
		sp->readPage();
		img_inf = sp->returnImgInfArray();
		txt_inf = sp->returnTxtInfArray();
		sp->changeIsBoot(false);
	}
}

void Page::next()
{
		if (auto sp = getData().controller.lock())
		{
			sp->nextPage();
			if (sp->isTransition())
			{
				getData().page++;
				sp->resetIsTransition();
				changeScene(U"Page");
			}
			if (sp->isEnd())
			{
				auto msg = System::ShowMessageBox(U"‚¨‚µ‚Ü‚¢", MessageBoxStyle::Info, MessageBoxButtons::OKCancel);
				if (msg == MessageBoxSelection::OK)
				{
					sp->resetIsEnd();
					System::Exit();
				}
			}
		}
}

void Page::prev()
{
		if (auto sp = getData().controller.lock())
		{
			sp->prevPage();
			if (sp->isTransition())
			{
				sp->changeIsBoot(true);
				changeScene(U"Page");
			}
		}
}
