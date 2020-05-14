#pragma once
#include <vector>
#include <string>
#include <DxLib.h>
#include "ImageMng.h"
#include "PhasesMng.h"
#include "DeckMng.h"
class DeckMng;
class PhasesBase
{
public:
	PhasesBase(std::string image_name);
	~PhasesBase();
	virtual bool Init()=0;
	virtual void Updata(std::vector<PhasesBase*> &ph_vec, PHASESTYPE& now_phases, DeckMng* card)=0;
	virtual void Draw(std::vector<PhasesBase*> &ph_vec, PHASESTYPE& now_phases, DeckMng* card);
private:
protected:
	std::string image_name;

};

