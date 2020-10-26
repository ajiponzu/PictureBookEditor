#include "MenuView.h"

constexpr auto B_POS_X = 20;
constexpr auto B_WID = 80;
constexpr auto B_HIGH = 50;
constexpr auto B_GAP = B_WID + 20;
constexpr auto B_POS_Y = 20;
constexpr auto F_SIZE = 30;

void MenuView::pollEvent()
{
	if (create_btn->isClicked(wid_ratio, high_ratio))
	{
		Print << U"create";
	}
	if (delete_btn->isClicked(wid_ratio, high_ratio))
	{
		Print << U"delete";
	}
	if (reset_btn->isClicked(wid_ratio, high_ratio))
	{
		Print << U"reset";
	}
	if (save_btn->isClicked(wid_ratio, high_ratio))
	{
		Print << U"save";
	}
	if (run_btn->isClicked(wid_ratio, high_ratio))
	{
		Print << U"run";
	}
}

void MenuView::draw()
{
}

void MenuView::init()
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
