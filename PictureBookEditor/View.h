#pragma once
#include <Siv3D.hpp>
#include <memory>
#include <vector>

#include "Controller.h"
#include "ViewComponent.h"

constexpr auto DEFAULT_SCENE_WID = 1280;
constexpr auto DEFAULT_SCENE_HIGH = 720;

class View
{
private:
	int scene_wid = 0;
	int scene_high = 0;
	int wid_ratio = 0;
	int high_ratio = 0;
	std::shared_ptr<Controller> controller;
	std::vector<std::shared_ptr<ViewComponent>> vc_list;
public:
	View(std::shared_ptr<Controller> ptr) : controller(ptr)
	{
		init();
	}
	~View() {}
	virtual void pollEvent();
	virtual void draw();
private:
	void init();
	void initVcList();
	void calcSceneRatio();
};

