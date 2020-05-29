#include"sceneMng.h"
#include <array>
#include "selectScene.h"

selectScene::selectScene(SCENE_TYPE type):sceneBase(type)
{
}

selectScene::~selectScene()
{
}

bool selectScene::Init(sceneMng* scene)
{
	click_triger = true;
	select_deck = 0;
	FontHandle = CreateFontToHandle(NULL, 30, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	BigFont= CreateFontToHandle(NULL, 100, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	deck_text.resize(4);
	deck_text[0] = "";
	deck_text[1] = "攻撃型のデッキ。\n武器カードが多めに防具カードは少なめに入っている。";
	deck_text[2] = "防御型のデッキ。\n防具カードが多めに武器カードは少なめに入っている。";
	deck_text[3] = "バランスの取れたデッキ。\n武器カードと防具カードが程よく入っている。";
	click_flag = false;
	return false;
}

void selectScene::Update(sceneMng* scene)
{
	VECTOR2 m_pos;
	GetMousePoint(&m_pos.x, &m_pos.y);
	if (HitBoxtoPoint(m_pos, VECTOR2(SCREEN_SIZE_X / 4 - CARD_SIZE_X / 2, SCREEN_SIZE_Y / 2 - CARD_SIZE_Y / 2), VECTOR2(CARD_SIZE_X, CARD_SIZE_Y)))
	{
		select_deck = 1;
		click_flag = true;
	}
	else if (HitBoxtoPoint(m_pos, VECTOR2(SCREEN_SIZE_X / 2 - CARD_SIZE_X / 2, SCREEN_SIZE_Y / 2 - CARD_SIZE_Y / 2), VECTOR2(CARD_SIZE_X, CARD_SIZE_Y))) {
		select_deck = 2;
		click_flag = true;
	}
	else if (HitBoxtoPoint(m_pos, VECTOR2(SCREEN_SIZE_X / 4 * 3 - CARD_SIZE_X / 2, SCREEN_SIZE_Y / 2 - CARD_SIZE_Y / 2), VECTOR2(CARD_SIZE_X, CARD_SIZE_Y))) {
		select_deck = 3;
		click_flag = true;
	}
	else{
		select_deck = 0;
		click_flag = false;
	}
	if (click_flag)
	{
		if (GetMouseInput() == MOUSE_INPUT_LEFT)
		{
			if (!click_triger)
			{
				click_triger = true;
				scene->SetDeckType(select_deck);
				scene->ChecgeScene(GAME_S);
				
			}
		}
		else
		{
			click_triger = false;
		}
	}
}

void selectScene::Draw()
{
	DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, 0x33b750, true);

	DrawStringToHandle(SCREEN_SIZE_X/2- GetDrawFormatStringWidthToHandle(BigFont, "使いたいデッキを選ぼう")/2, 50, "使いたいデッキを選ぼう", 0xffffff, BigFont);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	if (select_deck != 0)
	{
		DrawBox(SCREEN_SIZE_X / 4 * select_deck - CARD_SIZE_X / 2 - 50, SCREEN_SIZE_Y / 2 - CARD_SIZE_Y / 2 - 50, SCREEN_SIZE_X / 4 * select_deck - CARD_SIZE_X / 2 + CARD_SIZE_X + 50, SCREEN_SIZE_Y / 2 - CARD_SIZE_Y / 2 + CARD_SIZE_Y + 50, 0xffffff, true);
	}
	DrawBox(50, SCREEN_SIZE_Y / 1.4, SCREEN_SIZE_X - 50, SCREEN_SIZE_Y - 50, 0xffffff, true);
	DrawBox(50, SCREEN_SIZE_Y / 1.4, SCREEN_SIZE_X - 50, SCREEN_SIZE_Y - 50, 0x000000, false);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	
	DrawGraph(SCREEN_SIZE_X / 4 - CARD_SIZE_X / 2, SCREEN_SIZE_Y / 2-CARD_SIZE_Y/2, IMAGE_ID("data/card/Recard.png")[0], true);
	DrawStringFToHandle(SCREEN_SIZE_X / 4 - CARD_SIZE_X / 2-15, SCREEN_SIZE_Y / 2 + CARD_SIZE_Y/2, "攻撃型のデッキ", 0xff00ff,FontHandle);
	
	DrawGraph(SCREEN_SIZE_X / 2 - CARD_SIZE_X / 2, SCREEN_SIZE_Y / 2 - CARD_SIZE_Y / 2, IMAGE_ID("data/card/Recard.png")[0], true);
	DrawStringFToHandle(SCREEN_SIZE_X / 2 - CARD_SIZE_X / 2-15, SCREEN_SIZE_Y / 2 + CARD_SIZE_Y / 2, "防御型のデッキ", 0x6600ff, FontHandle);
	
	DrawGraph(SCREEN_SIZE_X / 4 * 3 - CARD_SIZE_X / 2, SCREEN_SIZE_Y / 2 - CARD_SIZE_Y / 2, IMAGE_ID("data/card/Recard.png")[0], true);
	DrawStringFToHandle(SCREEN_SIZE_X / 4 * 3 - CARD_SIZE_X / 2-30, SCREEN_SIZE_Y / 2 + CARD_SIZE_Y / 2, "バランス型デッキ", 0x00ff33, FontHandle);
	DrawStringToHandle(SCREEN_SIZE_X / 2 - GetDrawFormatStringWidthToHandle(FontHandle,deck_text[select_deck].c_str()) / 2, SCREEN_SIZE_Y / 1.25, deck_text[select_deck].c_str(), 0xffffff, FontHandle,0x991166);
	
	//DrawString(0, 0, "selsect", 0xffffff);
}

void selectScene::Deahtory()
{
}
