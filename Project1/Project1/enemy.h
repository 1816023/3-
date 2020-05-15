#pragma once
#include "objBase.h"
#define MOVE_SPEED 5
#define DEATH_CNT 60
struct EnemyStat {
	int HP;					//��{HP
	int MP;					//��{MP
	int attack;				//�U����
	int add_attack;			//�A�C�e���Ȃǂɂ�邻�̃^�[������̒ǉ��U����
	int def_attack;			//�A�C�e����G�ɂ��f�o�t�̌��Z���U����
	int defense;			//�h���
	int add_defence;		//�A�C�e���Ȃǂɂ�邻�̃^�[������̒ǉ��h���
	int def_defense;		//�A�C�e����G�ɂ��f�o�t�̌��Z���h���
	int enemy_handle;		//�摜�n���h��
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
	bool LRMoveFlag;	//false�ō�,true�ŉE
	int deathCnt;	
	int netaImageH[3];
	int netanum;
	EnemyStat state;
};

