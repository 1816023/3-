#include"sceneMng.h"
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

void TitleScene::Update(sceneMng* scene)
{
	if (GetMouseInput() == MOUSE_INPUT_LEFT)
	{
		if (!click_triger)
		{
			click_triger = true;
			scene->ChecgeScene(SELECT_S);
		}
	}
	else
	{
		click_triger = false;
	}
}

void TitleScene::Draw()
{
	DrawGraph(0, 0, IMAGE_ID("data/texture/titleBack.png")[0], true);
	DrawString(0, 0, "Title", 0xffffff);
}

void TitleScene::Deahtory()
{
}
