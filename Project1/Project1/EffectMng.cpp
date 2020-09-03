#include <EffekseerForDXLib.h>
#include "EffectMng.h"

EffectMng::EffectMng()
{
}
EffectMng::~EffectMng()
{
}

bool EffectMng::Init(VECTOR2 size)
{
	if (Effekseer_Init(8000) == -1)
	{
		DxLib_End();
		return -1;
	}
	Effekseer_Set2DSetting(size.x, size.y);

	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);
}

//Effect���g�p����Ƃ���Init�ŌĂяo��
void EffectMng::LoadEffect(string name, float magnification)
{
	if (effect_map.find(name) == effect_map.end())
	{
		effect_map[name] = LoadEffekseerEffect(("Effect/" + name + ".efkefc").c_str(), magnification);
		if (effect_map[name] == -1)
		{
			AST();
		}
	}
}

//�Ăяo�������^�C�~���O�̏����ňꏏ�ɌĂ�
void EffectMng::AddPlayList(string name, float pos_x, float pos_y)
{
	play_list.push_front(PlayEffekseer2DEffect(effect_map[name]));
	
	num = SetPosPlayingEffekseer2DEffect(play_list.front(), pos_x, pos_y, 0);

}

//���ꂼ���UpData�ŌĂяo��
void EffectMng::UpData(void)
{
	UpdateEffekseer2D();
	auto itr = remove_if(play_list.begin(), play_list.end(), [](int handle) {return !IsEffekseer2DEffectPlaying(handle); });
	play_list.erase(itr, play_list.end());
}

//���ꂼ���Draw�ŌĂяo��
void EffectMng::Draw(void)
{
	DrawEffekseer2D();
}
