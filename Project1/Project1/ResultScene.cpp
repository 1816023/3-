#include"sceneMng.h"
#include "ResultScene.h"


struct Header {

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

	return true;
}

void ResultScene::Update(sceneMng* scene)
{
}

void ResultScene::Draw()
{
	DrawString(0, 0, "result", 0xffffff);
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
			if (ranking[2] < point)
			{
				if (ranking[1] < point)
				{
					if (ranking[0] < point)
					{
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
	error = fopen_s(&file, "data/saveData/rankingData.data", "rb");
	if (error != 0)
	{
		return false;
	}
	fread(&ranking, sizeof(ranking), 1, file);
	out_of_ranking = (AddRanking(point) ? false : true);
	fwrite(&ranking, sizeof(ranking), 1, file);
	fclose(file);

	return true;
}
