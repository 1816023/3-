#include "PhasesBase.h"
#include "PhasesMng.h"

PhasesMng::PhasesMng()
{
}

PhasesMng::~PhasesMng()
{
}

bool PhasesMng::Init()
{
	now_phases = PHASES_DRAW;
	ph_vec.resize(PHASES_MAX);
	return false;
}

void PhasesMng::updata()
{
}
