#pragma once
#include <Siv3D.hpp>
#include <memory>
#include <vector>
#include "Controller.h"
#include "Layout.h"

//��ʃR���g���[���Ǘ��̂��߂̃N���X�C���ۃN���X
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
