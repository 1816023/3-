#include "enemy.h"
#include"ImageMng.h"


enemy::enemy(std::string image_name,VECTOR pos):objBase(image_name)
{
	data.imageName = image_name;
	data.pos = pos;
}

enemy::~enemy()
{
}

bool enemy::Init()
{
	data.objType = TYPE_ENEMY;
	data.imageSize = { 64,45 };
	lpObjMng.GetObj(data.imageName, { 65,45 }, {2,1});
	//LoadDivGraph(data.imageName.c_str(), 2, 2, 1, 64, 45, data.imageDivH);
	
	damageFlag = false;
	LRMoveFlag = true;
	deathCnt = DEATH_CNT;
	enemy_data["スライム"]		=	{ "スライム",		10,	0,	3,	0,0,0,	0,0,IMAGE_ID("data/texture/enemy_sra.png")	[0],10,	1 };
	enemy_data["ゴブリン"]		=	{ "ゴブリン",		20,	0,	5,	0,0,2,	0,0,IMAGE_ID("data/texture/enemy_gob.png")	[0],10,	2 };
	enemy_data["スケルトン"]	=	{ "スケルトン",		25,	0,	6,	0,0,3,	0,0,IMAGE_ID("data/texture/enemy_suke.png")	[0],10,	2 };
	enemy_data["ゾンビ"]		=	{ "ゾンビ",			25,	0,	7,	0,0,3,	0,0,IMAGE_ID("data/texture/enemy_zon2.png")	[0],10,	2 };
	enemy_data["ゾンビドッグ"]	=	{ "ゾンビドッグ",	20,	0,	9,	0,0,2,	0,0,IMAGE_ID("data/texture/enemy_zon1.png")	[0],10,	2 };
	enemy_data["盗賊"]			=	{ "盗賊",			30,	0,	6,	0,0,4,	0,0,IMAGE_ID("data/texture/enemy_zoku.png")	[0],10,	2 };
	enemy_data["オーク"]		=	{ "オーク",			40,	0,	6,	0,0,6,	0,0,IMAGE_ID("data/texture/enemy_oku.png")	[0],10,	2 };
	enemy_data["ビッグフット"]	=	{ "ビッグフット",	40,	0,	8,	0,0,5,	0,0,IMAGE_ID("data/texture/enemy_big.png")	[0],10,	2 };
	enemy_data["オーガ"]		=	{ "オーガ",			45,	0,	8,	0,0,6,	0,0,IMAGE_ID("data/texture/enemy_oga.png")	[0],10,	2 };
	enemy_data["ガーゴイル"]	=	{ "ガーゴイル",		35,	0,	8,	0,0,7,	0,0,IMAGE_ID("data/texture/enemy_gago.png")	[0],10,	2 };
	enemy_data["マンドラゴ"]	=	{ "マンドラゴ",		10,	0,	30,	0,0,0,	0,0,IMAGE_ID("data/texture/enemy_man.png")	[0],10,	2 };
	enemy_data["ミミック"]		=	{ "ミミック",		40,	0,	7,	0,0,5,	0,0,IMAGE_ID("data/texture/enemy_mimi.png")	[0],10,	2 };
	enemy_data["ミイラ男"]		=	{ "ミイラ男",		30,	0,	8,	0,0,4,	0,0,IMAGE_ID("data/texture/enemy_mii.png")	[0],10,	2 };
	enemy_data["サキュバス"]	=	{ "サキュバス",		55,	0,	10,	0,0,5,	0,0,IMAGE_ID("data/texture/enemy_sakyu.png")[0],10,	2 };
	enemy_data["フランケン"]	=	{ "フランケン",		50,	0,	8,	0,0,6,	0,0,IMAGE_ID("data/texture/enemy_fura.png")	[0],10,	2 };
	enemy_data["狼男"]			=	{ "狼男",			30,	0,	10,	0,0,4,	0,0,IMAGE_ID("data/texture/enemy_oo.png")	[0],10,	2 };
	enemy_data["ヴァンパイア"]	=	{ "ヴァンパイア",	60,	0,	13,	0,0,5,	0,0,IMAGE_ID("data/texture/enemy_van.png")	[0],10,	2 };
	enemy_data["ワイバーン"]	=	{ "ワイバーン",		50,	0,	9,	0,0,6,	0,0,IMAGE_ID("data/texture/enemy_wai.png")	[0],10,	2 };
	enemy_data["ハエトリグサ"]	=	{ "ハエトリグサ",	20,	0,	8,	0,0,4,	0,0,IMAGE_ID("data/texture/enemy_hae.png")	[0],10,	2 };
	enemy_data["キメラ"]		=	{ "キメラ",			70,	0,	9,	0,0,5,	0,0,IMAGE_ID("data/texture/enemy_kime.png")	[0],10,	2 };
	enemy_data["ゴーレム"]		=	{ "ゴーレム",		100,0,	7,	0,0,7,	0,0,IMAGE_ID("data/texture/enemy_gore.png")	[0],10,	2 };
	enemy_data["グリフォン"]	=	{ "グリフォン",		60,	0,	6,	0,0,6,	0,0,IMAGE_ID("data/texture/enemy_guri.png")	[0],10,	2 };
	enemy_data["デュラハン"]	=	{ "デュラハン",		60,	0,	5,	0,0,7,	0,0,IMAGE_ID("data/texture/enemy_dhura.png")[0],10,	2 };
	enemy_data["ベルゼブル"]	=	{ "ベルゼブル",		90,	0,	10,	0,0,5,	0,0,IMAGE_ID("data/texture/enemy_bel.png")	[0],10,	2 };
	enemy_data["魔王"]			=	{ "魔王",			150,0,	16,	0,0,4,	0,0,IMAGE_ID("data/texture/enemy_mao.png")	[0],10,	2 };
	enemy_data["ドラゴン"]		=	{ "ドラゴン",		200,0,	20,	0,0,9,	0,0,IMAGE_ID("data/texture/enemy_dora.png")	[0],10,	2 };

	state.push_back( enemy_data["スライム"]);
	state.push_back(enemy_data["ゴブリン"]);
	state.push_back(enemy_data["スケルトン"]);
	state.push_back(enemy_data["ゾンビ"]);
	state.push_back(enemy_data["ゾンビドッグ"]);
	state.push_back(enemy_data["盗賊"]);
	state.push_back(enemy_data["ビッグフット"]);
	state.push_back(enemy_data["オーガ"]);
	state.push_back(enemy_data["ガーゴイル"]);
	state.push_back(enemy_data["マンドラゴ"]);
	state.push_back(enemy_data["ミミック"]);
	state.push_back(enemy_data["ミイラ男"]);
	state.push_back(enemy_data["サキュバス"]);
	state.push_back(enemy_data["フランケン"]);
	state.push_back(enemy_data["狼男"]);
	state.push_back(enemy_data["ヴァンパイア"]);
	state.push_back(enemy_data["ワイバーン"]);
	state.push_back(enemy_data["ハエトリグサ"]);
	state.push_back(enemy_data["キメラ"]);
	state.push_back(enemy_data["ゴーレム"]);
	state.push_back(enemy_data["グリフォン"]);
	state.push_back(enemy_data["デュラハン"]);
	state.push_back(enemy_data["ベルゼブル"]);
	state.push_back(enemy_data["魔王"]);
	state.push_back(enemy_data["ドラゴン"]);

	enemy_number = 0;
	return true;
}

