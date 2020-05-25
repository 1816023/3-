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

	cardData_map["�q�m�L�̖_"] =		{	"�q�m�L�̖_",			WEAPON_CARD,	101,	"data/card/A01.png",	IMAGE_ID("data/card/A01.png")[0],	2,	0,	NO_EFFECT	};
	cardData_map["�����ȃq�m�L�̖_"] =	{	"�����ȃq�m�L�̖_",		WEAPON_CARD,	102,	"data/card/A02.png",	IMAGE_ID("data/card/A02.png")[0],	4,	0,	NO_EFFECT	};
	cardData_map["�`���̃q�m�L�̖_"] =	{	"�`���̃q�m�L�̖_",		WEAPON_CARD,	103,	"data/card/A03.png",	IMAGE_ID("data/card/A03.png")[0],	20,	0,	NO_EFFECT	};
	cardData_map["�P���p�̖،�"] =		{	"�P���p�̖،�",			WEAPON_CARD,	104,	"data/card/A04.png",	IMAGE_ID("data/card/A04.png")[0],	1,	0,	NO_EFFECT	};
	cardData_map["�S�̑匕"] =			{	"�S�̑匕",				WEAPON_CARD,	105,	"data/card/A05.png",	IMAGE_ID("data/card/A05.png")[0],	6,	0,	NO_EFFECT	};
	cardData_map["�o�X�^�[�\�[�h"] =	{	"�o�X�^�[�\�[�h",		WEAPON_CARD,	106,	"data/card/A06.png",	IMAGE_ID("data/card/A06.png")[0],	10,	0,	NO_EFFECT	};
	cardData_map["������������"] =		{	"������������",			WEAPON_CARD,	107,	"data/card/A07.png",	IMAGE_ID("data/card/A07.png")[0],	5,	0,	NO_EFFECT	};
	cardData_map["�퓬��"] =			{	"�퓬��",				WEAPON_CARD,	108,	"data/card/A08.png",	IMAGE_ID("data/card/A08.png")[0],	7,	0,	NO_EFFECT	};
	cardData_map["�@�Ӗ_"] =			{	"�@�Ӗ_",				WEAPON_CARD,	109,	"data/card/A09.png",	IMAGE_ID("data/card/A09.png")[0],	11,	0,	NO_EFFECT	};
	cardData_map["���e"] =				{	"���e",					WEAPON_CARD,	110,	"data/card/A10.png",	IMAGE_ID("data/card/A10.png")[0],	10,	0,	NO_EFFECT	};
	cardData_map["�鐊�"] =			{	"�鐊�",				WEAPON_CARD,	111,	"data/card/A11.png",	IMAGE_ID("data/card/A11.png")[0],	7,	0,	NO_EFFECT	};
	cardData_map["���[���["] =			{	"���[���[",				WEAPON_CARD,	112,	"data/card/A12.png",	IMAGE_ID("data/card/A12.png")[0],	4,	0,	NO_EFFECT	};
	cardData_map["�΂̃X�^�b�t"] =		{	"�΂̃X�^�b�t",			WEAPON_CARD,	113,	"data/card/A13.png",	IMAGE_ID("data/card/A13.png")[0],	7,	0,	NO_EFFECT	};
	cardData_map["�ۑ�"] =				{	"�ۑ�",					WEAPON_CARD,	114,	"data/card/A14.png",	IMAGE_ID("data/card/A14.png")[0],	12,	0,	NO_EFFECT	};
	cardData_map["���Ȃ�ۑ�"] =		{	"���Ȃ�ۑ�",			WEAPON_CARD,	115,	"data/card/A15.png",	IMAGE_ID("data/card/A15.png")[0],	13,	0,	NO_EFFECT	};
	cardData_map["�ؓ�"] =				{	"�ؓ�",					WEAPON_CARD,	116,	"data/card/A16.png",	IMAGE_ID("data/card/A16.png")[0],	5,	0,	NO_EFFECT	};
	cardData_map["�Ή���"] =			{	"�Ή���",				WEAPON_CARD,	117,	"data/card/A17.png",	IMAGE_ID("data/card/A17.png")[0],	9,	0,	NO_EFFECT	};

	cardData_map["�؂̏�"] =			{	"�؂̏�",				ARMOR_CARD,		201,	"data/card/S01.png",	IMAGE_ID("data/card/S01.png")[0],	0,	2,	NO_EFFECT	};
	cardData_map["���؂ȏ�"] =			{	"���؂ȏ�",				ARMOR_CARD,		202,	"data/card/S02.png",	IMAGE_ID("data/card/S02.png")[0],	0,	3,	NO_EFFECT	};
	cardData_map["�傫�ڂȖ؂̏�"] =	{	"�傫�ڂȖ؂̏�",		ARMOR_CARD,		203,	"data/card/S03.png",	IMAGE_ID("data/card/S03.png")[0],	0,	4,	NO_EFFECT	};
	cardData_map["�\��t���̏�"] =		{	"�\��t���̏�",			ARMOR_CARD,		204,	"data/card/S04.png",	IMAGE_ID("data/card/S04.png")[0],	0,	6,	NO_EFFECT	};
	cardData_map["�A�C�A���o�b�N���["] ={	"�A�C�A���o�b�N���[",	ARMOR_CARD,		205,	"data/card/S05.png",	IMAGE_ID("data/card/S05.png")[0],	0,	6,	NO_EFFECT	};
	cardData_map["�S�[���h�o�b�N���["] ={	"�S�[���h�o�b�N���[",	ARMOR_CARD,		206,	"data/card/S06.png",	IMAGE_ID("data/card/S06.png")[0],	0,	4,	NO_EFFECT	};
	cardData_map["�o�P�c���b�g"] =		{	"�o�P�c���b�g",			ARMOR_CARD,		207,	"data/card/S07.png",	IMAGE_ID("data/card/S07.png")[0],	0,	3,	NO_EFFECT	};
	cardData_map["���U�[�A�[�}�["] =	{	"���U�[�A�[�}�[",		ARMOR_CARD,		208,	"data/card/S08.png",	IMAGE_ID("data/card/S08.png")[0],	0,	4,	NO_EFFECT	};
	cardData_map["�R�m�̊Z"] =			{	"�R�m�̊Z",				ARMOR_CARD,		209,	"data/card/S09.png",	IMAGE_ID("data/card/S09.png")[0],	0,	7,	NO_EFFECT	};
	cardData_map["�Ő��̏�"] =			{	"�Ő��̏�",				ARMOR_CARD,		210,	"data/card/S10.png",	IMAGE_ID("data/card/S10.png")[0],	0,	6,	NO_EFFECT	};
	cardData_map["���̉��̏�"] =		{	"���̉��̏�",			ARMOR_CARD,		211,	"data/card/S11.png",	IMAGE_ID("data/card/S11.png")[0],	0,	9,	NO_EFFECT	};
	cardData_map["���҂̏�"] =			{	"���҂̏�",				ARMOR_CARD,		212,	"data/card/S12.png",	IMAGE_ID("data/card/S12.png")[0],	0,	15,	NO_EFFECT	};

	cardData_map["�񕜂̖�"] =			{	"�񕜂̖�",				ITEM_CARD,		301,	"data/card/I01.png",	IMAGE_ID("data/card/I01.png")[0],	5,	0,	RECOVERY_HP };
	cardData_map["�񕜂̖�E��"] =		{	"�񕜂̖�E��",			ITEM_CARD,		302,	"data/card/I02.png",	IMAGE_ID("data/card/I02.png")[0],	10,	0,	RECOVERY_HP	};
	cardData_map["�񕜂̖�E�^"] =		{	"�񕜂̖�E�^",			ITEM_CARD,		303,	"data/card/I03.png",	IMAGE_ID("data/card/I03.png")[0],	15,	0,	RECOVERY_HP	};
	cardData_map["�����̊ۖ�"] =		{	"�����̊ۖ�",			ITEM_CARD,		304,	"data/card/I04.png",	IMAGE_ID("data/card/I04.png")[0],	5,	0,	ADD_ATTACK	};
	cardData_map["�����̊ۖ�E��"] =	{	"�����̊ۖ�E��",		ITEM_CARD,		305,	"data/card/I05.png",	IMAGE_ID("data/card/I05.png")[0],	7,	0,	ADD_ATTACK	};
	cardData_map["�����̊ۖ�E�^"] =	{	"�����̊ۖ�E�^",		ITEM_CARD,		306,	"data/card/I06.png",	IMAGE_ID("data/card/I06.png")[0],	10,	0,	ADD_ATTACK	};
	cardData_map["�d���̃I�C��"] =		{	"�d���̃I�C��",			ITEM_CARD,		307,	"data/card/I07.png",	IMAGE_ID("data/card/I07.png")[0],	5,	0,	ADD_DEFENSE	};
	cardData_map["�d���̃I�C���E��"] =	{	"�d���̃I�C���E��",		ITEM_CARD,		308,	"data/card/I08.png",	IMAGE_ID("data/card/I08.png")[0],	7,	0,	ADD_DEFENSE	};
	cardData_map["�d���̃I�C���E�^"] =	{	"�d���̃I�C���E�^",		ITEM_CARD,		309,	"data/card/I09.png",	IMAGE_ID("data/card/I09.png")[0],	10,	0,	ADD_DEFENSE	};

	deck_vec.push_back(cardData_map["�q�m�L�̖_"]);
	deck_vec.push_back(cardData_map["�����ȃq�m�L�̖_"]);
	deck_vec.push_back(cardData_map["�`���̃q�m�L�̖_"]);
	deck_vec.push_back(cardData_map["�P���p�̖،�"]);
	deck_vec.push_back(cardData_map["�S�̑匕"]);
	deck_vec.push_back(cardData_map["�o�X�^�[�\�[�h"]);
	deck_vec.push_back(cardData_map["������������"]);
	deck_vec.push_back(cardData_map["�퓬��"]);
	deck_vec.push_back(cardData_map["�@�Ӗ_"]);
	deck_vec.push_back(cardData_map["���e"]);
	deck_vec.push_back(cardData_map["�鐊�"]);
	deck_vec.push_back(cardData_map["���[���["]);
	deck_vec.push_back(cardData_map["�΂̃X�^�b�t"]);
	deck_vec.push_back(cardData_map["�ۑ�"]);
	deck_vec.push_back(cardData_map["���Ȃ�ۑ�"]);
	deck_vec.push_back(cardData_map["�ؓ�"]);
	deck_vec.push_back(cardData_map["�Ή���"]);

	deck_vec.push_back(cardData_map["�؂̏�"]);
	deck_vec.push_back(cardData_map["���؂ȏ�"]);
	deck_vec.push_back(cardData_map["�傫�ڂȖ؂̏�"]);
	deck_vec.push_back(cardData_map["�\��t���̏�"]);
	deck_vec.push_back(cardData_map["�A�C�A���o�b�N���["]);
	deck_vec.push_back(cardData_map["�S�[���h�o�b�N���["]);
	deck_vec.push_back(cardData_map["�o�P�c���b�g"]);
	deck_vec.push_back(cardData_map["���U�[�A�[�}�["]);
	deck_vec.push_back(cardData_map["�R�m�̊Z"]);
	deck_vec.push_back(cardData_map["�Ő��̏�"]);
	deck_vec.push_back(cardData_map["���̉��̏�"]);
	deck_vec.push_back(cardData_map["���҂̏�"]);

	deck_vec.push_back(cardData_map["�񕜂̖�"]);
	deck_vec.push_back(cardData_map["�񕜂̖�"]);
	deck_vec.push_back(cardData_map["�񕜂̖�E��"]);
	deck_vec.push_back(cardData_map["�񕜂̖�E��"]);
	deck_vec.push_back(cardData_map["�񕜂̖�E�^"]);
	deck_vec.push_back(cardData_map["�����̊ۖ�"]);
	deck_vec.push_back(cardData_map["�����̊ۖ�E��"]);
	deck_vec.push_back(cardData_map["�����̊ۖ�E�^"]);
	deck_vec.push_back(cardData_map["�d���̃I�C��"]);
	deck_vec.push_back(cardData_map["�d���̃I�C���E��"]);
	deck_vec.push_back(cardData_map["�d���̃I�C���E�^"]);


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
