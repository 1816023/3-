#include"mainGame.h"
#include"TitleScene.h"
#include"selectScene.h"
#include"ResultScene.h"
#include "sceneMng.h"

sceneMng::sceneMng()
{
	nowScene = GAME_S;
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
	sceneClass[nowScene]->Init();
}

void sceneMng::main()
{
	sceneClass[nowScene]->main();
}


void sceneMng::ChecgeScene(const SCENE_TYPE scene)
{
	nowScene = scene;
}
