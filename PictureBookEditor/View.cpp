#include "View.h"

void View::pollEvent()
{

}

void View::draw()
{
	calcSceneRatio();
}

void View::calcSceneRatio()
{
	scene_wid = Scene::Width();
	scene_high = Scene::Height();
	wid_ratio = scene_wid / DEFAULT_SCENE_WID;
	high_ratio = scene_high / DEFAULT_SCENE_HIGH;
}
