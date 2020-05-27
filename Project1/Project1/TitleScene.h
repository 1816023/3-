#pragma once
#include "sceneBase.h"
class sceneMng;
class TitleScene :
	public sceneBase
{
public:
	TitleScene(SCENE_TYPE type);
	~TitleScene();
	bool Init();
	void Update(sceneMng* scene);
	void Draw();
	void Deahtory();
private:

};

