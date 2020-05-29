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
	void SetDeckType(int type) { deck_type = type; }
	int GetDcekType() { return deck_type; }
	int GetPoint() { return enemy_point; }
	void SetPoint(int point);
private:
	SCENE_TYPE nowScene;
	std::map<SCENE_TYPE,sceneBase*> sceneClass;
	int deck_type;
	int enemy_point;
};

