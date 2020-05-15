#include"player.h"
#include "objBase.h"

objBase::objBase(std::string image_name)
{
	data.imageName= image_name;
}

objBase::~objBase()
{
}

void objBase::Draw(PhasesMng* phases)
{
	DrawGraph(data.pos.x, data.pos.y, lpObjMng.GetObj(data.imageName)[0], true);
}

OBJCT_TYPE objBase::GetObjctType()
{
	return data.objType;
}

std::string objBase::GetImageName()
{
	return data.imageName;
}

void objBase::attack(std::vector<objBase*>& obj)
{
}

