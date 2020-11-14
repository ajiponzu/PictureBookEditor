#include "Layout.h"

void Layout::init()
{
	dpi = Graphics::GetDPIScaling();

	initMenuViewMacro();
	initPictureSetViewMacro();
	initScenarioSetViewMacro();
	initPageSetViewMacro();
	BTN_F_SIZE = 20 * dpi;
	BACK_RECT_WID = 450 * dpi;
	SLIDER_L_WID = 200 * dpi;
	SLIDER_WID =  150 * dpi;
	RECT_FRAME_THICK = 1.0 * dpi;
	initPos();
}

void Layout::initMenuViewMacro()
{
	MENU_BTN_WID = 80 * dpi;
	MENU_BTN_HIGH = 32 * dpi;
	MENU_BTN_GAP = MENU_BTN_WID + 8 * dpi;
	MENU_BAR_TH = MENU_BTN_HIGH + 8 * dpi;
	CLBTN_X = Window::ClientWidth() - MENU_BAR_TH;
}

void Layout::initPictureSetViewMacro()
{
	BTN_WID = 48 * dpi;
	BTN_HIGH = 32 * dpi;
	BTN_GAP = BTN_HIGH + 8 * dpi;
	PICTURE_BACK_RECT_HIGH = 420 * dpi;
}

void Layout::initScenarioSetViewMacro()
{
	SCENARIO_BACK_RECT_HIGH = 300 * dpi;
}

void Layout::initPageSetViewMacro()
{
	PAGE_BACK_RECT_WID = 1000 * dpi;
	PAGE_BACK_RECT_HIGH = 680 * dpi;
	MOVE_RECT1_POS = 20 * dpi;
	MOVE_RECT2_POS = MOVE_RECT1_POS + 20 * dpi;
	MOVE_RECT3_POS = MOVE_RECT2_POS + 20 * dpi;
}

void Layout::initPos()
{
	X0 = 0;
	X1 = 16 * dpi;
	X2 = X1 + MENU_BTN_GAP;
	X3 = X2 + MENU_BTN_GAP;
	X4 = 240 * dpi;
	X5 = X3 + MENU_BTN_GAP;
	X6 = X5 + MENU_BTN_GAP;
	X7 = X6 + 200 * dpi;
	X8 = X7 + 200 * dpi;
	X9 = 1070 * dpi;
	X10 = X9 + 16 * dpi;
	X11 = X10 + BTN_WID + 20 * dpi;

	Y0 = 0;
	Y1 = 60 * dpi;
	Y2 = Y1 + 9 * dpi;
	Y3 = Y2 + BTN_GAP;
	Y4 = Y3 + BTN_GAP;
	Y5 = Y4 + BTN_GAP + 20 * dpi;
	Y6 = Y5 + BTN_GAP;
	Y7 = Y6 + BTN_GAP;
	Y8 = Y7 + BTN_GAP + 20 * dpi;
	Y9 = Y8 + BTN_GAP;
	Y10 = Y9 + BTN_GAP;
	Y11 = 552 * dpi;
	Y12 = Y11 + 9 * dpi;
	Y13 = Y12 + BTN_GAP;
	Y14 = Y13 + BTN_GAP + 20 * dpi;
	Y15 = Y14 + BTN_GAP;
	Y16 = Y15 + BTN_GAP + 20 * dpi;
	Y17 = 780 * dpi;
	Y18 = Y16 + BTN_GAP;
}

