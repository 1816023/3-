#include "player.h"
#include "enemy.h"
#include "shot.h"
#include "playerUI.h"
#include "mainGame.h"


mainGame::mainGame()
{
	obj.push_back(new player("data/texture/player.png"));
	obj.push_back(new enemy("data/texture/enemySet.png", {0,50}));
	
	UI = new playerUI();
}

mainGame::~mainGame()
{
}

bool mainGame::Init()
{
	for (auto itr : obj)
	{
		if (itr->Init() == false)
		{
			return false;
		}
	}
	UI->Init();
	return true;
}

void mainGame::Update()
{
	std::vector<int> deleteObjNum;
	GetHitKeyStateAll(getKey);
	for (int i = 0; i < obj.size(); i++)
	{
		obj[i]->update(obj, getKey);
		deleteObjNum.push_back(obj[i]->PlaeseDeath()?i:-1);
	}
	
	
	for(auto obj_itr:deleteObjNum)
	if (obj_itr != -1)
	{
		delete(obj[obj_itr]);
		
		obj.erase(obj.begin()+obj_itr);
	}
	UI->Updata(obj);
}

void mainGame::Draw()
{
	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, 0x009900, true);
	for (auto itr : obj)
	{
		itr->Draw();
		if (itr->GetObjctType() == TYPE_PLAYER)
		{
			UI->Draw(itr);
		}
		
	}
	DrawFormatString(0, 0, 0xffffff, "%d\n", obj.size());
	
}

