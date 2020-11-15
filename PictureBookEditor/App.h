#pragma once
#define SIV3D_WINDOWS_HIGH_DPI
#include <Siv3D.hpp>
#include <memory>
#include "Controller.h"
#include "Model.h"
#include "View.h"

class App
{
private:
	std::unique_ptr<View> view = nullptr;
	std::unique_ptr<Model> model = nullptr;
	std::shared_ptr<Controller> controller = nullptr;

	Rect viewport_rect;
	Array<Size> resolutions;
public:
	App() { init(); }
	~App() {}
	
	void run();
private:
	void init();
	void setWindowInf();
};

