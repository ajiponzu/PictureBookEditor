#include "MenuView.h"

//���C�����[�v�ŌĂ΂�鏈��
void MenuView::pollEvent()
{
	//�w�i�`��
	menu_rect.draw(Arg::top = Palette::Aquamarine, Arg::bottom = Palette::Blue);
	pollCloseEvent();
	pollButtonEvent();
	displayPageNum();
}

//�R���X�g���N�^�ŌĂ΂�鏉��������
void MenuView::init()
{
	menu_rect = Rect(0, 0, Window::ClientWidth(), layout.MENU_BAR_TH);
	page_rect = Rect(layout.X7, layout.Y17, layout.PAGE_RECT_WID, layout.BTN_HIGH);
	font = Font(layout.BTN_F_SIZE);
	initButton();
}

//�{�^���쐬
void MenuView::initButton()
{
	create_btn = std::make_shared<MyButton>(MyButton(layout.X1, layout.Y0, layout.MENU_BTN_WID, layout.MENU_BTN_HIGH, String(U"�V�K"), layout.BTN_F_SIZE));
	delete_btn = std::make_shared<MyButton>(MyButton(layout.X2, layout.Y0, layout.MENU_BTN_WID, layout.MENU_BTN_HIGH, String(U"�폜"), layout.BTN_F_SIZE));
	reset_btn = std::make_shared<MyButton>(MyButton(layout.X3, layout.Y0, layout.MENU_BTN_WID, layout.MENU_BTN_HIGH, String(U"���Z�b�g"), layout.BTN_F_SIZE));
	save_btn = std::make_shared<MyButton>(MyButton(layout.X5, layout.Y0, layout.MENU_BTN_WID, layout.MENU_BTN_HIGH, String(U"�ۑ�"), layout.BTN_F_SIZE));
	run_btn = std::make_shared<MyButton>(MyButton(layout.X6, layout.Y0, layout.MENU_BTN_WID, layout.MENU_BTN_HIGH, String(U"���s"), layout.BTN_F_SIZE));
	close_btn = std::make_shared<MyButton>(MyButton(layout.CLBTN_X, 0, layout.MENU_BAR_TH, layout.MENU_BAR_TH, String(U""), layout.BTN_F_SIZE));
	prev_btn = std::make_shared<MyButton>(MyButton(layout.X4, layout.Y17, layout.BTN_WID, layout.BTN_HIGH, String(U"�O��"), layout.BTN_F_SIZE));
	next_btn = std::make_shared<MyButton>(MyButton(layout.X8, layout.Y17, layout.BTN_WID, layout.BTN_HIGH, String(U"����"), layout.BTN_F_SIZE));
	close_btn_img = Texture(U"close_btn.png");
	if (!close_btn_img)
	{
		throw Error(U"Failed to create a texture");
	}
}

//�{�^�������������ǂ���
void MenuView::pollButtonEvent()
{
	if (create_btn->isClicked())
	{
		if (auto sp = controller.lock())
		{
			sp->createPage();
		}
	}
	if (delete_btn->isClicked())
	{
		if (auto sp = controller.lock())
		{
			sp->deletePage();
		}
	}
	if (reset_btn->isClicked())
	{
		if (auto sp = controller.lock())
		{
			sp->resetPage();
		}
	}
	if (save_btn->isClicked())
	{
		if (auto sp = controller.lock())
		{
			sp->savePage();
		}
	}
	if (run_btn->isClicked())
	{
		if (auto sp = controller.lock())
		{
			sp->runBook();
		}
	}
	if (prev_btn->isClicked())
	{
		if (auto sp = controller.lock())
		{
			sp->prevPage();
		}
	}
	if (next_btn->isClicked())
	{
		if (auto sp = controller.lock())
		{
			sp->nextPage();
		}
	}
}

//�N���[�Y�{�^�������������ǂ���
void MenuView::pollCloseEvent()
{
	close_btn_img.resized(layout.MENU_BAR_TH).draw(layout.CLBTN_X, 0, AlphaF(0.88));
	if (close_btn->isClickedInvBtn())
	{
		System::Exit();
	}
}

//�ǂ̃y�[�W��ҏW���Ă��邩�C�y�[�W�ԍ���\��
void MenuView::displayPageNum()
{
	page_rect.draw(Palette::White).drawFrame(layout.RECT_FRAME_THICK, layout.RECT_FRAME_THICK, Palette::Lightsalmon);
	if (auto sp = controller.lock())
	{
		auto p = sp->returnCurrentPage();
		auto max_p = sp->returnMaxPage();
		font(U"  Page: {}/{}"_fmt(p, max_p)).draw(page_rect.stretched(1), Palette::Black);
	}
}