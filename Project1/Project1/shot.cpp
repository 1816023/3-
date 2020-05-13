#include "shot.h"

shot::shot(std::string image_name,VECTOR pos,SHOT_TYPE type,VECTOR enemy_pos):objBase(image_name)
{
	data.imageName = image_name;
	data.pos = pos;
	shot_type = type;
	shot::enemy_pos = enemy_pos;
	Init();
}

shot::~shot()
{
}

bool shot::Init()
{
	data.imagH = LoadGraph(data.imageName.c_str());
	data.imageSize = { 16,16 };
	data.pos.x+=data.imageSize.x/2;

	data.objType = TYPE_SHOT;
	move_num = { (enemy_pos.x - data.pos.x)/50,(enemy_pos.y-data.pos.y)/50 };
	return true;
}

void shot::update(std::vector<objBase*>&obj, char* getKey, PhasesMng* phases)
{
	switch (shot_type)
	{
	case SHOT_NORMAL:
		normal_shot();
		break;
	case SHOT_HOMING:
		homing_shot();
		break;
	case SHOT_MAX:
	default:
		break;
	}
	//íeÇÃìñÇΩÇËîªíË
	for (auto num = 0; num < obj.size(); num++)
	{
		if (obj[num]->GetObjType() == TYPE_ENEMY) {
			if (hitCheckObj(data, obj[num]->GetObjData()))
			{
				if (!obj[num]->GetDamageFlag())
				{
					deathFlag = true;
					obj[num]->damage();
				}
			}
		}
	}
	//ï`âÊîÕàÕäOçÌèú
	if (data.pos.y < -16||data.pos.y>SCREEN_SIZE_Y||data.pos.x<-data.imageSize.x||data.pos.x>SCREEN_SIZE_X)
	{
		
		deathFlag = true;
	}
}

void shot::damage()
{
}

bool shot::hitCheckObj(obj_data data_a,obj_data data_b)
{
	if (((data_a.pos.x > data_b.pos.x && data_a.pos.x < data_b.pos.x + data_b.imageSize.x) ||
		(data_a.pos.x<data_b.pos.x && data_a.pos.x + data_a.imageSize.x>data_b.pos.x)) &&
		((data_a.pos.y>data_b.pos.y && data_a.pos.y < data_b.pos.y + data_b.imageSize.y )||
		(data_a.pos.y<data_b.pos.y && data_a.pos.y + data_a.imageSize.y>data_b.pos.y))
		)
	{
 		return true;
	}
	else {
		return false;
	}
}

void shot::normal_shot()
{
	data.pos.y -= SHOT_SPEED;
	
}

void shot::homing_shot()
{
	data.pos.x += move_num.x;
	data.pos.y += move_num.y;
}

