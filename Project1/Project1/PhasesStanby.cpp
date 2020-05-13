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

void PhasesStanby::Updata(std::vector<PhasesBase*> &ph_vec, PHASESTYPE& now_phases)
{
	VECTOR2 m_pos;
	GetMousePoint(&m_pos.x, &m_pos.y);
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		if (((m_pos.x >= 220 && m_pos.y >= 260 + 20) & (m_pos.x >= 220 && m_pos.y <= 260 + 60) & (m_pos.x <= 410 && m_pos.y >= 260 + 20) & (m_pos.x <= 410 && m_pos.y <= 260 + 60)) == 1)
		{
			now_phases = PHASES_ATTACK;
		}
	}
}

