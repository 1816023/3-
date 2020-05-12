#include "PhasesDraw.h"

PhasesDraw::PhasesDraw(std::string image_name) :PhasesBase(image_name)
{
	PhasesBase::image_name = image_name;
}

PhasesDraw::~PhasesDraw()
{
}

bool PhasesDraw::Init()
{
	return false;
}

void PhasesDraw::Updata(std::vector<PhasesBase*>& ph_vec)
{
}

void PhasesDraw::Draw(std::vector<PhasesBase*> &ph_vec)
{

}
