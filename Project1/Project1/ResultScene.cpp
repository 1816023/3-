#include"sceneMng.h"
#include "AnimMng.h"
#include <random>
#include "ResultScene.h"


struct Header {
	int rank_top;
	int rank_second;
	int rank_third;
	int rank_forth;
	int rank_fifth;
};
ResultScene::ResultScene(SCENE_TYPE type):sceneBase(type)
{
}

ResultScene::~ResultScene()
{
}

bool ResultScene::Init(sceneMng* scene)
{
	lpSoundMng.StopSound("data/sound/BGM/中ボスくらいの戦闘風_2.mp3");
	for (auto rnk : ranking)
	{
		rnk = 0;
	}
	LoadandSave(scene->GetPoint());
	click_triger = true;
	FontHandle= CreateFontToHandle(NULL, 60, -1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	MyPoint = scene->GetPoint();
	cnt["ランキング"]=0;
	pos["タイトルボタン"] = { SCREEN_SIZE_X / 1.5f - 100, 700 };
	pos["セレクトボタン"] = { SCREEN_SIZE_X / 4 - 200, 700 };
	pos["1位"] = { SCREEN_SIZE_X / 2 - GetDrawFormatStringWidthToHandle(FontHandle, "1位：%5dポイント\n", ranking[0]) / 2, 200 };
	pos["2位"] = { SCREEN_SIZE_X / 2 - GetDrawFormatStringWidthToHandle(FontHandle, "2位：%5dポイント\n", ranking[1]) / 2, 260 };
	pos["3位"] = { SCREEN_SIZE_X / 2 - GetDrawFormatStringWidthToHandle(FontHandle, "3位：%5dポイント\n", ranking[2]) / 2, 320 };
	pos["4位"] = { SCREEN_SIZE_X / 2 - GetDrawFormatStringWidthToHandle(FontHandle, "4位：%5dポイント\n", ranking[3]) / 2, 380 };
	pos["5位"] = { SCREEN_SIZE_X / 2 - GetDrawFormatStringWidthToHandle(FontHandle, "5位：%5dポイント\n", ranking[4]) / 2, 440 };
	back_vec.resize(0);
	back_vec.push_back("data/card/backTurn.png");
	back_vec.push_back("data/card/backTurn2.png");
	back_vec.push_back("data/card/backTurn3.png");
	back_vec.push_back("data/card/backTurn4.png");
	anim.resize(0);
	return true;
}

void ResultScene::Update(sceneMng* scene)
{
	VECTOR2 m_pos;
	GetMousePoint(&m_pos.x, &m_pos.y);
	cnt["ランキング"] += (cnt["ランキング"] < 700 ? 1 : 0);
	CreatBackCard();
	EraseBackCard();
	if (GetMouseInput() == MOUSE_INPUT_LEFT)
	{
		if (!click_triger)
		{
			if (HitBoxtoPoint(m_pos, pos["セレクトボタン"], VECTOR2(400, 120)))
			{
				for (auto a : anim)
				{
					delete(a);
				}
				anim.clear();
				scene->ChecgeScene(SELECT_S);
			}
			else if (HitBoxtoPoint(m_pos, pos["タイトルボタン"], VECTOR2(400, 120)))
			{
				for (auto a : anim)
				{
					delete(a);
				}
				anim.clear();
				scene->ChecgeScene(TITLE_S);
			}
			else{}
			
			click_triger = true;
			
		}
	}
	else
	{
		click_triger = false;
	}
	for (auto itr : anim)
	{
		itr->Updata();
	}
}

void ResultScene::Draw()
{
	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, 0xe58d6a, true);
	for (auto itr : anim)
	{
		itr->Draw();
	}
	DrawStringFToHandle(SCREEN_SIZE_X / 2 - GetDrawFormatStringWidthToHandle(FontHandle, "結果発表")/2, 10, "結果発表", 0xff00ff, FontHandle);

	if (cnt["ランキング"] > 30)
	{
		DrawFormatStringFToHandle(pos["5位"].x, pos["5位"].y,  0xffffff, FontHandle, "5位：%dポイント\n", ranking[4]);
	}
	if (cnt["ランキング"] > 60)
	{
		DrawFormatStringFToHandle(pos["4位"].x, pos["4位"].y, 0xffffff, FontHandle, "4位：%dポイント\n", ranking[3]);
	}
	if (cnt["ランキング"] > 120)
	{
		DrawFormatStringFToHandle(pos["3位"].x, pos["3位"].y, 0xee7800, FontHandle, "3位：%dポイント\n", ranking[2]);
	}
	if (cnt["ランキング"] > 180)
	{
		DrawFormatStringFToHandle(pos["2位"].x, pos["2位"].y, 0xc0c0c0, FontHandle, "2位：%dポイント\n", ranking[1]);
	}
	if (cnt["ランキング"] > 240)
	{
		DrawFormatStringFToHandle(pos["1位"].x, pos["1位"].y, 0xffd700, FontHandle, "1位：%dポイント\n", ranking[0],0xffffff);
	}

	DrawFormatStringFToHandle(SCREEN_SIZE_X / 2 - GetDrawFormatStringWidthToHandle(FontHandle, "今回のポイント：%dポイント\n", MyPoint) / 2, 600, 0xff0000, FontHandle, "今回のポイント%dポイント\n", MyPoint);
	VECTOR2 m_pos;
	GetMousePoint(&m_pos.x,&m_pos.y);
	DrawGraph(pos["セレクトボタン"].x, pos["セレクトボタン"].y, lpImageMng.GetInstance().GetID("data/texture/ReturnDeckSelectBottun.png", VECTOR2(400, 120), VECTOR2(2, 1))[HitBoxtoPoint(m_pos, pos["セレクトボタン"], VECTOR2(400, 120))], true);
	DrawGraph(pos["タイトルボタン"].x, pos["タイトルボタン"].y, lpImageMng.GetInstance().GetID("data/texture/ReturnTitleBottun.png", VECTOR2(400, 120), VECTOR2(2, 1))[HitBoxtoPoint(m_pos, pos["タイトルボタン"], VECTOR2(400, 120))], true);
	/*DrawString(0, 0, "result", 0xffffff);
	DrawLine(SCREEN_SIZE_X / 2, 0, SCREEN_SIZE_X / 2, SCREEN_SIZE_Y, 0xffffff);
	DrawLine(0, SCREEN_SIZE_Y / 2, SCREEN_SIZE_X, SCREEN_SIZE_Y / 2, 0xffffff);*/
}

