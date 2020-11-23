#include "ImageRect.h"

//相対位置設定，Bookではこちらが使用される
void ImageRect::setRelativePos(const Vec2& pos, const Vec2& relative)
{
	this->pos = pos;
	this->relative = relative;
}

//相対位置を取得
Vec2 ImageRect::getRelativePos()
{
	return relative;
}

//サイズ変更を適用
void ImageRect::changeSize(const double& size)
{
	this->size = size;
}

//不透明度を適用
void ImageRect::changeAlpha(const double& alpha)
{
	this->alpha = alpha;
}

//画像パスの変更を適用
void ImageRect::changeImg(const String& path)
{
	this->path = path;
	img = Texture(path);
	if (!img)
	{
		this->path = U"";
		img = Texture(this->path);
	}
}

//相対位置を変更
void ImageRect::pollChangePosEvent(const double& expansion)
{
	if (path == U"") return;
	if (rectf.mouseOver()) Cursor::RequestStyle(CursorStyle::Hand);
	if (rectf.leftClicked())
	{
		is_pressed = true;
	}
	if (MouseL.up())
	{
		is_pressed = false;
	}
	if (is_pressed)
	{
		relative += Cursor::Delta() / expansion;
	}
}

//位置変更を適用
void ImageRect::move(const double& expansion)
{
	if (path == U"") return;
	this->expansion = expansion;
	rectf = RectF(pos + relative * expansion, img.width() * size * expansion, img.height() * size * expansion);
}

//描画
void ImageRect::draw()
{
	if (path == U"") return;
	if (is_pressed)
	{
		//押されているときは黄色の枠が表示される
		rectf.draw(AlphaF(0)).drawFrame(layout.RECT_FRAME_THICK + 5, layout.RECT_FRAME_THICK + 5, Palette::Yellow);
	}
	else
	{
		rectf.draw(AlphaF(0)).drawFrame(layout.RECT_FRAME_THICK + 5, layout.RECT_FRAME_THICK + 5, AlphaF(0));
	}
	//画像サイズ・不透明度・位置変更を適用
	img.scaled(size * expansion).draw(rectf.x, rectf.y, AlphaF(alpha));
}