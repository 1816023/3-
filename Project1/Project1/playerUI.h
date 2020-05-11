#pragma once
#include "player.h"
class playerUI 
{
public:
	playerUI();
	~playerUI();
	bool Init();
	void Updata(std::vector<objBase*> obj);
	void Draw(objBase* obj);
private:
	std::vector<std::string> shot_type_name;
};

