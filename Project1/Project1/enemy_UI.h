#pragma once
#include "UIBase.h"
class enemy_UI:public UIBase
{
public:
	enemy_UI(OBJCT_TYPE objtype);
	~enemy_UI();
	bool Init();
	void Updata(std::vector<objBase*> obj);
	void Draw(objBase* obj);
private:
};

