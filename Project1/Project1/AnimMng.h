#pragma once
#include"VECTOR2.h"
struct AnimData {
	std::vector<int> handle;	//画像のハンドル
	VECTOR2 image_size;			//画像のサイズ
	VECTOR2 div_cnt;			//分割数
	int all_div_cnt;			//総分割数
	VECTOR2 div_size;			//分割サイズ
	VECTOR2 mpf;				//1フレームごとの移動距離
	VECTOR2 pos;				//表示座標
	int anim_speed;					//アニメーションｽﾋﾟｰﾄﾞ
	VECTOR2 deathtroy_pos;			//削除座標
};
class AnimMng
{
public:
	AnimMng(std::string animHandle,VECTOR2 image_size,VECTOR2 div_cnt,VECTOR2 draw_pos,VECTOR2 mpf,int anim_speed=1, VECTOR2 deathtroy_pos = VECTOR2(-9999, -9999));
	~AnimMng();
	void Updata();
	void Draw();
	VECTOR2 GetPos() { return data.pos + data.mpf*anim_cnt; }
private:
	AnimData data;
	int anim_cnt;
};

