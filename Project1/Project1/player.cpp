#include "player.h"
#include "shot.h"
player::player(std::string image_name):objBase(image_name)
{
	data.imageName = image_name;

}

player::~player()
{
}

bool player::Init()
{
	data.imageSize = { 64,64 };
	data.pos = {SCREEN_SIZE_X/2-data.imageSize.x/2,SCREEN_SIZE_Y/4*3};
	
	data.objType = TYPE_PLAYER;
	shot_type = SHOT_NORMAL;
	for (int i= 0; i < 255; i++)
	{
		keyTriger[i] = false;
	}

	return true;
}

void player::update(std::vector<objBase*>&obj, char* getKey)
{
	

}

void player::damage()
{
}

int player::GetShotType()
{
	return  shot_type;
}



void player::move(char* getKey)
{
	

}
