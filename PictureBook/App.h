#pragma once
//#define SIV3D_WINDOWS_HIGH_DPI
#include <Siv3D.hpp>
#include "BookController.h"
#include "Page.h"

class App
{
private:
	int wid = 0;
	int high = 0;
	Book book;
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
