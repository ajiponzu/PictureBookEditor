#pragma once
#include <Siv3D.hpp>

class Layout
{
public:
	double dpi;
	//view layout
	//layout_x
	int X0;
	int X1;
	int X2;
	int X3;
	int X4;
	int X5;
	int X6;
	int X7;
	int X8;
	int X9;
	int X10;
	int X11;
	int X12;
	//layout_y
	int Y0;
	int Y1;
	int Y2;
	int Y3;
	int Y4;
	int Y5;
	int Y6;
	int Y7;
	int Y8;
	int Y9;
	int Y10;
	int Y11;
	int Y12;
	int Y13;
	int Y14;
	int Y15;
	int Y16;
	int Y17;

	//views special parameter
	int BTN_F_SIZE;
	int BACK_RECT_WID;
	int SLIDER_L_WID;
	int SLIDER_WID;
	//menu_view
	int MENU_BTN_GAP_X;
	int MENU_BTN_WID;
	int MENU_BTN_HIGH;
	int MENU_BAR_TH;
	int CLBTN_X;

	//picture_set_view
	int BTN_WID;
	int BTN_HIGH;
	int BTN_GAP;
	int DBTN_GAP;
	int PICTURE_BACK_RECT_HIGH;

	//scenario_set_view
	int SCENARIO_BACK_RECT_HIGH;

private:

public:
	Layout() {}
	~Layout() {}

	void init();
private:
	void initMenuViewMacro();
	void initPictureSetViewMacro();
	void initScenarioSetViewMacro();
	void initPos();
};
