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

void PhasesAttack::Updata(std::vector<PhasesBase*> &ph_vec, PHASESTYPE& now_phases, DeckMng* card)
{
	VECTOR2 m_pos;
	GetMousePoint(&m_pos.x, &m_pos.y);
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		if (((m_pos.x >= 450 && m_pos.y >= 260 + 20) & (m_pos.x >= 450 && m_pos.y <= 260 + 60) & (m_pos.x <= 620 && m_pos.y >= 260 + 20) & (m_pos.x <= 620 && m_pos.y <= 260 + 60)) == 1)
		{
			now_phases = PHASES_END;
		}
	}
}

