#include<EffekseerForDXLib.h>
#include "EffectMng.h"

bool EffectMng::Init(VECTOR2 size)
{
	if (Effekseer_Init(8000) == -1)
	{
		DxLib_End();
		return -1;
	}
	Effekseer_Set2DSetting(size.x, size.y);
}

void EffectMng::LoadEffect(string name, float magnification)
{
	if (effect_map[name] == -1)
	{
		effect_map[name] = LoadEffekseerEffect(("Effect/" + name + ".efk").c_str(), magnification);
		if (effect_map[name] == -1)
		{
			AST();
		}
	}
}

void EffectMng::UpData(void)
{
	UpdateEffekseer2D();
}

void EffectMng::Draw(void)
{
	DrawEffekseer2D();
}

EffectMng::~EffectMng()
{
}
