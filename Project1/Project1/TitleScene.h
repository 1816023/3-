#pragma once
#include "sceneBase.h"
class sceneMng;
class AnimMng;
class TitleScene :
	public sceneBase
{
public:
	TitleScene(SCENE_TYPE type);
	~TitleScene();
	bool Init(sceneMng* scene);
	void Update(sceneMng* scene);
	void Draw();
	void Deahtory();
private:
	std::vector<AnimMng*> anim;
	std::vector<std::string>back_vec;
	void CreatBackCard();
	void EraseBackCard();
	int flash_cnt;
};

