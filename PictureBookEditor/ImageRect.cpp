#include "ImageRect.h"

//���Έʒu�ݒ�CBook�ł͂����炪�g�p�����
void ImageRect::setRelativePos(const Vec2& pos, const Vec2& relative)
{
	this->pos = pos;
	this->relative = relative;
}

//���Έʒu���擾
Vec2 ImageRect::getRelativePos()
{
	return relative;
}

//�T�C�Y�ύX��K�p
void ImageRect::changeSize(const double& size)
{
	this->size = size;
}

//�s�����x��K�p
void ImageRect::changeAlpha(const double& alpha)
{
	this->alpha = alpha;
}

//�摜�p�X�̕ύX��K�p
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

//���Έʒu��ύX
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

//�ʒu�ύX��K�p
void ImageRect::move(const double& expansion)
{
	if (path == U"") return;
	this->expansion = expansion;
	rectf = RectF(pos + relative * expansion, img.width() * size * expansion, img.height() * size * expansion);
}

//�`��
void ImageRect::draw()
{
	if (path == U"") return;
	if (is_pressed)
	{
		//������Ă���Ƃ��͉��F�̘g���\�������
		rectf.draw(AlphaF(0)).drawFrame(layout.RECT_FRAME_THICK + 5, layout.RECT_FRAME_THICK + 5, Palette::Yellow);
	}
	else
	{
		rectf.draw(AlphaF(0)).drawFrame(layout.RECT_FRAME_THICK + 5, layout.RECT_FRAME_THICK + 5, AlphaF(0));
	}
	//�摜�T�C�Y�E�s�����x�E�ʒu�ύX��K�p
	img.scaled(size * expansion).draw(rectf.x, rectf.y, AlphaF(alpha));
}