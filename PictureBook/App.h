#pragma once
//#define SIV3D_WINDOWS_HIGH_DPI
#include <Siv3D.hpp>
#include <memory>
#include "BookController.h"
#include "Page.h"

class App
{
private:
	std::shared_ptr<BookController> controller = nullptr;
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
