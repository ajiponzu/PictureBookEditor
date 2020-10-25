#pragma once
#include <Siv3D.hpp>
#include <memory>

#include "Controller.h"
#include "Model.h"
#include "View.h"

class App
{
private:
	int wid = 0;
	int high = 0;
	std::unique_ptr<View> view = nullptr;
	std::unique_ptr<Model> model = nullptr;
	std::shared_ptr<Controller> controller = nullptr;
public:
	App(int width, int height) : wid(width), high(height)
	{
		init();
	}

	~App() {}
	
	void run();
private:
	void init();
	void setWindowInf();
};

