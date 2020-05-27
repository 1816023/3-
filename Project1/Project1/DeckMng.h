#pragma once
#include <string>
#include <vector>
#include <map>
enum CARDTYPE
{
	WEAPON_CARD,
	ARMOR_CARD,
	ITEM_CARD,
	PLAYER_CARD,
	NULL_CARD,
	CARD_MAX
};
enum ITEM_TYPE {
	RECOVERY_HP,
	RECOVERY_MP,
	ADD_ATTACK,
	ADD_DEFENSE,
	NO_EFFECT,
	ITEM_TYPE_MAX
};
struct CardData {
	std::string name;		//���O
	CARDTYPE type;			//�J�[�h�^�C�v
	int card_No;			//�J�[�h�̔ԍ�(sxx,s=�J�[�h�̎��(1��A�A2��S�A3��I�A4��P,5=N)�Ax=�ԍ�(2��)) 	
	std::string image_pass;	//�J�[�h�̃p�X
	int image_handle;
	int attack;				//�U����(�h��A�A�C�e���̏ꍇ�͂Ȃ�)
	int defense;			//�h���(����A�A�C�e���̏ꍇ�͂Ȃ�)
	ITEM_TYPE item_type;
};
class DeckMng
{
public:
	DeckMng();
	~DeckMng();
	bool Init(int deck_type);
	CardData Choice(std::string name);	//���O�ŃJ�[�h�������A�Ȃ������ꍇ�͋�̃f�[�^��Ԃ�
	CardData Choice(int num);			//�ԍ��ŃJ�[�h�������A�Ȃ������ꍇ�͋�̃f�[�^��Ԃ�
	CardData Draw();					//��D�����ׂď����ă����_����5���I��
	std::vector<CardData>GetHand();		
	void DelHand(int number);
	void ChangeHand(int num, CardData data);
private:
	std::vector<CardData>deck_vec;
	std::map<std::string, CardData>cardData_map;
	std::vector<CardData>hand_vec;
	std::map<int, CardData>hand_map;
	void CardLoad();
	void DeckLoad();
	std::vector<std::vector<CardData>> deck;
	int deck_type;
};

