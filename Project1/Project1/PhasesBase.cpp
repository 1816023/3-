#include "PhasesBase.h"

PhasesBase::PhasesBase(std::string image_name)
{
	PhasesBase::image_name = image_name;
}

PhasesBase::~PhasesBase()
{
}

void PhasesBase::Draw(std::vector<PhasesBase*>& ph_vec, PHASESTYPE& now_phases)
{
	DrawGraph(0, 320 - 60, IMAGE_ID(image_name)[0], true);

}

