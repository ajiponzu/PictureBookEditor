#pragma once
///
//高解像度ディスプレイ使用の際，下記をコメントアウト
//ただし，一部のguiパーツが小さくなるバグあり
//あと，動作が不安定になる，一部の処理が無効になるなどのバグあり
///
//#define SIV3D_WINDOWS_HIGH_DPI
#include <Siv3D.hpp>
#include <memory>
#include "Controller.h"
#include "View.h"

//アプリケーション管理クラス
class App
{
private:
	std::unique_ptr<View> view = nullptr;
	std::shared_ptr<Controller> controller = nullptr;
	Array<Size> resolutions;
public:
	App() { init(); }
	~App() {}

	void run();
private:
	void init();
	void setWindowInf();
};
