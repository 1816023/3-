#include "player.h"
#include "enemy.h"
#include "playerUI.h"
#include "enemy_UI.h"
#include "PhasesMng.h"
#include "UIBase.h"
#include"sceneMng.h"
#include "mainGame.h"


mainGame::mainGame(SCENE_TYPE type):sceneBase(type)
{
	obj.push_back(new player("data/texture/player.png"));
	obj.push_back(new enemy("data/texture/enemySet.png", {0,50}));
	phases = new PhasesMng();
	UI.push_back( new playerUI(TYPE_PLAYER));
	UI.push_back(new enemy_UI(TYPE_ENEMY));
}

mainGame::~mainGame()
{
}

bool mainGame::Init(sceneMng* scene)
{
	for (auto itr : obj)
	{
		if (itr->Init() == false)
		{
			return false;
		}
	}
	for (auto itr : UI)
	{
		itr->Init();
	}
	phases->Init(scene->GetDcekType());
	return true;
}

void mainGame::Update(sceneMng* scene)
{
	std::vector<int> deleteObjNum;
	GetHitKeyStateAll(getKey);
	
	for (auto itr : UI)
	{
		itr->Updata(obj);
	}
	phases->updata(obj);
	for (int i = 0; i < obj.size(); i++)
	{
		obj[i]->update(obj, getKey, phases);
		if (obj[i]->GetObjctType() == TYPE_PLAYER && obj[i]->GetHP() <= 0)
		{
			scene->ChecgeScene(RESULT_S);
			break;
		}
		if (obj[i]->GetObjctType() == TYPE_ENEMY)
		{
			scene->SetPoint(obj[i]->GetPoint());
			point = scene->GetPoint();
		}
		deleteObjNum.push_back(obj[i]->PlaeseDeath() ? i : -1);

	}

	for (auto obj_itr : deleteObjNum)
	{
		if (obj_itr != -1)
		{
			delete(obj[obj_itr]);

			obj.erase(obj.begin() + obj_itr);
		}
	}

}

void mainGame::Draw()
{
	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, 0x009900, true);
	for (auto itr : obj)
	{
		for (auto ui : UI)
		{
			switch (itr->GetObjType())
			{
			case TYPE_PLAYER:
				if (ui->GetObjType() == TYPE_PLAYER)
				{
					ui->Draw(itr);
				}
				break;
			case TYPE_ENEMY:
				if (ui->GetObjType() == TYPE_ENEMY)
				{
					ui->Draw(itr);
				}
				break;
			default:
				break;
			}
			
		}

		itr->Draw(phases);
	}
	
	phases->Draw();
	DrawFormatString(0, 0, 0xffffff, "%d\n", obj.size());
	DrawFormatString(0, 20, 0xffffff, "%d\n", point);
}

void mainGame::Deahtory()
{
	for (auto itr : obj)
	{
		
	}
	phases->Dehtroy();
}

