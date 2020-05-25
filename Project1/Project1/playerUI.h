#pragma once
#include"UIBase.h"

class playerUI :public UIBase
{
public:
	playerUI(OBJCT_TYPE objtype);
	~playerUI();
	bool Init();
	void Updata(std::vector<objBase*> obj);
	void Draw(objBase* obj);
private:
	std::vector<std::string> shot_type_name;
	

};

