#include <DxLib.h>
#include "sceneBase.h"

sceneBase::sceneBase(SCENE_TYPE type)
{
	scene_type = type;
}

sceneBase::~sceneBase()
{
}

void sceneBase::main()
{
	Update();
	ClearDrawScreen();
	Draw();
	ScreenFlip();
}
