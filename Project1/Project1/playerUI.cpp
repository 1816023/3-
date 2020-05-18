#include<string>
#include<vector>
#include "playerUI.h"

playerUI::playerUI()
{
}

playerUI::~playerUI()
{
}

bool playerUI::Init()
{
	FontHandle = CreateFontToHandle(NULL, 90, -1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	return true;
}

void playerUI::Updata(std::vector<objBase*> obj)
{
}

void playerUI::Draw(objBase* obj)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,200);
	int def_font_size = 17;
	VECTOR crd_size = { 192,270 };
	VECTOR im_pos = { SCREEN_SIZE_X / 2-crd_size.x/2 ,SCREEN_SIZE_Y / 1.5-crd_size.y/2 };
	//�v���C���[�J�[�h�z�u�ꏊ
	DrawBox(im_pos.x, im_pos.y,im_pos.x+ crd_size.x,im_pos.y+ crd_size.y, 0xfffffff, true);
	DrawBox(im_pos.x, im_pos.y, im_pos.x + crd_size.x, im_pos.y + crd_size.y, 0x000000, false);
	DrawString(im_pos.x, im_pos.y+crd_size.y/3,"�v���C���[\n�J�[�h", 0x000000);
	//����J�[�h�z�u�ꏊ
	DrawBox(im_pos.x - crd_size.x - 10, im_pos.y, im_pos.x  - 10, im_pos.y + crd_size.y, 0xffffff, true);
	DrawBox(im_pos.x - crd_size.x - 10, im_pos.y, im_pos.x - 10, im_pos.y + crd_size.y, 0x000000, false);
	DrawString(im_pos.x - crd_size.x - 10, im_pos.y + crd_size.y / 3, "����J�[�h", 0x000000);
	//�h��J�[�h�z�u�ꏊ
	DrawBox(im_pos.x+crd_size.x+10, im_pos.y, im_pos.x + crd_size.x*2+10, im_pos.y + crd_size.y, 0xfffffff, true);
	DrawBox(im_pos.x + crd_size.x + 10, im_pos.y, im_pos.x + crd_size.x * 2 + 10, im_pos.y + crd_size.y, 0x000000, false);
	DrawString(im_pos.x + crd_size.x + 10, im_pos.y + crd_size.y / 3, "�h��J�[�h", 0x000000);
	//��D
	DrawBox(20, SCREEN_SIZE_Y - crd_size.y/2 - 5, SCREEN_SIZE_X - 20, SCREEN_SIZE_Y - 5, 0xffffff, true);
	DrawBox(20, SCREEN_SIZE_Y - crd_size.y/2 - 5, SCREEN_SIZE_X - 20, SCREEN_SIZE_Y - 5, 0x000000, false);
	SetFontSize(50);
	DrawString(SCREEN_SIZE_X / 2 - GetDrawFormatStringWidth("��D") / 2, SCREEN_SIZE_Y - crd_size.y + 20, "��D", 0x000000);
	SetFontSize(def_font_size);
	
	DrawFormatStringToHandle(SCREEN_SIZE_X/1.3f, SCREEN_SIZE_Y/1.6, 0xff0000, FontHandle, "HP:%d\n", obj->GetHP());

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	
}
