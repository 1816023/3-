#include<string>
#include<vector>
#include "EffectMng.h"
#include "playerUI.h"

playerUI::playerUI(OBJCT_TYPE objtype) :UIBase(objtype)
{
	obj_type = objtype;
}

playerUI::~playerUI()
{
}

bool playerUI::Init()
{
	

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

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	DrawStringToHandle(SCREEN_SIZE_X / 2 - GetDrawFormatStringWidth("��D") / 2, SCREEN_SIZE_Y - crd_size.y + 20, "��D", 0x000000, GetFontHandle("AD"));
	DrawFormatStringToHandle(SCREEN_SIZE_X / 1.3f, SCREEN_SIZE_Y / 1.6, 0xff0000, GetFontHandle("HP"), "HP:%d\n", obj->GetHP());							//HP�\��
	DrawFormatStringToHandle(SCREEN_SIZE_X / 5, SCREEN_SIZE_Y / 1.5, 0xff0000, GetFontHandle("AD"), "%d\n", obj->GetAttack());								//�U���\��		
	DrawFormatStringToHandle(SCREEN_SIZE_X / 5, SCREEN_SIZE_Y / 1.5+60, 0x0000ff, GetFontHandle("AD"), "%d\n", obj->GetDefense());								//�h��\��
}
