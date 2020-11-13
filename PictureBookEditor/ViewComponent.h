#pragma once
#include <Siv3D.hpp>
#include <memory>
#include <vector>

#include "Controller.h"
#include "Layout.h"

class ViewComponent
{	
protected:
	std::shared_ptr<Controller> controller;
	Layout layout;
public:
	ViewComponent(std::shared_ptr<Controller> ctr) : controller(ctr)
	{
		layout = Layout();
	}

	~ViewComponent() {}
	
	virtual void pollEvent() = 0;
};

