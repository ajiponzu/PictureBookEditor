#include "PictureSetView.h"

//メインループで呼ばれる処理
void PictureSetView::pollEvent()
{
	//背景描画
	back_rect.draw(Palette::Whitesmoke).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Lightsalmon);
	pollGetImgInfEvent();
	pollButtonEvent();
	pollSliderEvent();
}

//コンストラクタで呼ばれる初期化処理
void PictureSetView::init()
{
	initParameter();
	initButton();
	back_rect = Rect(layout.X9, layout.Y1, layout.BACK_RECT_WID, layout.PICTURE_BACK_RECT_HIGH);
}

//パラメータ初期化
void PictureSetView::initParameter()
{
	img_size.push_back(1.0);
	img_size.push_back(1.0);
	img_size.push_back(1.0);
	img_alpha.push_back(1.0);
	img_alpha.push_back(1.0);
	img_alpha.push_back(1.0);
	img_fade_in.push_back(0.0);
	img_fade_in.push_back(0.0);
	img_fade_in.push_back(0.0);
}

//ボタン作成
void PictureSetView::initButton()
{
	img_btn1 = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y2, layout.BTN_WID, layout.BTN_HIGH, String(U"画像"), layout.BTN_F_SIZE));
	img_btn1d = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y3, layout.BTN_WID, layout.BTN_HIGH, String(U"削除"), layout.BTN_F_SIZE));
	img_btn2 = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y5, layout.BTN_WID, layout.BTN_HIGH, String(U"画像"), layout.BTN_F_SIZE));
	img_btn2d = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y6, layout.BTN_WID, layout.BTN_HIGH, String(U"削除"), layout.BTN_F_SIZE));
	img_btn3 = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y8, layout.BTN_WID, layout.BTN_HIGH, String(U"画像"), layout.BTN_F_SIZE));
	img_btn3d = std::make_shared<MyButton>(MyButton(layout.X10, layout.Y9, layout.BTN_WID, layout.BTN_HIGH, String(U"削除"), layout.BTN_F_SIZE));
}

//画像情報の取得
void PictureSetView::pollGetImgInfEvent()
{
	pollGetImgInfEvent(0);
	pollGetImgInfEvent(1);
	pollGetImgInfEvent(2);
}

//画像情報の変更を監視
void PictureSetView::pollGetImgInfEvent(const int& idx)
{
	if (auto sp = controller.lock())
	{
		auto inf = sp->returnImgInf(idx);
		if (inf != nullptr)
		{
			img_size[idx] = inf->size;
			img_alpha[idx] = inf->alpha;
			img_fade_in[idx] = inf->fadein;
		}
	}
}

//画像情報更新ボタンを押したかどうか
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
		if (auto sp = controller.lock())
		{
			sp->deleteImg(0);
		}
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
		if (auto sp = controller.lock())
		{
			sp->deleteImg(1);
		}
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
		if (auto sp = controller.lock())
		{
			sp->deleteImg(2);
		}
	}
}

//スライダーを動かしたかどうか
void PictureSetView::pollSliderEvent()
{
	if (SimpleGUI::Slider(U"サイズ ", img_size[0], 0.0, 3.0, Vec2(layout.X11, layout.Y2), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		if (auto sp = controller.lock())
		{
			//変更した値を送信
			sp->changeImgSize(0, img_size[0]);
		}
	}
	if (SimpleGUI::Slider(U"アルファ値 ", img_alpha[0], 0.0, 1.0, Vec2(layout.X11, layout.Y3), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		if (auto sp = controller.lock())
		{
			sp->changeImgAlpha(0, img_alpha[0]);
		}
	}
	if (SimpleGUI::Slider(U"フェードイン {:.2f} "_fmt(img_fade_in[0]), img_fade_in[0], 0.0, 60.0, Vec2(layout.X11, layout.Y4), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		if (auto sp = controller.lock())
		{
			sp->changeImgFadein(0, img_fade_in[0]);
		}
	}

	if (SimpleGUI::Slider(U"サイズ ", img_size[1], 0.0, 3.0, Vec2(layout.X11, layout.Y5), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		if (auto sp = controller.lock())
		{
			sp->changeImgSize(1, img_size[1]);
		}
	}
	if (SimpleGUI::Slider(U"アルファ値 ", img_alpha[1], 0.0, 1.0, Vec2(layout.X11, layout.Y6), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		if (auto sp = controller.lock())
		{
			sp->changeImgAlpha(1, img_alpha[1]);
		}
	}
	if (SimpleGUI::Slider(U"フェードイン {:.2f} "_fmt(img_fade_in[1]), img_fade_in[1], 0.0, 60.0, Vec2(layout.X11, layout.Y7), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		if (auto sp = controller.lock())
		{
			sp->changeImgFadein(1, img_fade_in[1]);
		}
	}

	if (SimpleGUI::Slider(U"サイズ ", img_size[2], 0.0, 3.0, Vec2(layout.X11, layout.Y8), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		if (auto sp = controller.lock())
		{
			sp->changeImgSize(2, img_size[2]);
		}
	}
	if (SimpleGUI::Slider(U"アルファ値 ", img_alpha[2], 0.0, 1.0, Vec2(layout.X11, layout.Y9), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		if (auto sp = controller.lock())
		{
			sp->changeImgAlpha(2, img_alpha[2]);
		}
	}
	if (SimpleGUI::Slider(U"フェードイン {:.2f} "_fmt(img_fade_in[2]), img_fade_in[2], 0.0, 60.0, Vec2(layout.X11, layout.Y10), layout.SLIDER_L_WID, layout.SLIDER_WID))
	{
		if (auto sp = controller.lock())
		{
			sp->changeImgFadein(2, img_fade_in[2]);
		}
	}
}