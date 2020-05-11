#include "sceneMng.h"
#include"mainGame.h"

sceneMng::sceneMng()
{
	nowScene = SCENE_GAME;
	sceneClass[SCENE_GAME] = new mainGame();
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


void sceneMng::ChecgeScene(const SCENE scene)
{
	nowScene = scene;
}
