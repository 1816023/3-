#include"mainGame.h"
#include"TitleScene.h"
#include"selectScene.h"
#include"ResultScene.h"
#include "sceneMng.h"

sceneMng::sceneMng()
{
	nowScene = TITLE_S;
	sceneClass[GAME_S] = new mainGame(GAME_S);
	sceneClass[TITLE_S] = new TitleScene(TITLE_S);
	sceneClass[SELECT_S] = new selectScene(SELECT_S);
	sceneClass[RESULT_S] = new ResultScene(RESULT_S);
}

sceneMng::~sceneMng()
{
	
}

void sceneMng::Iint()
{
	sceneClass[nowScene]->Init(this);
}

void sceneMng::main()
{
	sceneClass[nowScene]->Update(this);
	ClearDrawScreen();
	sceneClass[nowScene]->Draw();
	ScreenFlip();
}


void sceneMng::ChecgeScene(const SCENE_TYPE scene)
{
	delete(sceneClass[nowScene]);
	nowScene = scene;
	switch (scene)
	{
	case TITLE_S:
		sceneClass[scene] = new TitleScene(scene);
		break;
	case SELECT_S:
		sceneClass[scene] = new selectScene(scene);
		break;
	case GAME_S:
		sceneClass[scene] = new mainGame(scene);
		break;
	case RESULT_S:
		sceneClass[scene] = new ResultScene(scene);
		break;

	default:
		break;
	}
	sceneClass[nowScene]->Init(this);
}
