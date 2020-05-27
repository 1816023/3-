#include <string>
#include<DxLib.h>
#include<vector>
#include"ImageMng.h"
#include "AnimMng.h"

AnimMng::AnimMng(std::string animHandle, VECTOR2 image_size, VECTOR2 div_cnt, VECTOR2 draw_pos, VECTOR2 mpf,int anim_speed, VECTOR2 deathtroy_pos)
{
	anim_cnt = 0;
	data.image_size = image_size;
	data.div_cnt = div_cnt;
	data.div_size = image_size / div_cnt;
	data.pos = draw_pos;
	data.all_div_cnt = data.div_cnt.y * data.div_cnt.x;
	data.handle.resize(data.all_div_cnt);	
	data.mpf = mpf;
	data.anim_speed = anim_speed;
	data.handle = lpImageMng.GetInstance().GetID(animHandle, data.div_size, data.div_cnt);
	//LoadDivGraph(animHandle.c_str(), data.all_div_cnt, data.div_cnt.x, data.div_cnt.y, data.div_size.x, data.div_size.y, &data.handle[0]);
}

AnimMng::~AnimMng()
{
}

void AnimMng::Updata()
{
	anim_cnt++;
}

void AnimMng::Draw()
{
	/*for (int a=0;a< data.handle.size();a++)
	{
		DrawGraph( data.div_size.x * (a % data.div_cnt.x),  data.div_size.y * (a / data.div_cnt.y), data.handle[a], true);
	}*/
	DrawRotaGraph(data.pos.x+data.mpf.x*anim_cnt, data.pos.y+data.mpf.y*anim_cnt,1,0, data.handle[anim_cnt/data.anim_speed %(data.all_div_cnt)], true);
}
