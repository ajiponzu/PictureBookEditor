#pragma once
#include <Siv3D.hpp>
#include <memory>

#include "Controller.h"

class Model
{
private:
	std::shared_ptr<Controller> controller;
public:
	Model(std::shared_ptr<Controller> ptr) : controller(ptr) {}
	~Model() {}
};

