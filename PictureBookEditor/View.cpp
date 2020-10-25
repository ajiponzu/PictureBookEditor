#include "View.h"
#include "MenuView.h"
#include "PictureSetView.h"
#include "ScenarioSetView.h"
#include "PageSetView.h"

void View::pollEvent()
{
	calcSceneRatio();
	for (auto vc : vc_list)
	{
		vc->pollEvent(wid_ratio, high_ratio);
	}
}

void View::draw()
{
	for (auto vc : vc_list)
	{
		vc->draw();
	}
}

void View::init()
{
	initVcList();
}

void View::initVcList()
{
	vc_list.push_back(std::make_shared<MenuView>(MenuView(controller)));
	vc_list.push_back(std::make_shared<PictureSetView>(PictureSetView(controller)));
	vc_list.push_back(std::make_shared<ScenarioSetView>(ScenarioSetView(controller)));
	vc_list.push_back(std::make_shared<PageSetView>(PageSetView(controller)));
}

void View::calcSceneRatio()
{
	scene_wid = Scene::Width();
	scene_high = Scene::Height();
	wid_ratio = scene_wid / DEFAULT_SCENE_WID;
	high_ratio = scene_high / DEFAULT_SCENE_HIGH;
}
