#pragma once
#include <map>
#include"sceneBase.h"
enum SCENE
{
	SCENE_GAME,
	SCENE_MAX
};
class sceneMng
{
public:
	sceneMng();
	~sceneMng();
	void Iint();
	void main();
private:
	SCENE nowScene;
	std::map<SCENE ,sceneBase*> sceneClass;
protected:
	virtual void ChecgeScene(const SCENE scene);
};