void ResultScene::Deahtory()
{
}

bool ResultScene::AddRanking(int point)
{
	if (ranking[4]<point)
	{
		if (ranking[3] < point)
		{
			ranking[4] = ranking[3];
			if (ranking[2] < point)
			{
				ranking[3] = ranking[2];
				if (ranking[1] < point)
				{
					ranking[2] = ranking[1];
					if (ranking[0] < point)
					{
						ranking[1] = ranking[0];
						ranking[0] = point;
						
					}
					else {
						ranking[1] = point;
					}
				}
				else {
					ranking[2] = point;
				}
			}
			else {
				ranking[3] = point;
			}
		}
		else {
			ranking[4] = point;
		}
	}
	else {
		return false;
	}
	return true;
}

bool ResultScene::LoadandSave(int point)
{
	FILE* file;
	errno_t error;
	error = fopen_s(&file, "data/saveData/ranking.data", "rb");
	if (error != 0)
	{
		return false;
	}
	fread(&ranking, sizeof(ranking[0]), ranking.size(), file);
	fclose(file);
	
	out_of_ranking = (AddRanking(point) ? false : true);

	error = fopen_s(&file, "data/saveData/ranking.data", "wb");
	if (error != 0)
	{
		return false;
	}
	fwrite(&ranking, sizeof(ranking[0]), ranking.size(), file);
	fclose(file);

	return true;
}

void ResultScene::CreatBackCard()
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> data_size(0, back_vec.size() - 1);
	std::uniform_int_distribution<> rand_size(0, SCREEN_SIZE_X - 1);
	if ((rand_size(mt) / 1200) % 2)
	{
		anim.push_back(new AnimMng(back_vec[data_size(mt)], VECTOR2(640, 360), VECTOR2(10, 4), VECTOR2(rand_size(mt), -45), VECTOR2(0, 2),1));
	}
}

void ResultScene::EraseBackCard()
{
	int erase_num = -1;
	for (int a = 0; a < anim.size(); a++)
	{
		if (anim[a]->GetPos().y - 45 > SCREEN_SIZE_Y)
		{
			erase_num = a;
		}
	}
	if (erase_num != -1)
	{
		delete(anim[erase_num]);
		anim.erase(anim.begin() + erase_num);

	}
}
