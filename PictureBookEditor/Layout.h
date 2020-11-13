#pragma once
#include <Siv3D.hpp>

class Layout
{
public:
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
	//menu_view
	int MENU_BTN_GAP_X;
	int MENU_BTN_WID;
	int MENU_BTN_HIGH;
	int MENU_BTN_F_SIZE;
	int MENU_BAR_TH;
	int MENU_CLBTN_X;
	double dpi;

	//func
	void init()
	{
		dpi = Graphics::GetDPIScaling();
		X0 = 0;
		X1 = 16 * dpi;
		X2 = 0;
		X3 = 0;
		X4 = 0;
		X5 = 0;
		X6 = 0;
		X7 = 0;
		X8 = 0;
		X9 = 0;
		X10 = 0;
		X11 = 0;
		X12 = 0;

		Y0 = 0;
		Y1 = 0;
		Y2 = 0;
		Y3 = 0;
		Y4 = 0;
		Y5 = 0;
		Y6 = 0;
		Y7 = 0;
		Y8 = 0;
		Y9 = 0;
		Y10 = 0;
		Y11 = 0;
		Y12 = 0;
		Y13 = 0;
		Y14 = 0;
		Y15 = 0;
		Y16 = 0;
		Y17 = 0;

		MENU_BTN_WID = 80 * dpi;
		MENU_BTN_HIGH = 32 * dpi;
		MENU_BTN_GAP_X = MENU_BTN_WID + 8 * dpi;
		MENU_BTN_F_SIZE = 20 * dpi;
		MENU_BAR_TH = MENU_BTN_HIGH + 8 * dpi;
		MENU_CLBTN_X = Window::ClientWidth() - MENU_BAR_TH;
	}
};
