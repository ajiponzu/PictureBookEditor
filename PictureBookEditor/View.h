#pragma once
#include <Siv3D.hpp>
#include <memory>
#include <vector>
#include "Controller.h"
#include "ViewComponent.h"

//ViewComponentä«óùÉNÉâÉX
class View
{
private:
	int scene_wid = 0;
	int scene_high = 0;
	std::shared_ptr<Controller> controller;
	std::vector<std::shared_ptr<ViewComponent>> vc_list;
public:
	View(std::shared_ptr<Controller> ptr) : controller(ptr)
	{
		init();
		scene_wid = Scene::Width();
		scene_high = Scene::Height();
	}
	~View() {}
	virtual void pollEvent();
private:
	void init();
	void initVcList();
};
