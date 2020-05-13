#pragma once
#include <DxLib.h>
#include<vector>
#include<string>
#include"objMng.h"
#include "ImageMng.h"
#include "PhasesMng.h"
#define SCREEN_SIZE_X 820
#define SCREEN_SIZE_Y 640
class PhasesMng;
enum OBJCT_TYPE
{
	TYPE_PLAYER,
	TYPE_ENEMY,
	TYPE_SHOT,
	TYPE_MAX
};
enum SHOT_TYPE {
	SHOT_NORMAL,
	SHOT_HOMING,
	SHOT_MAX

};
struct obj_data{
	OBJCT_TYPE objType;
	std::string imageName;
	int imagH;
	int imageDivH[2];
	VECTOR imageSize;
	VECTOR pos;
};
class objBase
{
public:
	objBase(std::string image_name);
	~objBase();
	virtual bool Init() = 0;
	virtual void update(std::vector<objBase*>&obj,char* getKey,PhasesMng* phases) = 0;
	virtual void Draw(PhasesMng* phases);
	virtual OBJCT_TYPE GetObjctType();
	virtual std::string GetImageName();
	virtual VECTOR GetPos() { return data.pos; }
	virtual OBJCT_TYPE GetObjType() { return data.objType; }
	virtual obj_data GetObjData() { return data; }
	virtual bool PlaeseDeath() { return deathFlag; };
	virtual void damage() = 0;
	virtual bool GetDamageFlag() { return false; }
	virtual int GetShotType();
private:
	
protected:
	obj_data data = {};
	bool keyTriger[255] = {};
	bool deathFlag=false;
};

