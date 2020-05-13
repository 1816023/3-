#pragma once
#include "objBase.h"
#define MOVE_SPEED 5
#define DEATH_CNT 60
class enemy :
	public objBase
{
public:
	enemy(std::string image_name,VECTOR pos);
	~enemy();
	bool Init();
	void update(std::vector<objBase*>&obj, char* getKey, PhasesMng* phases);
	void Draw(PhasesMng* phases);
	void damage();
	bool GetDamageFlag() { return damageFlag; }
private:
	bool damageFlag;
	void move();
	bool LRMoveFlag;	//falseÇ≈ç∂,trueÇ≈âE
	int deathCnt;	
	int netaImageH[3];
	int netanum;
};

