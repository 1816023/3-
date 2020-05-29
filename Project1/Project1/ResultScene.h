#pragma once
#include "sceneBase.h"
#include <DxLib.h>
class ResultScene :
	public sceneBase
{
public:
	ResultScene(SCENE_TYPE type);
	~ResultScene();
	bool Init(sceneMng* scene);
	void Update(sceneMng* scene);
	void Draw();
	void Deahtory();
private:
	bool AddRanking(int point);
	std::array<int, 5> ranking;
	bool out_of_ranking;
	bool LoadandSave(int point);
	int FontHandle;
	int MyPoint;
	std::map<std::string, int> cnt;
	std::map<std::string, VECTOR2> pos;
};

