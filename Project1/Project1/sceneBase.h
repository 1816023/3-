#pragma once
#include <vector>
#include <string>
#include <vector>
#define SCREEN_SIZE_X 820
#define SCREEN_SIZE_Y 640
class sceneBase
{
public:
	sceneBase();
	~sceneBase();
	virtual bool Init()=0;
	virtual void Update()=0;
	virtual void Draw()=0;
	virtual void main();
};

