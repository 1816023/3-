#pragma once
#include "objBase.h"
#define MOVE_SPEED 5
class player :
	public objBase
{
public:
	player(std::string image_name);
	~player();
	bool Init();
	void update(std::vector<objBase*>&obj, char* getKey);
	void damage();
	virtual int GetShotType()override;
	//void Draw();
private:
	void move(char* getKey);
	int shot_type;		//弾のタイプ変更用
};

