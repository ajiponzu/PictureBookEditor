#include "Page.h"

void Page::update()
{
	if (MouseL.down())
	{
		changeScene(U"Page");
	}
}

void Page::draw() const
{
	Scene::SetBackground(ColorF(Palette::White));
}

void Page::init()
{
	if (auto sp = getData().cotroller.lock())
	{
		img_inf = sp->returnImgInfArray();
		txt_inf = sp->returnTxtInfArray();
	}
}
