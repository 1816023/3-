#pragma once
#include "objBase.h"
#define MOVE_SPEED 5
#define DEATH_CNT 60
struct EnemyStat {
	std::string name;
	int HP;					//��{HP
	int MP;					//��{MP
	int attack;				//�U����
	int add_attack;			//�A�C�e���Ȃǂɂ�邻�̃^�[������̒ǉ��U����
	int def_attack;			//�A�C�e����G�ɂ��f�o�t�̌��Z���U����
	int defense;			//�h���
	int add_defence;		//�A�C�e���Ȃǂɂ�邻�̃^�[������̒ǉ��h���
	int def_defense;		//�A�C�e����G�ɂ��f�o�t�̌��Z���h���
	int enemy_handle;		//�摜�n���h��
	int point;				//�|�������̃|�C���g
	int abe_turn;			//�|���̂ɂ�����ł��낤�^�[����
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
	bool LRMoveFlag;	//false�ō�,true�ŉE
	int deathCnt;	
	int netaImageH[3];
	int enemy_number;
	std::vector<EnemyStat> state;
	std::map < std::string, EnemyStat >enemy_data;
	int defeat_point;
};

