#pragma once
#include "sceneBase.h"
class ResultScene :
	public sceneBase
{
public:
	ResultScene(SCENE_TYPE type);
	~ResultScene();
	bool Init();
	void Update(sceneMng* scene);
	void Draw();
	void Deahtory();
private:
};

