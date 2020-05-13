#include "PhasesBase.h"
#include "PhasesAttack.h"
#include "PhasesDraw.h"
#include "PhasesEnd.h"
#include "PhasesStanby.h"
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
	ph_vec[PHASES_DRAW] = new PhasesDraw("data/texture/DrawImage.png");
	ph_vec[PHASES_STNBY] = new PhasesStanby("data/texture/StandbyImage.png");
	ph_vec[PHASES_ATTACK] = new PhasesAttack("data/texture/AttackImage.png");
	ph_vec[PHASES_END] = new PhasesEnd("data/texture/EndImage.png");

	return false;
}

void PhasesMng::updata()
{
	if (now_phases != ENEMY_TURN)
	{
		ph_vec[now_phases]->Updata(ph_vec,now_phases);
	}
	
}

void PhasesMng::Draw()
{
	if (now_phases != ENEMY_TURN)
	{
		ph_vec[now_phases]->Draw(ph_vec,now_phases);
	}
}

void PhasesMng::Dehtroy()
{
	for (auto phases : ph_vec)
	{
		delete(phases);
	}
}

void PhasesMng::ChangePhases(PHASESTYPE phases)
{
	now_phases = phases;
}
