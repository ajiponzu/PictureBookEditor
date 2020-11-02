#include "MenuView.h"

constexpr auto B_POS_X = 20;
constexpr auto B_WID = 200;
constexpr auto B_HIGH = 80;
constexpr auto B_GAP = B_WID + 20;
constexpr auto B_POS_Y = 0;
constexpr auto F_SIZE = 50;
constexpr auto B_OFFSET = 40;

constexpr auto R_WID = 3840;
constexpr auto R_HIGH = B_HIGH + 20;

constexpr auto CB_SIZE =R_HIGH;
constexpr auto CB_X = R_WID - CB_SIZE;

void MenuView::pollEvent()
{
	menu_rect.draw(Arg::top = Palette::Aquamarine, Arg::bottom = Palette::Blue);
	pollCloseEvent();
	pollButtonEvent();
}

void MenuView::init()
{
	menu_rect = Rect(0, 0, R_WID, R_HIGH);
	close_btn_img = Texture(U"close_btn.png");
	close_btn = std::make_shared<MyButton>(MyButton(CB_X, 0, CB_SIZE, CB_SIZE, String(U""), F_SIZE));
	if (!close_btn_img)
    {
        throw Error(U"Failed to create a texture");
    }
	initButton();
}

void MenuView::initButton()
{
	auto create_x = B_POS_X;
	auto delete_x = create_x + B_GAP;
	auto reset_x = delete_x + B_GAP;
	auto save_x = reset_x + B_GAP;
	auto run_x = save_x + B_GAP;
	create_btn = std::make_shared<MyButton>(MyButton(create_x, B_POS_Y, B_WID, B_HIGH, String(U"新規"), F_SIZE));
	delete_btn = std::make_shared<MyButton>(MyButton(delete_x, B_POS_Y, B_WID, B_HIGH, String(U"削除"), F_SIZE));
	reset_btn = std::make_shared<MyButton>(MyButton(reset_x, B_POS_Y, B_WID, B_HIGH, String(U"リセット"), F_SIZE));
	save_btn = std::make_shared<MyButton>(MyButton(save_x, B_POS_Y, B_WID, B_HIGH, String(U"保存"), F_SIZE));
	run_btn = std::make_shared<MyButton>(MyButton(run_x, B_POS_Y, B_WID, B_HIGH, String(U"実行"), F_SIZE));
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
	close_btn_img.draw(CB_X, 0);
	if (close_btn->isClickedInvBtn())
	{
		System::Exit();
	}
}

