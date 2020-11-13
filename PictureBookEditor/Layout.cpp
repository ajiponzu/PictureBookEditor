#include "Layout.h"

void Layout::init()
{
	dpi = Graphics::GetDPIScaling();

	initMenuViewMacro();
	initPictureSetViewMacro();
	initPos();
	BTN_F_SIZE = 20 * dpi;
	BACK_RECT_WID = 480 * dpi;
	SLIDER_L_WID = 80 * dpi;
	SLIDER_WID = 100 * dpi;
}

void Layout::initMenuViewMacro()
{
	MENU_BTN_WID = 80 * dpi;
	MENU_BTN_HIGH = 32 * dpi;
	MENU_BTN_GAP_X = MENU_BTN_WID + 8 * dpi;
	MENU_BAR_TH = MENU_BTN_HIGH + 8 * dpi;
	MENU_CLBTN_X = Window::ClientWidth() - MENU_BAR_TH;
}

void Layout::initPictureSetViewMacro()
{
	PICTURE_BTN_WID = 48 * dpi;
	PICTURE_BTN_HIGH = 32 * dpi;
	PICTURE_BTN_GAP = PICTURE_BTN_HIGH + 8 * dpi;
	PICTURE_DBTN_GAP = 20 * dpi;
	PICTURE_BACK_RECT_HIGH = 400 * dpi;
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
	X9 = 1120 * dpi;
	X10 = X9 + 20 * dpi;
	X11 = 1200 * dpi;
	X12 = X11 + 200 * dpi;

	Y0 = 0;
	Y1 = 60 * dpi;
	Y2 = Y1 + 9 * dpi;
	Y3 = Y2 + PICTURE_BTN_GAP;
	Y4 = Y3 + PICTURE_BTN_GAP + PICTURE_DBTN_GAP;
	Y5 = Y4 + PICTURE_BTN_GAP;
	Y6 = Y5 + PICTURE_BTN_GAP + PICTURE_DBTN_GAP;
	Y7 = Y6 + PICTURE_BTN_GAP;
	Y8 = Y7 + PICTURE_BTN_GAP + PICTURE_DBTN_GAP;
	Y9 = Y8 + PICTURE_BTN_GAP;
	Y10 = 0;
	Y11 = 0;
	Y12 = 0;
	Y13 = 0;
	Y14 = 0;
	Y15 = 0;
	Y16 = 0;
	Y17 = 0;
}

