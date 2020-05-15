#pragma once
#include "objBase.h"
#define MOVE_SPEED 5
#define DEATH_CNT 60
struct EnemyStat {
	int HP;					//基本HP
	int MP;					//基本MP
	int attack;				//攻撃力
	int add_attack;			//アイテムなどによるそのターン限りの追加攻撃力
	int def_attack;			//アイテムや敵によるデバフの減算分攻撃力
	int defense;			//防御力
	int add_defence;		//アイテムなどによるそのターン限りの追加防御力
	int def_defense;		//アイテムや敵によるデバフの減算分防御力
	int enemy_handle;		//画像ハンドル
};
class enemy :
	public objBase
{
public:
	enemy(std::string image_name,VECTOR pos);
	~enemy();
	bool Init();
	void update(std::vector<objBase*>&obj, char* getKey, PhasesMng* phases);
	void Draw(PhasesMng* phases);
	void damage(int damage_num);
	void attack(std::vector<objBase*>& obj);
	bool GetDamageFlag() { return damageFlag; }
	int GetDefense();
private:
	bool damageFlag;
	void move();
	bool LRMoveFlag;	//falseで左,trueで右
	int deathCnt;	
	int netaImageH[3];
	int netanum;
	EnemyStat state;
};

