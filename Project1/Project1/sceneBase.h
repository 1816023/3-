#pragma once
#include <vector>
#include <string>
#include <array>
#include <vector>
#include <DxLib.h>
#include "ImageMng.h"
#include "SoundMng.h"
#define CARD_SIZE_X 192
#define CARD_SIZE_Y 270
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
class sceneMng;

class sceneBase
{
public:
	sceneBase(SCENE_TYPE type);
	~sceneBase();
	virtual bool Init(sceneMng* scene)=0;
	virtual void Update(sceneMng* scene)=0;
	virtual void Draw()=0;
	virtual SCENE_TYPE GetSceneType() { return scene_type; }
private:
	SCENE_TYPE scene_type;

protected:
	bool click_triger;
	bool HitBoxtoPoint(VECTOR2 point_pos, VECTOR2 box_pos, VECTOR2 box_size);
};

