#include "TitleScene.h"

TitleScene::TitleScene(SCENE_TYPE type):sceneBase(type)
{
}

TitleScene::~TitleScene()
{
}

bool TitleScene::Init()
{
	click_triger = false;
	return false;
}

void TitleScene::Update()
{
	if (GetMouseInput() == MOUSE_INPUT_LEFT)
	{


	}
	else
	{
		click_triger = false;
	}
}

void TitleScene::Draw()
{
	DrawString(0, 0, "Title", 0xffffff);
}

void TitleScene::Deahtory()
{
}
