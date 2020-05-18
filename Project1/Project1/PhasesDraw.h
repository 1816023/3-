#pragma once
#include "PhasesBase.h"
class PhasesDraw :
	public PhasesBase
{
public:
	PhasesDraw(std::string image_name);
	~PhasesDraw();
	bool Init();
	void Updata(std::vector<PhasesBase*> &ph_vec, PHASESTYPE& now_phases, DeckMng* card, std::vector<objBase*> obj);
private:
	bool drawF;
};

