#pragma once
#include "MyButton.h"
#include "ViewComponent.h"

//ページ作成・削除・遷移等管理クラス
class MenuView :
	public ViewComponent
{
private:
	std::shared_ptr<MyButton> create_btn;
	std::shared_ptr<MyButton> delete_btn;
	std::shared_ptr<MyButton> reset_btn;
	std::shared_ptr<MyButton> save_btn;
	std::shared_ptr<MyButton> run_btn;
	std::shared_ptr<MyButton> prev_btn;
	std::shared_ptr<MyButton> next_btn;
	std::shared_ptr<MyButton> close_btn;
	Texture close_btn_img;
	Rect menu_rect;
	Rect page_rect;
	Font font;
public:
	MenuView(std::weak_ptr<Controller> ctr) : ViewComponent(ctr)
	{
		init();
	}
	~MenuView() {}

	virtual void pollEvent() override;
private:
	void init();
	void initButton();
	void pollButtonEvent();
	void pollCloseEvent();
	void displayPageNum();
};
