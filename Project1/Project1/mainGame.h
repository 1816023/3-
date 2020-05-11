#pragma once
#include "sceneBase.h"
#include "objBase.h"
class playerUI;
class mainGame:public sceneBase
{
public:
	mainGame();
	~mainGame();
	bool Init();
	void Update();
	void Draw();
private:
	std::vector<objBase*> obj;
	char getKey[256];
	playerUI* UI;
};

