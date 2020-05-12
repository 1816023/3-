#include "ImageMng.h"
#include "DxLib.h"


ImageMng*ImageMng::i_instance=nullptr;
std::once_flag ImageMng::initFlag;

void ImageMng::Destroy(void)
{
	if (i_instance != nullptr)
	{
		delete i_instance;
	}
	i_instance = nullptr;
}

void ImageMng::Creat(void)
{
	i_instance = new ImageMng;
}

const VecInt& ImageMng::GetID(std::string f_name)
{
	//f_nameとimage/を合体
	std::string name = "image/" + f_name;
	//stringをcharに変換
	const char*file_name = name.c_str();


	if (imgMap.find(f_name) == imgMap.end())//問い合わせ//見つからなかったらendが返ってくる
	{
		imgMap[f_name].resize(1);
		//f_nameをﾛｰﾄﾞする
		imgMap[f_name][0] = LoadGraph(file_name);
	}
		return imgMap[f_name];
		
}

const VecInt & ImageMng::GetID(std::string f_name, VECTOR2 divsize, VECTOR2 divCnt)
{
	std::string name = "image/" + f_name;
	const char*file_name = name.c_str();
	if (imgMap.find(f_name) == imgMap.end())
	{
		imgMap[f_name].resize(divCnt.x*divCnt.y);
		//f_nameをﾛｰﾄﾞする
		 LoadDivGraph(file_name, divCnt.x*divCnt.y,divCnt.x,divCnt.y,divsize.x,divsize.y, &imgMap[f_name][0]);


	}

	return imgMap[f_name];

}

ImageMng::ImageMng()
{
}


ImageMng::~ImageMng()
{
}
