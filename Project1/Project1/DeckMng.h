#pragma once
#include <string>
enum CARDTYPE
{
	WEAPON_CARD,
	ARMOR_CARD,
	ITEM_CARD,
	CARD_MAX
};
struct CardData {
	std::string name;		//���O
	CARDTYPE type;			//�J�[�h�^�C�v
	int card_No;			//�J�[�h�̔ԍ�	
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
private:

};

