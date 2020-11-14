#include "Layout.h"

void Layout::init()
{
	dpi = Graphics::GetDPIScaling();

	initMenuViewMacro();
	initPictureSetViewMacro();
	initScenarioSetViewMacro();
	BTN_F_SIZE = 20 * dpi;
	BACK_RECT_WID = 480 * dpi;
	SLIDER_L_WID = 80 * dpi;
	SLIDER_WID = 100 * dpi;
	initPos();
}

void Layout::initMenuViewMacro()
{
	MENU_BTN_WID = 80 * dpi;
	MENU_BTN_HIGH = 32 * dpi;
	MENU_BTN_GAP_X = MENU_BTN_WID + 8 * dpi;
	MENU_BAR_TH = MENU_BTN_HIGH + 8 * dpi;
	CLBTN_X = Window::ClientWidth() - MENU_BAR_TH;
}

void Layout::initPictureSetViewMacro()
{
	BTN_WID = 48 * dpi;
	BTN_HIGH = 32 * dpi;
	BTN_GAP = BTN_HIGH + 8 * dpi;
	DBTN_GAP = 20 * dpi;
	PICTURE_BACK_RECT_HIGH = 400 * dpi;
}

void Layout::initScenarioSetViewMacro()
{
	SCENARIO_BACK_RECT_HIGH = 284 * dpi;
}

void Layout::initPos()
{
	X0 = 0;
	X1 = 16 * dpi;
	X2 = 0;
	X3 = 0;
	X4 = 0;
	X5 = 0;
	X6 = 0;
	X7 = 0;
	X8 = 0;
	X9 = 1070 * dpi;
	X10 = X9 + 16 * dpi;
	X11 = X10 + BTN_WID + 16 * dpi;
	X12 = X11 + SLIDER_WID + 100 * dpi;

	Y0 = 0;
	Y1 = 60 * dpi;
	Y2 = Y1 + 9 * dpi;
	Y3 = Y2 + BTN_GAP;
	Y4 = Y3 + BTN_GAP + DBTN_GAP;
	Y5 = Y4 + BTN_GAP;
	Y6 = Y5 + BTN_GAP + DBTN_GAP;
	Y7 = Y6 + BTN_GAP;
	Y8 = Y7 + BTN_GAP + DBTN_GAP;
	Y9 = Y8 + BTN_GAP;
	Y10 = 552 * dpi;
	Y11 = Y10 + 8 * dpi;
	Y12 = Y11 + BTN_GAP;
	Y13 = Y12 + BTN_GAP + DBTN_GAP;
	Y14 = Y13 + BTN_GAP;
	Y15 = Y14 + BTN_GAP + DBTN_GAP;
	Y16 = 0;
	Y17 = Y15 + BTN_GAP;
}

