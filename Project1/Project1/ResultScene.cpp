#include"sceneMng.h"
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
	for (auto rnk : ranking)
	{
		rnk = 0;
	}
	LoadandSave(scene->GetPoint());
	click_triger = true;
	FontHandle= CreateFontToHandle(NULL, 60, -1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	MyPoint = scene->GetPoint();
	cnt["�����L���O"]=0;
	pos["�^�C�g���{�^��"] = { SCREEN_SIZE_X / 1.5f - 100, 700 };
	pos["�Z���N�g�{�^��"] = { SCREEN_SIZE_X / 4 - 200, 700 };
	pos["1��"] = { SCREEN_SIZE_X / 2 - GetDrawFormatStringWidthToHandle(FontHandle, "1�ʁF%5d�|�C���g\n", ranking[0]) / 2, 200 };
	pos["2��"] = { SCREEN_SIZE_X / 2 - GetDrawFormatStringWidthToHandle(FontHandle, "2�ʁF%5d�|�C���g\n", ranking[1]) / 2, 260 };
	pos["3��"] = { SCREEN_SIZE_X / 2 - GetDrawFormatStringWidthToHandle(FontHandle, "3�ʁF%5d�|�C���g\n", ranking[2]) / 2, 320 };
	pos["4��"] = { SCREEN_SIZE_X / 2 - GetDrawFormatStringWidthToHandle(FontHandle, "4�ʁF%5d�|�C���g\n", ranking[3]) / 2, 380 };
	pos["5��"] = { SCREEN_SIZE_X / 2 - GetDrawFormatStringWidthToHandle(FontHandle, "5�ʁF%5d�|�C���g\n", ranking[4]) / 2, 440 };
	return true;
}

void ResultScene::Update(sceneMng* scene)
{

	cnt["�����L���O"] += (cnt["�����L���O"] < 700 ? 1 : 0);
}

void ResultScene::Draw()
{
	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, 0xe58d6a, true);
	DrawStringFToHandle(SCREEN_SIZE_X / 2 - GetDrawFormatStringWidthToHandle(FontHandle, "���ʔ��\")/2, 10, "���ʔ��\", 0xff00ff, FontHandle);

	if (cnt["�����L���O"] > 30)
	{
		DrawFormatStringFToHandle(pos["5��"].x, pos["5��"].y,  0xffffff, FontHandle, "5�ʁF%d�|�C���g\n", ranking[4]);
	}
	if (cnt["�����L���O"] > 60)
	{
		DrawFormatStringFToHandle(pos["4��"].x, pos["4��"].y, 0xffffff, FontHandle, "4�ʁF%d�|�C���g\n", ranking[3]);
	}
	if (cnt["�����L���O"] > 120)
	{
		DrawFormatStringFToHandle(pos["3��"].x, pos["3��"].y, 0xee7800, FontHandle, "3�ʁF%d�|�C���g\n", ranking[2]);
	}
	if (cnt["�����L���O"] > 180)
	{
		DrawFormatStringFToHandle(pos["2��"].x, pos["2��"].y, 0xc0c0c0, FontHandle, "2�ʁF%d�|�C���g\n", ranking[1]);
	}
	if (cnt["�����L���O"] > 240)
	{
		DrawFormatStringFToHandle(pos["1��"].x, pos["1��"].y, 0xffd700, FontHandle, "1�ʁF%d�|�C���g\n", ranking[0],0xffffff);
	}

	DrawFormatStringFToHandle(SCREEN_SIZE_X / 2 - GetDrawFormatStringWidthToHandle(FontHandle, "����̃|�C���g�F%d�|�C���g\n", MyPoint) / 2, 600, 0xff0000, FontHandle, "����̃|�C���g%d�|�C���g\n", MyPoint);
	VECTOR2 m_pos;
	GetMousePoint(&m_pos.x,&m_pos.y);
	DrawGraph(pos["�Z���N�g�{�^��"].x, pos["�Z���N�g�{�^��"].y, lpImageMng.GetInstance().GetID("data/texture/ReturnDeckSelectBottun.png", VECTOR2(400, 120), VECTOR2(2, 1))[HitBoxtoPoint(m_pos, VECTOR2(SCREEN_SIZE_X / 4-200, 700), VECTOR2(400, 120))], true);
	DrawGraph(pos["�^�C�g���{�^��"].x, pos["�^�C�g���{�^��"].y, lpImageMng.GetInstance().GetID("data/texture/ReturnTitleBottun.png", VECTOR2(400, 120), VECTOR2(2, 1))[HitBoxtoPoint(m_pos, VECTOR2(SCREEN_SIZE_X / 1.5f-100, 700), VECTOR2(400, 120))], true);
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
