#pragma once
#include <vector>
#include <string>
#include <DxLib.h>
#include "ImageMng.h"
#include "PhasesMng.h"
#include "DeckMng.h"
#include "objBase.h"

class DeckMng;
class objBase;
class PhasesBase
{
public:
	PhasesBase(std::string image_name);
	~PhasesBase();
	virtual bool Init()=0;
	virtual void Updata(std::vector<PhasesBase*> &ph_vec, PHASESTYPE& now_phases, DeckMng* card, std::vector<objBase*> obj)=0;
	virtual void Draw(std::vector<PhasesBase*> &ph_vec, PHASESTYPE& now_phases, DeckMng* card);
private:
protected:
	std::string image_name;
	bool triger_flag;
	bool click_flag;
};

