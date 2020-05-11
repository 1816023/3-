#pragma once
#include <vector>
enum PHASESTYPE {
	PHASES_DRAW,
	PHASES_STNBY,
	PHASES_ATTCK,
	PHASES_END,
	PHASES_MAX
};

class PhasesMng
{
public:
	PhasesMng();
	~PhasesMng();
	bool Init();
	void updata();

private:
	PHASESTYPE now_phases;
	std::vector<PhasesBase*> ph_vec;
};

