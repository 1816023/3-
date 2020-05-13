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
	return true;
}

void enemy::update(std::vector<objBase*>&obj, char* getKey, PhasesMng* phases)
{
	move();
	if (damageFlag)
	{
		deathCnt--;
		if (deathCnt<0)
		{
			deathFlag = true;
		}
	}
	if (phases->GetNowPhases() == ENEMY_TURN)
	{
		phases->ChangePhases(PHASES_DRAW);
	}
}

void enemy::Draw( PhasesMng* phases)
{
	if (phases->GetNowPhases() == ENEMY_TURN)
	{
		DrawGraph(0, 320 - 60, IMAGE_ID("data/texture/EnemyTurnImage.png")[0], true);
	}
	
}

void enemy::damage()
{
	damageFlag = true;
	netanum = rand() % 3;
}

void enemy::move()
{
	
}
