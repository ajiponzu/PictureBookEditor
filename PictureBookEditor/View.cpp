#include "View.h"
#include "MenuView.h"
#include "PictureSetView.h"
#include "ScenarioSetView.h"
#include "PageSetView.h"

void View::pollEvent()
{
	calcSceneRatio();
	for (auto itr = vc_list.begin(); itr != vc_list.end(); itr++)
	{
		itr->get()->pollEvent(wid_ratio, high_ratio);
	}
}

void View::draw()
{
	for (auto itr = vc_list.begin(); itr != vc_list.end(); itr++)
	{
		itr->get()->draw();
	}
}

void View::init()
{
	initVcList();
}

void View::initVcList()
{
	auto child0 = std::make_unique<ViewComponent>(MenuView(controller));
	auto child1 = std::make_unique<ViewComponent>(PictureSetView(controller));
	auto child2 = std::make_unique<ViewComponent>(ScenarioSetView(controller));
	auto child3 = std::make_unique<ViewComponent>(PageSetView(controller));
	vc_list.push_back(std::move(child0));
	vc_list.push_back(std::move(child1));
	vc_list.push_back(std::move(child2));
	vc_list.push_back(std::move(child3));
}

void View::calcSceneRatio()
{
	scene_wid = Scene::Width();
	scene_high = Scene::Height();
	wid_ratio = scene_wid / DEFAULT_SCENE_WID;
	high_ratio = scene_high / DEFAULT_SCENE_HIGH;
}
