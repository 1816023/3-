#include <random>
#include <DxLib.h>
#include "ImageMng.h"
#include "DeckMng.h"

DeckMng::DeckMng()
{
}

DeckMng::~DeckMng()
{
}

bool DeckMng::Init()
{
	cardData_map["NullCard"] =			{	"NullCard",				NULL_CARD,		500,	"data/card/N00.png",	IMAGE_ID("data/card/N00.png")[0],	0,	0,	NO_EFFECT	};

	cardData_map["ヒノキの棒"] =		{	"ヒノキの棒",			WEAPON_CARD,	101,	"data/card/A01.png",	IMAGE_ID("data/card/A01.png")[0],	2,	0,	NO_EFFECT	};
	cardData_map["高級なヒノキの棒"] =	{	"高級なヒノキの棒",		WEAPON_CARD,	102,	"data/card/A02.png",	IMAGE_ID("data/card/A02.png")[0],	4,	0,	NO_EFFECT	};
	cardData_map["伝説のヒノキの棒"] =	{	"伝説のヒノキの棒",		WEAPON_CARD,	103,	"data/card/A03.png",	IMAGE_ID("data/card/A03.png")[0],	20,	0,	NO_EFFECT	};
	cardData_map["訓練用の木剣"] =		{	"訓練用の木剣",			WEAPON_CARD,	104,	"data/card/A04.png",	IMAGE_ID("data/card/A04.png")[0],	1,	0,	NO_EFFECT	};
	cardData_map["鉄の大剣"] =			{	"鉄の大剣",				WEAPON_CARD,	105,	"data/card/A05.png",	IMAGE_ID("data/card/A05.png")[0],	6,	0,	NO_EFFECT	};
	cardData_map["バスターソード"] =	{	"バスターソード",		WEAPON_CARD,	106,	"data/card/A06.png",	IMAGE_ID("data/card/A06.png")[0],	10,	0,	NO_EFFECT	};
	cardData_map["少し飾った槍"] =		{	"少し飾った槍",			WEAPON_CARD,	107,	"data/card/A07.png",	IMAGE_ID("data/card/A07.png")[0],	5,	0,	NO_EFFECT	};
	cardData_map["戦闘斧"] =			{	"戦闘斧",				WEAPON_CARD,	108,	"data/card/A08.png",	IMAGE_ID("data/card/A08.png")[0],	7,	0,	NO_EFFECT	};
	cardData_map["如意棒"] =			{	"如意棒",				WEAPON_CARD,	109,	"data/card/A09.png",	IMAGE_ID("data/card/A09.png")[0],	11,	0,	NO_EFFECT	};
	cardData_map["爆弾"] =				{	"爆弾",					WEAPON_CARD,	110,	"data/card/A10.png",	IMAGE_ID("data/card/A10.png")[0],	10,	0,	NO_EFFECT	};
	cardData_map["髑髏鎌"] =			{	"髑髏鎌",				WEAPON_CARD,	111,	"data/card/A11.png",	IMAGE_ID("data/card/A11.png")[0],	7,	0,	NO_EFFECT	};
	cardData_map["ヨーヨー"] =			{	"ヨーヨー",				WEAPON_CARD,	112,	"data/card/A12.png",	IMAGE_ID("data/card/A12.png")[0],	4,	0,	NO_EFFECT	};
	cardData_map["緑のスタッフ"] =		{	"緑のスタッフ",			WEAPON_CARD,	113,	"data/card/A13.png",	IMAGE_ID("data/card/A13.png")[0],	7,	0,	NO_EFFECT	};
	cardData_map["丸太"] =				{	"丸太",					WEAPON_CARD,	114,	"data/card/A14.png",	IMAGE_ID("data/card/A14.png")[0],	12,	0,	NO_EFFECT	};
	cardData_map["聖なる丸太"] =		{	"聖なる丸太",			WEAPON_CARD,	115,	"data/card/A15.png",	IMAGE_ID("data/card/A15.png")[0],	13,	0,	NO_EFFECT	};
	cardData_map["木刀"] =				{	"木刀",					WEAPON_CARD,	116,	"data/card/A16.png",	IMAGE_ID("data/card/A16.png")[0],	5,	0,	NO_EFFECT	};
	cardData_map["火炎剣"] =			{	"火炎剣",				WEAPON_CARD,	117,	"data/card/A17.png",	IMAGE_ID("data/card/A17.png")[0],	9,	0,	NO_EFFECT	};

	cardData_map["木の盾"] =			{	"木の盾",				ARMOR_CARD,		201,	"data/card/S01.png",	IMAGE_ID("data/card/S01.png")[0],	0,	2,	NO_EFFECT	};
	cardData_map["豪華な盾"] =			{	"豪華な盾",				ARMOR_CARD,		202,	"data/card/S02.png",	IMAGE_ID("data/card/S02.png")[0],	0,	3,	NO_EFFECT	};
	cardData_map["大き目な木の盾"] =	{	"大き目な木の盾",		ARMOR_CARD,		203,	"data/card/S03.png",	IMAGE_ID("data/card/S03.png")[0],	0,	4,	NO_EFFECT	};
	cardData_map["貼り付けの盾"] =		{	"貼り付けの盾",			ARMOR_CARD,		204,	"data/card/S04.png",	IMAGE_ID("data/card/S04.png")[0],	0,	6,	NO_EFFECT	};
	cardData_map["アイアンバックラー"] ={	"アイアンバックラー",	ARMOR_CARD,		205,	"data/card/S05.png",	IMAGE_ID("data/card/S05.png")[0],	0,	6,	NO_EFFECT	};
	cardData_map["ゴールドバックラー"] ={	"ゴールドバックラー",	ARMOR_CARD,		206,	"data/card/S06.png",	IMAGE_ID("data/card/S06.png")[0],	0,	4,	NO_EFFECT	};
	cardData_map["バケツメット"] =		{	"バケツメット",			ARMOR_CARD,		207,	"data/card/S07.png",	IMAGE_ID("data/card/S07.png")[0],	0,	3,	NO_EFFECT	};
	cardData_map["レザーアーマー"] =	{	"レザーアーマー",		ARMOR_CARD,		208,	"data/card/S08.png",	IMAGE_ID("data/card/S08.png")[0],	0,	4,	NO_EFFECT	};
	cardData_map["騎士の鎧"] =			{	"騎士の鎧",				ARMOR_CARD,		209,	"data/card/S09.png",	IMAGE_ID("data/card/S09.png")[0],	0,	7,	NO_EFFECT	};
	cardData_map["翡翠の盾"] =			{	"翡翠の盾",				ARMOR_CARD,		210,	"data/card/S10.png",	IMAGE_ID("data/card/S10.png")[0],	0,	6,	NO_EFFECT	};
	cardData_map["霞の王の盾"] =		{	"霞の王の盾",			ARMOR_CARD,		211,	"data/card/S11.png",	IMAGE_ID("data/card/S11.png")[0],	0,	9,	NO_EFFECT	};
	cardData_map["王者の盾"] =			{	"王者の盾",				ARMOR_CARD,		212,	"data/card/S12.png",	IMAGE_ID("data/card/S12.png")[0],	0,	15,	NO_EFFECT	};

	cardData_map["回復の薬"] =			{	"回復の薬",				ITEM_CARD,		301,	"data/card/I01.png",	IMAGE_ID("data/card/I01.png")[0],	5,	0,	RECOVERY_HP };
	cardData_map["回復の薬・改"] =		{	"回復の薬・改",			ITEM_CARD,		302,	"data/card/I02.png",	IMAGE_ID("data/card/I02.png")[0],	10,	0,	RECOVERY_HP	};
	cardData_map["回復の薬・真"] =		{	"回復の薬・真",			ITEM_CARD,		303,	"data/card/I03.png",	IMAGE_ID("data/card/I03.png")[0],	15,	0,	RECOVERY_HP	};
	cardData_map["狂化の丸薬"] =		{	"狂化の丸薬",			ITEM_CARD,		304,	"data/card/I04.png",	IMAGE_ID("data/card/I04.png")[0],	5,	0,	ADD_ATTACK	};
	cardData_map["狂化の丸薬・改"] =	{	"狂化の丸薬・改",		ITEM_CARD,		305,	"data/card/I05.png",	IMAGE_ID("data/card/I05.png")[0],	7,	0,	ADD_ATTACK	};
	cardData_map["狂化の丸薬・真"] =	{	"狂化の丸薬・真",		ITEM_CARD,		306,	"data/card/I06.png",	IMAGE_ID("data/card/I06.png")[0],	10,	0,	ADD_ATTACK	};
	cardData_map["硬化のオイル"] =		{	"硬化のオイル",			ITEM_CARD,		307,	"data/card/I07.png",	IMAGE_ID("data/card/I07.png")[0],	5,	0,	ADD_DEFENSE	};
	cardData_map["硬化のオイル・改"] =	{	"硬化のオイル・改",		ITEM_CARD,		308,	"data/card/I08.png",	IMAGE_ID("data/card/I08.png")[0],	7,	0,	ADD_DEFENSE	};
	cardData_map["硬化のオイル・真"] =	{	"硬化のオイル・真",		ITEM_CARD,		309,	"data/card/I09.png",	IMAGE_ID("data/card/I09.png")[0],	10,	0,	ADD_DEFENSE	};

	deck_vec.push_back(cardData_map["ヒノキの棒"]);
	deck_vec.push_back(cardData_map["高級なヒノキの棒"]);
	deck_vec.push_back(cardData_map["伝説のヒノキの棒"]);
	deck_vec.push_back(cardData_map["訓練用の木剣"]);
	deck_vec.push_back(cardData_map["鉄の大剣"]);
	deck_vec.push_back(cardData_map["バスターソード"]);
	deck_vec.push_back(cardData_map["少し飾った槍"]);
	deck_vec.push_back(cardData_map["戦闘斧"]);
	deck_vec.push_back(cardData_map["如意棒"]);
	deck_vec.push_back(cardData_map["爆弾"]);
	deck_vec.push_back(cardData_map["髑髏鎌"]);
	deck_vec.push_back(cardData_map["ヨーヨー"]);
	deck_vec.push_back(cardData_map["緑のスタッフ"]);
	deck_vec.push_back(cardData_map["丸太"]);
	deck_vec.push_back(cardData_map["聖なる丸太"]);
	deck_vec.push_back(cardData_map["木刀"]);
	deck_vec.push_back(cardData_map["火炎剣"]);

	deck_vec.push_back(cardData_map["木の盾"]);
	deck_vec.push_back(cardData_map["豪華な盾"]);
	deck_vec.push_back(cardData_map["大き目な木の盾"]);
	deck_vec.push_back(cardData_map["貼り付けの盾"]);
	deck_vec.push_back(cardData_map["アイアンバックラー"]);
	deck_vec.push_back(cardData_map["ゴールドバックラー"]);
	deck_vec.push_back(cardData_map["バケツメット"]);
	deck_vec.push_back(cardData_map["レザーアーマー"]);
	deck_vec.push_back(cardData_map["騎士の鎧"]);
	deck_vec.push_back(cardData_map["翡翠の盾"]);
	deck_vec.push_back(cardData_map["霞の王の盾"]);
	deck_vec.push_back(cardData_map["王者の盾"]);

	deck_vec.push_back(cardData_map["回復の薬"]);
	deck_vec.push_back(cardData_map["回復の薬"]);
	deck_vec.push_back(cardData_map["回復の薬・改"]);
	deck_vec.push_back(cardData_map["回復の薬・改"]);
	deck_vec.push_back(cardData_map["回復の薬・真"]);
	deck_vec.push_back(cardData_map["狂化の丸薬"]);
	deck_vec.push_back(cardData_map["狂化の丸薬・改"]);
	deck_vec.push_back(cardData_map["狂化の丸薬・真"]);
	deck_vec.push_back(cardData_map["硬化のオイル"]);
	deck_vec.push_back(cardData_map["硬化のオイル・改"]);
	deck_vec.push_back(cardData_map["硬化のオイル・真"]);


	return false;
}

CardData DeckMng::Choice(std::string name)
{
	return cardData_map[name];
}

CardData DeckMng::Choice(int num)
{
	for (auto card : deck_vec)
	{
		if (card.card_No == num)
		{
			return card;
		}
	}
	return CardData();
}

CardData DeckMng::Draw()
{
	hand_vec.clear();
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand_cardsize(0,deck_vec.size()-1);
	for (int x = 0; x < 5; x++)
	{
		int a = rand_cardsize(mt);
		hand_vec.push_back(deck_vec[a]);
	}
	
	return CardData();
}

std::vector<CardData> DeckMng::GetHand()
{

	return hand_vec;
}

void DeckMng::DelHand(int number)
{
	
	hand_vec.erase(hand_vec.begin()+number);
}

void DeckMng::ChangeHand(int num, CardData data)
{
	hand_vec[num] = data;
}
