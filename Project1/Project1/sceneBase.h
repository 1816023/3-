#pragma once
#include <vector>
#include <string>
#include <vector>
#include <DxLib.h>
#define SCREEN_SIZE_X 1230
#define SCREEN_SIZE_Y 960
enum SCENE_TYPE
{
	TITLE_S,
	SELECT_S,
	GAME_S,
	RESULT_S,
	MAX_S
};
class sceneBase
{
public:
	sceneBase(SCENE_TYPE type);
	~sceneBase();
	virtual bool Init()=0;
	virtual void Update()=0;
	virtual void Draw()=0;
	virtual void main();
	virtual SCENE_TYPE GetSceneType() { return scene_type; }
private:
	SCENE_TYPE scene_type;

protected:
	bool click_triger;
};

