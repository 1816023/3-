#pragma once
#include "sceneBase.h"
class selectScene :
	public sceneBase
{
public:
	selectScene(SCENE_TYPE type);
	~selectScene();
	bool Init(sceneMng* scene);
	void Update(sceneMng* scene);
	void Draw();
	void Deahtory();
private:
	int FontHandle;
	int BigFont;
	int select_deck;
	std::vector<std::string> deck_text;
	bool click_flag;
};

