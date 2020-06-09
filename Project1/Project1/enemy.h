#pragma once
#include "objBase.h"
#define MOVE_SPEED 5
#define DEATH_CNT 60
struct EnemyStat {
	std::string name;
	int HP;					//基本HP
	int MP;					//基本MP
	int attack;				//攻撃力
	int add_attack;			//アイテムなどによるそのターン限りの追加攻撃力
	int def_attack;			//アイテムや敵によるデバフの減算分攻撃力
	int defense;			//防御力
	int add_defence;		//アイテムなどによるそのターン限りの追加防御力
	int def_defense;		//アイテムや敵によるデバフの減算分防御力
	int enemy_handle;		//画像ハンドル
	int point;				//倒した時のポイント
	int abe_turn;			//倒すのにかかるであろうターン数
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
	bool attack(std::vector<objBase*>& obj);
	bool GetDamageFlag() { return damageFlag; }
	
	void Standby(DeckMng* card);
	int GetHP() { return state[enemy_number].HP; }
	int GetDefense() { return state[enemy_number].defense + state[enemy_number].add_defence + state[enemy_number].def_defense; }
	int GetAttack() { return state[enemy_number].attack + state[enemy_number].add_defence + state[enemy_number].def_defense; }
	int GetPoint() { return defeat_point; }
	EnemyStat GetState()const { return state[enemy_number]; }
private:
	bool damageFlag;
	void move();
	bool LRMoveFlag;	//falseで左,trueで右
	int deathCnt;	
	int netaImageH[3];
	int enemy_number;
	std::vector<EnemyStat> state;
	std::map < std::string, EnemyStat >enemy_data;
	int defeat_point;
};

