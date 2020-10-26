#pragma once
#define SIV3D_WINDOWS_HIGH_DPI
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

