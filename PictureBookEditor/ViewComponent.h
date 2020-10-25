#pragma once
#include <Siv3D.hpp>
#include <memory>

#include "Controller.h"

class ViewComponent
{	
private:
	int wid_ratio = 0;
	int high_ratio = 0;
	std::shared_ptr<Controller> controller;
public:
	ViewComponent(std::shared_ptr<Controller> ctr) : controller(ctr) {}
	~ViewComponent() {}
	
	virtual void pollEvent(int w_ratio, int h_ratio) = 0;
	virtual void draw() = 0;
};

