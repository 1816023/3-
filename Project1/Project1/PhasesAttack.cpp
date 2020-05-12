#include "PhasesAttack.h"

PhasesAttack::PhasesAttack(std::string image_name):PhasesBase(image_name)
{
	PhasesBase::image_name = image_name;
}

PhasesAttack::~PhasesAttack()
{
}

bool PhasesAttack::Init()
{
	return false;
}

void PhasesAttack::Updata(std::vector<PhasesBase*> &ph_vec)
{
}

void PhasesAttack::Draw(std::vector<PhasesBase*>& ph_vec)
{
}
