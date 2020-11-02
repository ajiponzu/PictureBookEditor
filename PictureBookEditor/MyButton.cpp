#include "MyButton.h"

bool MyButton::isClicked()
{
	button.draw(Palette::Aliceblue).drawFrame(2, 2, Palette::Aqua);
	font(text).drawAt(button.center(), Palette::Black);
	if (button.mouseOver()) Cursor::RequestStyle(CursorStyle::Hand);
	if (button.leftClicked())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MyButton::isClickedInvBtn()
{
	button.draw(Alpha(0));
	if (button.mouseOver()) Cursor::RequestStyle(CursorStyle::Hand);
	if (button.leftClicked())
	{
		return true;
	}
	else
	{
		return false;
	}
}


