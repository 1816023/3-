#include "objMng.h"

objMng::objMng()
{
}

objMng::~objMng()
{
}

std::vector<int>&  objMng::GetObj(std::string image_name)
{
	if (handle.find(image_name) == handle.end())
	{
		handle[image_name].resize(1);
		handle[image_name][0]=LoadGraph(image_name.c_str());
	}

	return handle[image_name];
}

std::vector<int>& objMng::GetObj(std::string image_name, VECTOR divsize, VECTOR divcnt)
{
	if (handle.find(image_name) == handle.end())
	{
		handle[image_name].resize(divcnt.x*divcnt.y);
		LoadDivGraph(image_name.c_str(), divcnt.x * divcnt.y, divcnt.x, divcnt.y, divsize.x, divsize.y, &handle[image_name][0]);

	}

	return handle[image_name];
	// TODO: return ステートメントをここに挿入します
}
