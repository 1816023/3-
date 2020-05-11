#include "enemy.h"



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
	netaImageH[0]=LoadGraph("data/neta/ñ≥åæÇÃï†ÉpÉì.jpg");
	netaImageH[1]= LoadGraph("data/neta/êlÇÃó~ÇÕèIÇÌÇÁÇÀÇ¶.jpg");
	netaImageH[2] = LoadGraph("data/neta/kusaka.jpg");
	damageFlag = false;
	LRMoveFlag = true;
	deathCnt = DEATH_CNT;
	return true;
}

void enemy::update(std::vector<objBase*>&obj, char* getKey)
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
}

void enemy::Draw()
{
	
	
}

void enemy::damage()
{
	damageFlag = true;
	netanum = rand() % 3;
}

void enemy::move()
{
	if (!damageFlag)
	{
		if (LRMoveFlag)
		{
			data.pos.x += MOVE_SPEED;
		}
		else {
			data.pos.x -= MOVE_SPEED;
		}
	}
	if (data.pos.x < 0)
	{
		data.pos.x = 0;
		LRMoveFlag = (!LRMoveFlag ? true: false);
	}
	else if (data.pos.x > SCREEN_SIZE_X - 64) {
		data.pos.x = SCREEN_SIZE_X - 64;
		LRMoveFlag = (LRMoveFlag ? false : true);
	}
	else {}
}
