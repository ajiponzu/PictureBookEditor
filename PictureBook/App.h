#pragma once
///
//高解像度ディスプレイ使用の際，下記をコメントアウト
//ただし，一部のguiパーツが小さくなるバグあり
//あと，動作が不安定になる，一部の処理が無効になるなどのバグあり
///
//#define SIV3D_WINDOWS_HIGH_DPI
#include <Siv3D.hpp>
#include "BookController.h"
#include "Page.h"

//アプリケーション管理クラス
class App
{
private:
	int wid = 0;
	int high = 0;
	Book book;
	Rect viewport_rect;
	Array<Size> resolutions;
public:
	App() { init(); }
	~App() {}

	void run();
private:
	void init();
	void setWindowInf();
};
