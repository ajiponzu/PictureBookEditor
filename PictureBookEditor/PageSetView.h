#pragma once
#include "FontRect.h"
#include "ImageRect.h"
#include "MyButton.h"
#include "ViewComponent.h"

//画像・文字配置画面管理クラス
class PageSetView : public ViewComponent
{
private:
	Rect back_rect;
	Rect boundary_rect;
	Vec2 boundary_rect_pos;
	double expansion = 1.0;
	int wheel = 0;
	std::vector<std::shared_ptr<ImageRect>> img_rect_list;
	std::vector<std::shared_ptr<FontRect>> font_rect_list;
public:
	PageSetView(std::weak_ptr<Controller> ctr) : ViewComponent(ctr)
	{
		init();
	}
	~PageSetView() {}

	virtual void pollEvent() override;
private:
	void init();
	void initPageView();
	void initImgRect();
	void initFontRect();
	void pollGetImgInfEvent();
	void pollGetImgInfEvent(const int&);
	void pollGetTxtInfEvent();
	void pollGetTxtInfEvent(const int&);
	void pollPagePosEvent();
	void pollZoomEvent();
	void pollChangeBoundaryRectPosEvent();
	void pollImgRectEvent();
	void pollFontRectEvent();
	void pollSendPosInfEvent();
};
