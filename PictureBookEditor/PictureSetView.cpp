#include "PictureSetView.h"

//constexpr auto B_POS_X = 2650;
//constexpr auto B_WID = 120;
//constexpr auto B_HIGH = 80;
//constexpr auto B_GAP = B_HIGH + 20;
//constexpr auto BD_GAP = 45;
//constexpr auto B_POS_Y = 170;
//constexpr auto F_SIZE = 50;
//constexpr auto B_OFFSET = 40;

//constexpr auto TOP_Y = B_POS_Y - 20;
//constexpr auto IMG1_Y = B_POS_Y;
//constexpr auto IMG1D_Y = IMG1_Y + B_GAP;
//constexpr auto IMG2_Y = IMG1D_Y + B_GAP + BD_GAP;
//constexpr auto IMG2D_Y = IMG2_Y + B_GAP;
//constexpr auto IMG3_Y = IMG2D_Y + B_GAP + BD_GAP;
//constexpr auto IMG3D_Y = IMG3_Y + B_GAP;
//constexpr auto IMG4_Y = IMG3D_Y + B_GAP + BD_GAP;
//constexpr auto IMG4D_Y = IMG4_Y + B_GAP;
//constexpr auto BACK_HIGH = IMG4D_Y + 100 - TOP_Y;

//constexpr auto LEFT_X = B_POS_X - 50;
//constexpr auto LEFT_SLIDER_X = B_WID + B_POS_X + 50;
//constexpr auto RIGHT_SLIDER_X = LEFT_SLIDER_X + 500;
//constexpr auto SLIDER_LABEL_WID = 200.0;
//constexpr auto SLIDER_WID = 250.0;
//constexpr auto BACK_WID = RIGHT_SLIDER_X + 500 - LEFT_X;

void PictureSetView::pollEvent()
{
	back_rect.draw(Palette::Whitesmoke).drawFrame(4, 4, Palette::Lightsalmon);
	pollButtonEvent();
	pollSliderEvent();
}

void PictureSetView::init()
{
	layout.init();
	initButton();
	initMacro();
	back_rect = Rect(layout.X9, layout.Y1, layout.BACK_RECT_WID, layout.PICTURE_BACK_RECT_HIGH);
	Print << U"{}, {}, {}, {}"_fmt(layout.X9, layout.Y1, layout.BACK_RECT_WID, layout.PICTURE_BACK_RECT_HIGH);
}

void PictureSetView::initButton()
{
	img_btn1 = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y2, layout.PICTURE_BTN_WID, layout.PICTURE_BTN_HIGH, String(U"�摜"), layout.BTN_F_SIZE));
	img_btn1d = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y3, layout.PICTURE_BTN_WID, layout.PICTURE_BTN_HIGH, String(U"�폜"), layout.BTN_F_SIZE));
	img_btn2 = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y4, layout.PICTURE_BTN_WID, layout.PICTURE_BTN_HIGH, String(U"�摜"), layout.BTN_F_SIZE));
	img_btn2d = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y5, layout.PICTURE_BTN_WID, layout.PICTURE_BTN_HIGH, String(U"�폜"), layout.BTN_F_SIZE));
	img_btn3 = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y6, layout.PICTURE_BTN_WID, layout.PICTURE_BTN_HIGH, String(U"�摜"), layout.BTN_F_SIZE));
	img_btn3d = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y7, layout.PICTURE_BTN_WID, layout.PICTURE_BTN_HIGH, String(U"�폜"), layout.BTN_F_SIZE));
	img_btn4 = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y8, layout.PICTURE_BTN_WID, layout.PICTURE_BTN_HIGH, String(U"�摜"), layout.BTN_F_SIZE));
	img_btn4d = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y9, layout.PICTURE_BTN_WID, layout.PICTURE_BTN_HIGH, String(U"�폜"), layout.BTN_F_SIZE));
}

void PictureSetView::initMacro()
{
	x11 = layout.X11;
	x12 = layout.X12;
	y2 = layout.Y2;
	y3 = layout.Y3;
	y4 = layout.Y4;
	y5 = layout.Y5;
	y6 = layout.Y6;
	y7 = layout.Y7;
	y8 = layout.Y8;
	y9 = layout.Y9;
	slider_l_wid = layout.SLIDER_L_WID;
	slider_wid = layout.SLIDER_WID;
}

void PictureSetView::pollButtonEvent()
{
	if (img_btn1->isClicked())
	{
		Print << U"img1";
		img_set_flag1 = true;
	}
	if (img_btn1d->isClicked())
	{
		Print << U"img1d";
		img_set_flag1d = true;
	}
	if (img_btn2->isClicked())
	{
		Print << U"img2";
		img_set_flag2 = true;
	}
	if (img_btn2d->isClicked())
	{
		Print << U"img2d";
		img_set_flag2d = true;
	}
	if (img_btn3->isClicked())
	{
		Print << U"img3";
		img_set_flag3 = true;
	}
	if (img_btn3d->isClicked())
	{
		Print << U"img3d";
		img_set_flag3d = true;
	}
	if (img_btn4->isClicked())
	{
		Print << U"img4";
		img_set_flag4 = true;
	}
	if (img_btn4d->isClicked())
	{
		Print << U"img4d";
		img_set_flag4d = true;
	}
}

