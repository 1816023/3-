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
struct CardData {
	std::string name;		//名前
	CARDTYPE type;			//カードタイプ
	int card_No;			//カードの番号(sxx,s=カードの種類(1＝A、2＝S、3＝I、4＝P,5=N)、x=番号(2桁)) 	
	std::string image_pass;	//カードのパス
	int image_handle;
	int attack;				//攻撃力(防具、アイテムの場合はなし)
	int defense;			//防御力(武器、アイテムの場合はなし)
};
class DeckMng
{
public:
	DeckMng();
	~DeckMng();
	bool Init();
	CardData Choice(std::string name);	//名前でカードを検索、なかった場合は空のデータを返す
	CardData Choice(int num);			//番号でカードを検索、なかった場合は空のデータを返す
	CardData Draw();					//手札をすべて消してランダムで5枚選ぶ
	std::vector<CardData>GetHand();		
	void DelHand(int number);
	void ChangeHand(int num, CardData data);
private:
	std::vector<CardData>deck_vec;
	std::map<std::string, CardData>cardData_map;
	std::vector<CardData>hand_vec;
	std::map<int, CardData>hand_map;


};

