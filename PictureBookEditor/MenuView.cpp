#include "MenuView.h"

void MenuView::pollEvent()
{
	if (create_btn->isClicked(wid_ratio, high_ratio))
	{
		Print << U"hello";
	}
}

void MenuView::draw()
{
}

void MenuView::init()
{
	create_btn = std::make_shared<MyButton>(MyButton(50, 50, 100, 100, String(U"V‹K"), 30));
}
