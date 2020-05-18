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
	click_flag = false;
	return false;
}

void PhasesStanby::Updata(std::vector<PhasesBase*> &ph_vec, PHASESTYPE& now_phases, DeckMng* card, std::vector<objBase*> obj)
{
	for (auto itr : obj)
	{
		if (itr->GetObjctType() == TYPE_PLAYER)
		{
			itr->Standby(card);
		}
	}
	VECTOR2 m_pos;
	GetMousePoint(&m_pos.x, &m_pos.y);

	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		if (!click_flag)
		{
			click_flag = true;
			if (((m_pos.x >= 220 * 1.5 && m_pos.y >= 260 * 1.5) & (m_pos.x >= 220 * 1.5 && m_pos.y <= 260 * 1.5 + 60) & (m_pos.x <= 410 * 1.5 && m_pos.y >= 260 * 1.5) & (m_pos.x <= 410 * 1.5 && m_pos.y <= 260 * 1.5 + 60)) == 1)
			{
				now_phases = PHASES_ATTACK;
			}
		}
	}
	else {
		click_flag = false;
	}
}

