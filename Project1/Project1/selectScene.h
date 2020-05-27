#pragma once
#include "sceneBase.h"
class selectScene :
	public sceneBase
{
public:
	selectScene(SCENE_TYPE type);
	~selectScene();
	bool Init();
	void Update(sceneMng* scene);
	void Draw();
	void Deahtory();
private:
};

