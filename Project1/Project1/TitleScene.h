#pragma once
#include "sceneBase.h"
class TitleScene :
	public sceneBase
{
public:
	TitleScene(SCENE_TYPE type);
	~TitleScene();
	bool Init();
	void Update();
	void Draw();
	void Deahtory();
private:

};

