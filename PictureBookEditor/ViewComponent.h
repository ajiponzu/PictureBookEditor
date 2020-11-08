#pragma once
#define SIV3D_WINDOWS_HIGH_DPI
#include <Siv3D.hpp>
#include <memory>
#include <vector>

#include "Controller.h"

class ViewComponent
{	
protected:
	std::shared_ptr<Controller> controller;
public:
	ViewComponent(std::shared_ptr<Controller> ctr) : controller(ctr) {}
	~ViewComponent() {}
	
	virtual void pollEvent() = 0;
};

