#include "DeckMng.h"
#include "player.h"
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
		0,
		IMAGE_ID("data/card/P01.png")[0]
	};
	return true;
}

void player::update(std::vector<objBase*>&obj, char* getKey, PhasesMng* phases)
{
	

}

void player::damage(int damage_num)
{
}

void player::Draw(PhasesMng* phases)
{
	DrawRotaGraph(SCREEN_SIZE_X/2, SCREEN_SIZE_Y/1.5f,1.0f, 0, state.card_handle, true, false);
	int hand_size = phases->GetHand().size();
	for (int a = 0; a < hand_size; a++)
	{
		// SCREEN_SIZE_X/hand_size
	}
}

void player::attack(std::vector<objBase*>& obj)
{
	for (auto itr : obj)
	{
		if (itr->GetObjctType() == TYPE_ENEMY)
		{
			itr->damage(state.attack + state.add_attack + state.def_attack);
		}
	}
	
}

int player::GetDefense()
{
	return state.defense+state.add_defence+state.def_defense;
}





void player::move(char* getKey)
{
	

}
