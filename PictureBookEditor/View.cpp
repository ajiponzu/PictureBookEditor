#include "View.h"
#include "MenuView.h"
#include "PictureSetView.h"
#include "ScenarioSetView.h"
#include "PageSetView.h"

//メインループで呼ばれる処理
void View::pollEvent()
{
	//全ViewComponentの処理
	for (auto& vc : vc_list)
	{
		vc->pollEvent();
	}
}

//コンストラクタで呼ばれる初期化処理
void View::init()
{
	initVcList();
}

//コンポーネント追加
void View::initVcList()
{
	vc_list.push_back(std::make_shared<MenuView>(MenuView(controller)));
	vc_list.push_back(std::make_shared<PictureSetView>(PictureSetView(controller)));
	vc_list.push_back(std::make_shared<ScenarioSetView>(ScenarioSetView(controller)));
	vc_list.push_back(std::make_shared<PageSetView>(PageSetView(controller)));
}