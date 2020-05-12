#pragma once
#include "PhasesBase.h"
class PhasesStanby :
	public PhasesBase
{
public:
	PhasesStanby(std::string image_name);
	~PhasesStanby();
	bool Init();
	void Updata(std::vector<PhasesBase*>& ph_vec);
	void Draw(std::vector<PhasesBase*> &ph_vec);
private:
};

