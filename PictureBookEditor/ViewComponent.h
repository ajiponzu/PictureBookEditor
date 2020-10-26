#pragma once
#define SIV3D_WINDOWS_HIGH_DPI
#include <Siv3D.hpp>
#include <memory>
#include <vector>

#include "Controller.h"

class ViewComponent
{	
protected:
	static int wid_ratio;
	static int high_ratio;
	std::shared_ptr<Controller> controller;
public:
	ViewComponent(std::shared_ptr<Controller> ctr) : controller(ctr) {}
	~ViewComponent() {}
	
	virtual void pollEvent() = 0;
	virtual void draw() = 0;
	
	static void changeRatio(int& w_ratio, int& h_ratio)
	{
		wid_ratio = w_ratio;
		high_ratio = h_ratio;
	}
};

