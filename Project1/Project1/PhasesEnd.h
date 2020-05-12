#pragma once
#include "PhasesBase.h"
class PhasesEnd :
	public PhasesBase
{
public:
	PhasesEnd(std::string image_name);
	~PhasesEnd();
	bool Init();
	void Updata(std::vector<PhasesBase*> &ph_vec);
	void Draw(std::vector<PhasesBase*>& ph_vec);
private:
};

