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
	ViewComponent(int w_ratio, int h_ratio, std::shared_ptr<Controller> ctr) : wid_ratio(w_ratio), high_ratio(h_ratio), controller(ctr) {}
	~ViewComponent() {}
	
	virtual void pollEvent() = 0;
	virtual void draw() = 0;
};

