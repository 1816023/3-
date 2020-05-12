#pragma once
#include "PhasesBase.h"
class PhasesDraw :
	public PhasesBase
{
public:
	PhasesDraw(std::string image_name);
	~PhasesDraw();
	bool Init();
	void Updata(std::vector<PhasesBase*> &ph_vec);
	void Draw(std::vector<PhasesBase*>& ph_vec);
private:

};

