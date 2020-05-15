#pragma once
#include "objBase.h"
#define MOVE_SPEED 5
struct PlayerStat
{
	int HP;					//��{HP
	int MP;					//��{MP
	int attack;				//�U����
	int add_attack;			//�A�C�e���Ȃǂɂ�邻�̃^�[������̒ǉ��U����
	int def_attack;			//�A�C�e����G�ɂ��f�o�t�̌��Z���U����
	int defense;			//�h���
	int add_defence;		//�A�C�e���Ȃǂɂ�邻�̃^�[������̒ǉ��h���
	int def_defense;		//�A�C�e����G�ɂ��f�o�t�̌��Z���h���
	int card_handle;		//�摜�n���h��
	CardData weapon_card;	//�������Ă��镐��J�[�h
	CardData armor_card;	//�������Ă���h��J�[�h
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
	void Draw(PhasesMng* phases);		//�`��
	PlayerStat GetPlayerState() { return state; }
	void attack(std::vector<objBase*>& obj);
	int GetDefense();
	//void Draw();
private:
	void move(char* getKey);
	PlayerStat state;
};

