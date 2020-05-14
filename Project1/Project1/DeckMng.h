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
	CARD_MAX
};
struct CardData {
	std::string name;		//���O
	CARDTYPE type;			//�J�[�h�^�C�v
	int card_No;			//�J�[�h�̔ԍ�(sxx,s=�J�[�h�̎��(1��A�A2��S�A3��I�A4��P)�Ax=�ԍ�(2��)) 	
	std::string image_pass;	//�J�[�h�̃p�X
	int image_handle;
	int attack;				//�U����(�h��A�A�C�e���̏ꍇ�͂Ȃ�)
	int defense;			//�h���(����A�A�C�e���̏ꍇ�͂Ȃ�)
	int durability;			//�ϋv��(�A�C�e���̏ꍇ��1��0
	
};
class DeckMng
{
public:
	DeckMng();
	~DeckMng();
	bool Init();
	CardData Choice(std::string name);	//���O�ŃJ�[�h�������A�Ȃ������ꍇ�͋�̃f�[�^��Ԃ�
	CardData Choice(int num);			//�ԍ��ŃJ�[�h�������A�Ȃ������ꍇ�͋�̃f�[�^��Ԃ�
	CardData Draw();					//�����_����1���I��
	CardData Draw(int num);				//�w�肳�ꂽ1�����̂Ă�1�������_���ň���	
	std::vector<CardData>GetHand();
private:
	std::vector<CardData>deck_vec;
	std::map<std::string, CardData>cardData_map;
	std::vector<CardData>hand_vec;
	std::map<int, CardData>hand_map;


};

