#include "PhasesStanby.h"

PhasesStanby::PhasesStanby(std::string image_name) :PhasesBase(image_name)
{
	PhasesBase::image_name = image_name;
}

PhasesStanby::~PhasesStanby()
{
}

bool PhasesStanby::Init()
{
	return false;
}

void PhasesStanby::Updata(std::vector<PhasesBase*> &ph_vec)
{
}

void PhasesStanby::Draw(std::vector<PhasesBase*>& ph_vec)
{
}
