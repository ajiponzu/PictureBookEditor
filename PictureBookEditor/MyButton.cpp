#include "MyButton.h"

bool MyButton::isClicked(int& w_ratio, int& h_ratio)
{
	resize(w_ratio, h_ratio);
	button.draw(ColorF(125, 0, 255));
	isMouseOver();
	if (button.leftClicked())
		return true;
	else
		return false;
}

void MyButton::resize(int& w_ratio, int& h_ratio)
{
	button.setPos(x * w_ratio, y * h_ratio);
	button.setSize(width * w_ratio, height * h_ratio);
}

bool MyButton::isMouseOver()
{
	return false;
}
