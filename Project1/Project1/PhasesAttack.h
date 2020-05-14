#pragma once
#include "PhasesBase.h"
class PhasesAttack :
	public PhasesBase
{
public:
	PhasesAttack(std::string image_name);
	~PhasesAttack();
	bool Init();
	void Updata(std::vector<PhasesBase*> &ph_vec, PHASESTYPE& now_phases, DeckMng* card);
private:
};

