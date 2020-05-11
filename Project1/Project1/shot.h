#pragma once
#include "objBase.h"
#define SHOT_SPEED 10
class shot :
	public objBase
{
public:
	shot(std::string image_name, VECTOR pos, SHOT_TYPE type, VECTOR enemy_pos = {});
	~shot();
	bool Init();
	void update(std::vector<objBase*>&obj,char* getKey);
	void damage();
private:
	SHOT_TYPE shot_type;
	VECTOR enemy_pos;
	VECTOR move_num;

	bool hitCheckObj(obj_data data_a, obj_data data_b);
	void normal_shot();		//SHOT_TYPE‚ªNORMAL‚ÌŽž‚Ì“®‚«
	void homing_shot();		//SHOT_TYPE‚ªHOMING‚ÌŽž‚Ì“®‚«
	//void Draw();
};

