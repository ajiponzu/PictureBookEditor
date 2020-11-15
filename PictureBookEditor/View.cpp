#include "View.h"
#include "MenuView.h"
#include "PictureSetView.h"
#include "ScenarioSetView.h"
#include "PageSetView.h"

void View::pollEvent()
{
	for (auto vc : vc_list)
	{
		vc->pollEvent();
	}
}

void View::init()
{
	initVcList();
}

void View::initVcList()
{
	vc_list.push_back(std::make_shared<PageSetView>(PageSetView(controller)));
	vc_list.push_back(std::make_shared<MenuView>(MenuView(controller)));
	vc_list.push_back(std::make_shared<PictureSetView>(PictureSetView(controller)));
	vc_list.push_back(std::make_shared<ScenarioSetView>(ScenarioSetView(controller)));
}

