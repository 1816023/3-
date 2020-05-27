#pragma once
#include"VECTOR2.h"
struct AnimData {
	std::vector<int> handle;	//�摜�̃n���h��
	VECTOR2 image_size;			//�摜�̃T�C�Y
	VECTOR2 div_cnt;			//������
	int all_div_cnt;			//��������
	VECTOR2 div_size;			//�����T�C�Y
	VECTOR2 mpf;				//1�t���[�����Ƃ̈ړ�����
	VECTOR2 pos;				//�\�����W
	int anim_speed;					//�A�j���[�V������߰��
	VECTOR2 deathtroy_pos;			//�폜���W
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

