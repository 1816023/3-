#pragma once

#ifdef _DEBUG
#define AST(){\
	CHAR ast_mes[256];\
	wsprintf(ast_mes, "%s %dçsñ⁄Åè0", __FILE__, __LINE__);\
	MessageBox(0, ast_mes, "±ª∞ƒï\é¶", MB_OK);\
	}
#else
#define AST()
#endif    // _DEBUG

#include <Map>
#include <List>

#include "VECTOR2.h"

using namespace std;
class EffectMng
{
public:
	bool Init(VECTOR2 size);
	void LoadEffect(string name, float magnification);
	void UpData(void);
	void Draw(void);

private:
	EffectMng();
	~EffectMng();


	map<string, int> effect_map;
	list<string> play_list;

	float pos_x;
	float pos_y;
};

