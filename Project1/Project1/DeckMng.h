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
	std::string name;		//名前
	CARDTYPE type;			//カードタイプ
	int card_No;			//カードの番号	
	std::string image_pass;	//カードのパス
	int image_handle;
	int attack;				//攻撃力(防具、アイテムの場合はなし)
	int defense;			//防御力(武器、アイテムの場合はなし)
	int durability;			//耐久力(アイテムの場合は1か0
	
};
class DeckMng
{
public:
	DeckMng();
	~DeckMng();
private:

};