void enemy::update(std::vector<objBase*>&obj, char* getKey, PhasesMng* phases)
{
	move();
	
	if (phases->GetNowPhases() == ENEMY_TURN)
	{
		attack(obj);
		phases->ChangePhases(PHASES_DRAW);
	}
}

void enemy::Draw( PhasesMng* phases)
{
	if (phases->GetNowPhases() == ENEMY_TURN)
	{
		DrawRotaGraph(SCREEN_SIZE_X/2, SCREEN_SIZE_Y/2 - 60,1.5,0, IMAGE_ID("data/texture/EnemyTurnImage.png")[0], true);
	}
	DrawRotaGraph(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 4 - 60, 1, 0,state[enemy_number].enemy_handle, true);
}

void enemy::damage(int damage_num)
{
	state[enemy_number].HP += (GetDefense() - damage_num>0?0: GetDefense() - damage_num);
	if (state[enemy_number].HP <= 0)
	{
		state[enemy_number] = enemy_data[state[enemy_number].name];
		enemy_number = (enemy_number+1 >= state.size() ? 0 : enemy_number+1);
	}
}

void enemy::attack(std::vector<objBase*>& obj)
{
	for (auto itr : obj)
	{
		if (itr->GetObjctType() == TYPE_PLAYER)
		{
			itr->damage(state[enemy_number].attack + state[enemy_number].add_attack + state[enemy_number].def_attack);
		}
	}
}


void enemy::Standby(DeckMng* card)
{
}

void enemy::move()
{
	
}
