#include "EffectMng.h"
#include "enemy_UI.h"

enemy_UI::enemy_UI(OBJCT_TYPE objtype):UIBase(objtype)
{
	obj_type = objtype;
}

enemy_UI::~enemy_UI()
{
}

bool enemy_UI::Init()
{
	return false;
}

void enemy_UI::Updata(std::vector<objBase*> obj)
{
}

void enemy_UI::Draw(objBase* obj)
{
	DrawFormatStringToHandle(SCREEN_SIZE_X / 1.3f, SCREEN_SIZE_Y/7, 0x0000ff, GetFontHandle("HP"), "HP:%d\n", obj->GetHP());
}
