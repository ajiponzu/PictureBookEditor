#pragma once
#include <Siv3D.hpp>
#include <memory>

#include "Controller.h"

class View
{
private:
	int scene_wid = 0;
	int scene_high = 0;
	std::shared_ptr<Controller> controller;
public:
	View(std::shared_ptr<Controller> ptr) : controller(ptr) {}
	~View() {}
	virtual void pollEvent();
	virtual void draw();
};

