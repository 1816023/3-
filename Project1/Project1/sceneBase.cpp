#include "sceneMng.h"
#include "sceneBase.h"

sceneBase::sceneBase(SCENE_TYPE type)
{
	scene_type = type;
}

sceneBase::~sceneBase()
{
}

bool sceneBase::HitBoxtoPoint(VECTOR2 point_pos, VECTOR2 box_pos, VECTOR2 box_size)
{
	if (point_pos.x >= box_pos.x && point_pos.y >= box_pos.y &&
		point_pos.x <= box_pos.x + box_size.x && point_pos.y >= box_pos.y &&
		point_pos.x >= box_pos.x && point_pos.y <= box_pos.y + box_size.y &&
		point_pos.x <= box_pos.x + box_size.x && point_pos.y <= box_pos.y + box_size.y)
	{
		return true;
	}
	else
	{
		return false;
	}

}