#include"sceneMng.h"
#include "selectScene.h"

selectScene::selectScene(SCENE_TYPE type):sceneBase(type)
{
}

selectScene::~selectScene()
{
}

bool selectScene::Init()
{
	click_triger = false;

	return false;
}

void selectScene::Update(sceneMng* scene)
{
	if (GetMouseInput() == MOUSE_INPUT_LEFT)
	{
		if (!click_triger)
		{
			click_triger = true;
			scene->ChecgeScene(GAME_S);
		}
	}
	else
	{
		click_triger = false;
	}
}

void selectScene::Draw()
{
	DrawString(0, 0, "selsect", 0xffffff);
}

void selectScene::Deahtory()
{
}
