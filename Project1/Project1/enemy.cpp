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
	enemy_data["スライム"] = { "スライム",10,10,3,0,0,0,0,0,IMAGE_ID("data/texture/enemy_sra.png")[0],10,1 };
	enemy_data["ゴブリン"] = { "ゴブリン",20,0,5,0,0,2,0,0,IMAGE_ID("data/texture/enemy_gob.png")[0],10,2 };
	state.push_back( enemy_data["スライム"]);
	state.push_back(enemy_data["ゴブリン"]);
	enemy_number = 0;
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
	DrawRotaGraph(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 4 - 60, 1, 0,state[enemy_number].enemy_handle, true);
}

void enemy::damage(int damage_num)
{
	state[enemy_number].HP += (GetDefense() - damage_num>0?0: GetDefense() - damage_num);
	if (state[enemy_number].HP <= 0)
	{
		state[enemy_number] = enemy_data[state[enemy_number].name];
		enemy_number = (enemy_number+1 >= state.size() ? 0 : enemy_number+1);
	}
}

void enemy::attack(std::vector<objBase*>& obj)
{
	for (auto itr : obj)
	{
		if (itr->GetObjctType() == TYPE_PLAYER)
		{
			itr->damage(state[enemy_number].attack + state[enemy_number].add_attack + state[enemy_number].def_attack);
		}
	}
}


void enemy::Standby(DeckMng* card)
{
}

void enemy::move()
{
	
}
