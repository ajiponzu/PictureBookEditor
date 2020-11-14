#include "MyButton.h"

bool MyButton::isClicked()
{
	button.draw(Palette::Aliceblue).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Aqua);
	font(text).drawAt(button.center(), Palette::Black);
	if (button.mouseOver()) Cursor::RequestStyle(CursorStyle::Hand);
	return button.leftClicked();
}

bool MyButton::isClickedInvBtn()
{
	button.draw(Alpha(0));
	if (button.mouseOver()) Cursor::RequestStyle(CursorStyle::Hand);
	return button.leftClicked();
}