void PictureSetView::pollSliderEvent()
{
	if (SimpleGUI::Slider(U"�T�C�Y {:.2f} "_fmt(img_size1), img_size1, 0.0, 10.0, Vec2(x11, y2), slider_l_wid, slider_wid))
	{
		Print << U"img1_size was changed";
	}
	if (SimpleGUI::Slider(U"�A���t�@�l {:.2f} "_fmt(img_alpha1), img_alpha1, 0.0, 1.0, Vec2(x12, y2), slider_l_wid, slider_wid))
	{
		Print << U"img1_alpha was changed";
	}
	if (SimpleGUI::Slider(U"�t�F�[�h�C�� {:.2f} "_fmt(img_fade_in1), img_fade_in1, 0.0, 60.0, Vec2(x11, y3), slider_l_wid, slider_wid))
	{
		Print << U"img1_fade_in was changed";
	}
	if (SimpleGUI::Slider(U"�t�F�[�h�A�E�g {:.2f} "_fmt(img_fade_out1), img_fade_out1, 0.0, 120.0, Vec2(x12, y3), slider_l_wid, slider_wid))
	{
		Print << U"img1_fade_out was changed";
	}

	if (SimpleGUI::Slider(U"�T�C�Y {:.2f} "_fmt(img_size2), img_size2, 0.0, 10.0, Vec2(x11, y4), slider_l_wid, slider_wid))
	{
		Print << U"img2_size was changed";
	}
	if (SimpleGUI::Slider(U"�A���t�@�l {:.2f} "_fmt(img_alpha2), img_alpha2, 0.0, 1.0, Vec2(x12, y4), slider_l_wid, slider_wid))
	{
		Print << U"img2_alpha was changed";
	}
	if (SimpleGUI::Slider(U"�t�F�[�h�C�� {:.2f} "_fmt(img_fade_in2), img_fade_in2, 0.0, 60.0, Vec2(x11, y5), slider_l_wid, slider_wid))
	{
		Print << U"img2_fade_in was changed";
	}
	if (SimpleGUI::Slider(U"�t�F�[�h�A�E�g {:.2f} "_fmt(img_fade_out2), img_fade_out2, 0.0, 120.0, Vec2(x12, y5), slider_l_wid, slider_wid))
	{
		Print << U"img2_fade_out was changed";
	}

	if (SimpleGUI::Slider(U"�T�C�Y {:.2f} "_fmt(img_size3), img_size3, 0.0, 10.0, Vec2(x11, y6), slider_l_wid, slider_wid))
	{
		Print << U"img3_size was changed";
	}
	if (SimpleGUI::Slider(U"�A���t�@�l {:.2f} "_fmt(img_alpha3), img_alpha3, 0.0, 1.0, Vec2(x12, y6), slider_l_wid, slider_wid))
	{
		Print << U"img3_alpha was changed";
	}
	if (SimpleGUI::Slider(U"�t�F�[�h�C�� {:.2f} "_fmt(img_fade_in3), img_fade_in3, 0.0, 60.0, Vec2(x11, y7), slider_l_wid, slider_wid))
	{
		Print << U"img3_fade_in was changed";
	}
	if (SimpleGUI::Slider(U"�t�F�[�h�A�E�g {:.2f} "_fmt(img_fade_out3), img_fade_out3, 0.0, 120.0, Vec2(x12, y7), slider_l_wid, slider_wid))
	{
		Print << U"img3_fade_out was changed";
	}

	if (SimpleGUI::Slider(U"�T�C�Y {:.2f} "_fmt(img_size4), img_size4, 0.0, 10.0, Vec2(x11, y8), slider_l_wid, slider_wid))
	{
		Print << U"img4_size was changed";
	}
	if (SimpleGUI::Slider(U"�A���t�@�l {:.2f} "_fmt(img_alpha4), img_alpha4, 0.0, 1.0, Vec2(x12, y8), slider_l_wid, slider_wid))
	{
		Print << U"img4_alpha was changed";
	}
	if (SimpleGUI::Slider(U"�t�F�[�h�C�� {:.2f} "_fmt(img_fade_in4), img_fade_in4, 0.0, 60.0, Vec2(x11, y9), slider_l_wid, slider_wid))
	{
		Print << U"img4_fade_in was changed";
	}
	if (SimpleGUI::Slider(U"�t�F�[�h�A�E�g {:.2f} "_fmt(img_fade_out4), img_fade_out4, 0.0, 120.0, Vec2(x12, y9), slider_l_wid, slider_wid))
	{
		Print << U"img4_fade_out was changed";
	}
}

