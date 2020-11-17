#include "PictureSetView.h"

void PictureSetView::pollEvent()
{
	back_rect.draw(Palette::Whitesmoke).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Lightsalmon);
	pollButtonEvent();
	pollSliderEvent();
}

void PictureSetView::init()
{
	layout.init();
	initButton();
	back_rect = Rect(layout.X9, layout.Y1, layout.BACK_RECT_WID, layout.PICTURE_BACK_RECT_HIGH);
}

void PictureSetView::initButton()
{
	img_btn1 = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y2, layout.BTN_WID, layout.BTN_HIGH, String(U"画像"), layout.BTN_F_SIZE));
	img_btn1d = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y3, layout.BTN_WID, layout.BTN_HIGH, String(U"削除"), layout.BTN_F_SIZE));
	img_btn2 = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y5, layout.BTN_WID, layout.BTN_HIGH, String(U"画像"), layout.BTN_F_SIZE));
	img_btn2d = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y6, layout.BTN_WID, layout.BTN_HIGH, String(U"削除"), layout.BTN_F_SIZE));
	img_btn3 = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y8, layout.BTN_WID, layout.BTN_HIGH, String(U"画像"), layout.BTN_F_SIZE));
	img_btn3d = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y9, layout.BTN_WID, layout.BTN_HIGH, String(U"削除"), layout.BTN_F_SIZE));
}

void PictureSetView::pollButtonEvent()
{
	if (img_btn1->isClicked())
	{
		if (auto sp = controller.lock())
		{
			sp->selectImg(0);
		}
	}
	if (img_btn1d->isClicked())
	{
		Print << U"img1d";
		img_set_flag1d = true;
	}
	if (img_btn2->isClicked())
	{
		if (auto sp = controller.lock())
		{
			sp->selectImg(1);
		}
	}
	if (img_btn2d->isClicked())
	{
		Print << U"img2d";
		img_set_flag2d = true;
	}
	if (img_btn3->isClicked())
	{
		if (auto sp = controller.lock())
		{
			sp->selectImg(2);
		}
	}
	if (img_btn3d->isClicked())
	{
		Print << U"img3d";
		img_set_flag3d = true;
	}
}

void PictureSetView::pollSliderEvent()
{
	if (SimpleGUI::Slider(U"サイズ ", img_size1, 0.0, 10.0, Vec2(layout.X11, layout.Y2), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		Print << U"img1_size was changed";
	}
	if (SimpleGUI::Slider(U"アルファ値 ", img_alpha1, 0.0, 1.0, Vec2(layout.X11, layout.Y3), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		Print << U"img1_alpha was changed";
	}
	if (SimpleGUI::Slider(U"フェードイン {:.2f} "_fmt(img_fade_in1), img_fade_in1, 0.0, 60.0, Vec2(layout.X11, layout.Y4), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		Print << U"img1_fade_in was changed";
	}

	if (SimpleGUI::Slider(U"サイズ ", img_size2, 0.0, 10.0, Vec2(layout.X11, layout.Y5), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		Print << U"img2_size was changed";
	}
	if (SimpleGUI::Slider(U"アルファ値 ", img_alpha2, 0.0, 1.0, Vec2(layout.X11, layout.Y6), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		Print << U"img2_alpha was changed";
	}
	if (SimpleGUI::Slider(U"フェードイン {:.2f} \n"_fmt(img_fade_in2), img_fade_in2, 0.0, 60.0, Vec2(layout.X11, layout.Y7), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		Print << U"img2_fade_in was changed";
	}

	if (SimpleGUI::Slider(U"サイズ ", img_size3, 0.0, 10.0, Vec2(layout.X11, layout.Y8), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		Print << U"img3_size was changed";
	}
	if (SimpleGUI::Slider(U"アルファ値 ", img_alpha3, 0.0, 1.0, Vec2(layout.X11, layout.Y9), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		Print << U"img3_alpha was changed";
	}
	if (SimpleGUI::Slider(U"フェードイン {:.2f} "_fmt(img_fade_in3), img_fade_in3, 0.0, 60.0, Vec2(layout.X11, layout.Y10), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		Print << U"img3_fade_in was changed";
	}
}

