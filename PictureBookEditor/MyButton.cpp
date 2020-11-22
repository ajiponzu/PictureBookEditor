#include "MyButton.h"

bool MyButton::isClicked()
{
	transition.update(button.mouseOver());
	auto color = ColorF(palette.r, palette.g * (1 - transition.value()), palette.b);
	if (button.mouseOver()) Cursor::RequestStyle(CursorStyle::Hand);
	button.draw(color).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Aqua);
	font(text).drawAt(button.center(), Palette::Black);
	return button.leftClicked();
}

bool MyButton::isClickedInvBtn()
{
	if (button.mouseOver()) Cursor::RequestStyle(CursorStyle::Hand);
	transition.update(button.mouseOver());
	auto color = ColorF(1.0 * transition.value(), 0.0, 0.0, 0.65 * transition.value());
	button.draw(color);
	return button.leftClicked();
}