#include <DxLib.h>
#include "sceneBase.h"

sceneBase::sceneBase()
{
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
