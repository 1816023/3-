#pragma once
#include <map>
#include"sceneBase.h"
class sceneMng
{
public:
	sceneMng();
	~sceneMng();
	void Iint();
	void main();
	void ChecgeScene(const SCENE_TYPE scene);
private:
	SCENE_TYPE nowScene;
	std::map<SCENE_TYPE,sceneBase*> sceneClass;
};

