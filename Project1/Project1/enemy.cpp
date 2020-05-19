#include "enemy.h"
#include"ImageMng.h"


enemy::enemy(std::string image_name,VECTOR pos):objBase(image_name)
{
	data.imageName = image_name;
	data.pos = pos;
}

enemy::~enemy()
{
}

bool enemy::Init()
{
	data.objType = TYPE_ENEMY;
	data.imageSize = { 64,45 };
	lpObjMng.GetObj(data.imageName, { 65,45 }, {2,1});
	//LoadDivGraph(data.imageName.c_str(), 2, 2, 1, 64, 45, data.imageDivH);
	
	damageFlag = false;
	LRMoveFlag = true;
	deathCnt = DEATH_CNT;
	enemy_data["スライム"] = { 10,10,3,0,0,0,0,0,IMAGE_ID("data/texture/enemy_sra.png")[0],10 };
	state = enemy_data["スライム"];
	return true;
}

void enemy::update(std::vector<objBase*>&obj, char* getKey, PhasesMng* phases)
{
	move();
	
	if (phases->GetNowPhases() == ENEMY_TURN)
	{
		attack(obj);
		phases->ChangePhases(PHASES_DRAW);
	}
}

void enemy::Draw( PhasesMng* phases)
{
	if (phases->GetNowPhases() == ENEMY_TURN)
	{
		DrawRotaGraph(SCREEN_SIZE_X/2, SCREEN_SIZE_Y/2 - 60,1.5,0, IMAGE_ID("data/texture/EnemyTurnImage.png")[0], true);
	}
	DrawRotaGraph(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 4 - 60, 1, 0, IMAGE_ID("data/texture/enemy_sra.png")[0], true);
	DrawFormatString(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 4 - 60, 0xff0000, "%d\n", state.HP);
}

void enemy::damage(int damage_num)
{
	state.HP += (GetDefense() - damage_num>0?0: GetDefense() - damage_num);
}

void enemy::attack(std::vector<objBase*>& obj)
{
	for (auto itr : obj)
	{
		if (itr->GetObjctType() == TYPE_PLAYER)
		{
			itr->damage(state.attack + state.add_attack + state.def_attack);
		}
	}
}

int enemy::GetDefense()
{
	return state.defense+state.add_defence+state.def_defense;
}

void enemy::Standby(DeckMng* card)
{
}

void enemy::move()
{
	
}
