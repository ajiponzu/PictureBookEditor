#pragma once
#include <Siv3D.hpp>
#include <memory>
#include <vector>
#include "Controller.h"
#include "Layout.h"

//画面コントロール管理のためのクラス，抽象クラス
class ViewComponent
{
protected:
	std::weak_ptr<Controller> controller;
	Layout layout{};
public:
	ViewComponent(std::weak_ptr<Controller> ctr) : controller(ctr) {}
	~ViewComponent() {}

	virtual void pollEvent() = 0;
};
