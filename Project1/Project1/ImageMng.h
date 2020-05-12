#pragma once
#include <mutex>
#include <map>
#include<vector>
#include"VECTOR2.h"
//�u��������
using VecInt = std::vector<int>;
#define lpImageMng ImageMng::GetInstance()
#define ImageID(X) (ImageMng::GetInstance().GetID(X))

class ImageMng
{
public:
	static void Creat(void);
	static void Destroy(void);
	static ImageMng&GetInstance(void)
	{
		std::call_once(initFlag, Creat);
		return *i_instance;
	}

	const VecInt& GetID(std::string f_name);
	const VecInt& GetID(std::string f_name,VECTOR2 divsize,VECTOR2 divCnt);
private:

	ImageMng();
	~ImageMng();
	static ImageMng *i_instance;
	static std::once_flag initFlag;
	//std::map<���̌^,�A�z�z��̌^>�A�z�z��;
	std::map<std::string, VecInt>imgMap;
	

};

