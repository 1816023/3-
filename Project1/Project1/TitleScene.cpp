#include"sceneMng.h"
#include "AnimMng.h"
#include <random>
#include "TitleScene.h"

TitleScene::TitleScene(SCENE_TYPE type):sceneBase(type)
{
}

TitleScene::~TitleScene()
{
}

bool TitleScene::Init(sceneMng* scene)
{
	anim.resize(0);
	click_triger = false;
	back_vec.resize(0);
	back_vec.push_back("data/card/backTurn.png");
	back_vec.push_back("data/card/backTurn2.png");
	back_vec.push_back("data/card/backTurn3.png");
	back_vec.push_back("data/card/backTurn4.png");
	flash_cnt = 0;
	return false;
}

void TitleScene::Update(sceneMng* scene)
{
	CreatBackCard();
	EraseBackCard();
	flash_cnt++;
	if (GetMouseInput() == MOUSE_INPUT_LEFT)
	{
		if (!click_triger)
		{
			for (auto a : anim)
			{
				delete(a);
			}
			anim.clear();
			click_triger = true;
			scene->ChecgeScene(SELECT_S);
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

void TitleScene::Draw()
{
	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, 0x222222, true);
	for (auto itr : anim)
	{
		itr->Draw();
	}

	DrawGraph(0, 0, IMAGE_ID("data/texture/titleBack.png")[0], true);
	//DrawString(0, 0, "Title", 0xffffff);
	//DrawFormatString(0, 20, 0xff0000, "%d\n", anim.size());
	if (flash_cnt /10 % 2)
	{
		DrawString(SCREEN_SIZE_X/2- GetDrawFormatStringWidth("Please Push")/2, SCREEN_SIZE_Y/1.25, "Please Push", 0xffff00);

	}
}

void TitleScene::Deahtory()
{
}

void TitleScene::CreatBackCard()
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> data_size(0, back_vec.size() - 1);
	std::uniform_int_distribution<> rand_size(0, SCREEN_SIZE_X - 1);
	if ((rand_size(mt) / 100) % 2)
	{
		anim.push_back(new AnimMng(back_vec[data_size(mt)], VECTOR2(640, 360), VECTOR2(10, 4), VECTOR2(rand_size(mt), -45), VECTOR2(0, 2)));
	}
}

void TitleScene::EraseBackCard()
{
	int erase_num=-1;
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
