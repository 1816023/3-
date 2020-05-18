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
	triger_flag = false;
	return false;
}

void PhasesAttack::Updata(std::vector<PhasesBase*> &ph_vec, PHASESTYPE& now_phases, DeckMng* card, std::vector<objBase*> obj)
{
	//if (!triger_flag)
	//{
		for (auto itr : obj)
		{
			if (itr->GetObjType() == TYPE_PLAYER)
			{
				itr->attack(obj);
				triger_flag = true;
			}
		}
	//}
	now_phases = PHASES_END;
	/*VECTOR2 m_pos;
	GetMousePoint(&m_pos.x, &m_pos.y);
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		if (((m_pos.x >= 450*1.5 && m_pos.y >= 260 * 1.5 ) & (m_pos.x >= 450 * 1.5 && m_pos.y <= 260 * 1.5 + 60) & (m_pos.x <= 620 * 1.5 && m_pos.y >= 260 * 1.5 ) & (m_pos.x <= 620 * 1.5 && m_pos.y <= 260 * 1.5 + 60)) == 1)
		{
			now_phases = PHASES_END;
			triger_flag = false;
		}
	}*/
}

