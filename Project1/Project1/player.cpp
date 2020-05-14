#include "DeckMng.h"
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
	for (int i= 0; i < 255; i++)
	{
		keyTriger[i] = false;
	}
	state = {
		40,
		20,
		0,
		0,
		0,
		0,
		0,
		0
	};
	return true;
}

void player::update(std::vector<objBase*>&obj, char* getKey, PhasesMng* phases)
{
	

}

void player::damage( )
{
}

void player::Draw(PhasesMng* phases)
{

}





void player::move(char* getKey)
{
	

}
