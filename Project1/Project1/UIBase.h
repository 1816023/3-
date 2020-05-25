#pragma once
#include <vector>
#include "objBase.h"
class UIBase
{
public:
	UIBase(OBJCT_TYPE objtype);
	~UIBase();
	virtual bool Init() = 0;
	virtual void Updata(std::vector<objBase*> obj) = 0;
	virtual void Draw(objBase* obj)=0;
	virtual OBJCT_TYPE GetObjType() { return obj_type; }
private:
	std::map<std::string, int> FontHandle;
protected:
	int GetFontHandle(std::string name) { return FontHandle[name]; };
	OBJCT_TYPE obj_type;
};

