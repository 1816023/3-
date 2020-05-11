#pragma once
#include "objBase.h"
#include <map>
#define lpObjMng objMng::GetInstance()

class objMng 
{
public:
	static objMng& GetInstance(void)
	{
		static objMng i_instance;

		return i_instance;
	}

	
	 std::vector<int>& GetObj(std::string image_name);
	 std::vector<int>& GetObj(std::string image_name,VECTOR divsize,VECTOR divcnt);
private:
	objMng();
	~objMng();
	objMng& operator=(const objMng&);
	std::map<std::string, std::vector<int>>handle;

};

