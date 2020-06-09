#include "PhasesBase.h"
int PhasesBase::turn = 0;
PhasesBase::PhasesBase(std::string image_name)
{
	PhasesBase::image_name = image_name;
	click_flag = false;
}

PhasesBase::~PhasesBase()
{
}

void PhasesBase::Draw(std::vector<PhasesBase*>& ph_vec, PHASESTYPE& now_phases, DeckMng* card)
{
	DrawFormatString(0, 0, 0xffffff, "%d\n", turn);
	DrawRotaGraph(1230/2,960/2-60,1.5f,0, IMAGE_ID(image_name)[0], true);

}

