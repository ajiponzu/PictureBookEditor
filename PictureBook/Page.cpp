#include "Page.h"

Stopwatch stopwatch;

void Page::update()
{
	stopwatch.start();
	if (MouseL.down())
	{
		next();
	}
	if (MouseR.down())
	{
		prev();
	}
}

void Page::draw() const
{
	Scene::SetBackground(Palette::White);
	drawImg();
	drawTxt();
}

void Page::initPageInf()
{
	auto& controller = getData().controller;
	controller.readPage();
	img_inf = controller.returnImgInfArray();
	txt_inf = controller.returnTxtInfArray();
	initImg();
	initTxt();
}

void Page::initImg()
{
	auto idx = 0;
	img.resize(3);
	for (const auto& inf : img_inf)
	{
		img[idx] = Texture(inf.path);
		idx++;
	}
}

void Page::initTxt()
{
	auto idx = 0;
	txt.resize(2);
	for (const auto& inf : txt_inf)
	{
		txt[idx] = Font(inf.size);
		idx++;
	}
}

void Page::drawImg() const
{
	auto idx = 0;
	for (const auto& inf : img_inf)
	{
		if (inf.path != U"" && (stopwatch.sF() >= inf.fadein))
		{
			const auto t = Min(stopwatch.sF() - inf.fadein, inf.alpha);
			const auto alpha = EaseOutCirc(t) * inf.alpha;
			img[idx].scaled(inf.size).draw(inf.pos, AlphaF(alpha));
		}
		idx++;
	}
}

void Page::drawTxt() const
{
	auto idx = 0;
	for (const auto& inf : txt_inf)
	{
		if (inf.txt != U"" && (stopwatch.sF() >= inf.fadein))
		{
			const auto length = static_cast<size_t>((stopwatch.sF() - inf.fadein) / 0.2);
			txt[idx](inf.txt.substr(0, length)).draw(inf.pos, Palette::Black);
		}
		idx++;
	}
}

void Page::next()
{
	auto& controller = getData().controller;
	controller.nextPage();
	if (controller.isTransition())
	{
		resetStopWatch();
		controller.resetIsTransition();
		changeScene(U"Page", 1s);
	}
	if (controller.isEnd())
	{
		System::Exit();
	}
}

void Page::prev()
{
	auto& controller = getData().controller;
	controller.prevPage();
	if (controller.isTransition())
	{
		resetStopWatch();
		controller.resetIsTransition();
		changeScene(U"Page", 1s);
	}
}

void Page::resetStopWatch()
{
	stopwatch.restart();
	stopwatch.pause();
}
