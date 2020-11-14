#include "MenuView.h"

void MenuView::pollEvent()
{
	menu_rect.draw(Arg::top = Palette::Aquamarine, Arg::bottom = Palette::Blue);
	pollCloseEvent();
	pollButtonEvent();
}

void MenuView::init()
{
	layout.init();
	menu_rect = Rect(0, 0, Window::ClientWidth(), layout.MENU_BAR_TH);
	initButton();
}

void MenuView::initButton()
{
	auto create_x = layout.X1;
	auto delete_x = create_x + layout.MENU_BTN_GAP_X;
	auto reset_x = delete_x + layout.MENU_BTN_GAP_X;
	auto save_x = reset_x + layout.MENU_BTN_GAP_X;
	auto run_x = save_x + layout.MENU_BTN_GAP_X;
	create_btn = std::make_shared<MyButton>(MyButton(create_x, layout.Y0, layout.MENU_BTN_WID, layout.MENU_BTN_HIGH, String(U"新規"), layout.BTN_F_SIZE));
	delete_btn = std::make_shared<MyButton>(MyButton(delete_x, layout.Y0, layout.MENU_BTN_WID, layout.MENU_BTN_HIGH, String(U"削除"), layout.BTN_F_SIZE));
	reset_btn = std::make_shared<MyButton>(MyButton(reset_x, layout.Y0, layout.MENU_BTN_WID, layout.MENU_BTN_HIGH, String(U"リセット"), layout.BTN_F_SIZE));
	save_btn = std::make_shared<MyButton>(MyButton(save_x, layout.Y0, layout.MENU_BTN_WID, layout.MENU_BTN_HIGH, String(U"保存"), layout.BTN_F_SIZE));
	run_btn = std::make_shared<MyButton>(MyButton(run_x, layout.Y0, layout.MENU_BTN_WID, layout.MENU_BTN_HIGH, String(U"実行"), layout.BTN_F_SIZE));
	close_btn = std::make_shared<MyButton>(MyButton(layout.CLBTN_X, 0, layout.MENU_BAR_TH, layout.MENU_BAR_TH, String(U""), layout.BTN_F_SIZE));
	close_btn_img = Texture(U"close_btn.png");
	if (!close_btn_img)
    {
        throw Error(U"Failed to create a texture");
    }
}

void MenuView::pollButtonEvent()
{
	if (create_btn->isClicked())
	{
		Print << U"create";
	}
	if (delete_btn->isClicked())
	{
		Print << U"delete";
	}
	if (reset_btn->isClicked())
	{
		Print << U"reset";
	}
	if (save_btn->isClicked())
	{
		Print << U"save";
	}
	if (run_btn->isClicked())
	{
		Print << U"run";
	}
}

void MenuView::pollCloseEvent()
{
	close_btn_img.resized(layout.MENU_BAR_TH).draw(layout.CLBTN_X, 0);
	if (close_btn->isClickedInvBtn())
	{
		System::Exit();
	}
}

