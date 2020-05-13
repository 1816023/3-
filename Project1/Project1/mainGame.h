#pragma once
#include "sceneBase.h"
#include "objBase.h"
class playerUI;
class PhasesMng;
class mainGame:public sceneBase
{
public:
	mainGame();
	~mainGame();
	bool Init();
	void Update();
	void Draw();
	void Deahtory();
private:
	std::vector<objBase*> obj;
	char getKey[256];
	playerUI* UI;
	PhasesMng* phases;
};

