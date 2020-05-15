#pragma once
#include "objBase.h"
#define MOVE_SPEED 5
struct PlayerStat
{
	int HP;					//基本HP
	int MP;					//基本MP
	int attack;				//攻撃力
	int add_attack;			//アイテムなどによるそのターン限りの追加攻撃力
	int def_attack;			//アイテムや敵によるデバフの減算分攻撃力
	int defense;			//防御力
	int add_defence;		//アイテムなどによるそのターン限りの追加防御力
	int def_defense;		//アイテムや敵によるデバフの減算分防御力
	int card_handle;		//画像ハンドル
	CardData weapon_card;	//装備している武器カード
	CardData armor_card;	//装備している防具カード
};
class player :
	public objBase
{
public:
	player(std::string image_name);
	~player();
	bool Init();
	void update(std::vector<objBase*>&obj, char* getKey, PhasesMng* phases);
	void damage(int damage_num);
	void Draw(PhasesMng* phases);		//描画
	PlayerStat GetPlayerState() { return state; }
	void attack(std::vector<objBase*>& obj);
	int GetDefense();
	//void Draw();
private:
	void move(char* getKey);
	PlayerStat state;
};

