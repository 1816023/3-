#pragma once
#include "sceneBase.h"
#include "objBase.h"
class UIBase;
class PhasesMng;
class mainGame:public sceneBase
{
public:
	mainGame(SCENE_TYPE type);
	~mainGame();
	bool Init();
	void Update(sceneMng* scene);
	void Draw();
	void Deahtory();
private:
	std::vector<objBase*> obj;
	char getKey[256];

	std::vector<UIBase*> UI;
	PhasesMng* phases;
};

