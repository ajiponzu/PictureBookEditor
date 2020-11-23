#include "View.h"
#include "MenuView.h"
#include "PictureSetView.h"
#include "ScenarioSetView.h"
#include "PageSetView.h"

//���C�����[�v�ŌĂ΂�鏈��
void View::pollEvent()
{
	//�SViewComponent�̏���
	for (auto& vc : vc_list)
	{
		vc->pollEvent();
	}
}

//�R���X�g���N�^�ŌĂ΂�鏉��������
void View::init()
{
	initVcList();
}

//�R���|�[�l���g�ǉ�
void View::initVcList()
{
	vc_list.push_back(std::make_shared<MenuView>(MenuView(controller)));
	vc_list.push_back(std::make_shared<PictureSetView>(PictureSetView(controller)));
	vc_list.push_back(std::make_shared<ScenarioSetView>(ScenarioSetView(controller)));
	vc_list.push_back(std::make_shared<PageSetView>(PageSetView(controller)));
}