#include "PhasesEnd.h"

PhasesEnd::PhasesEnd(std::string image_name) :PhasesBase(image_name)
{
	PhasesBase::image_name = image_name;
}

PhasesEnd::~PhasesEnd()
{
}

bool PhasesEnd::Init()
{
	return false;
}

void PhasesEnd::Updata(std::vector<PhasesBase*>& ph_vec)
{
}

void PhasesEnd::Draw(std::vector<PhasesBase*> &ph_vec)
{
}
