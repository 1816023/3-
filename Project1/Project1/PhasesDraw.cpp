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
	drawF = false;
	click_flag = true;
	change_phases_F = false;
	return false;
}

void PhasesDraw::Updata(std::vector<PhasesBase*>& ph_vec, PHASESTYPE& now_phases, DeckMng* card, std::vector<objBase*> obj)
{

	//card->Draw();
	//
	//for (auto itr : obj)
	//{
	//	if (itr->GetObjType() == TYPE_PLAYER)
	//	{
	//		itr->Reset();
	//	}
	//}
	//turn++;
	//now_phases = PHASES_STNBY;
	for (auto itr : obj)
	{
		if (itr->GetObjType() == TYPE_PLAYER)
		{
			itr->Reset();
		}
	}
	VECTOR2 m_pos;
	GetMousePoint(&m_pos.x, &m_pos.y);
	if ((GetMouseInput() & MOUSE_INPUT_LEFT)!=0)
	{
		if (!click_flag)
		{
			click_flag = true;

			if (((m_pos.x >= 10 * 1.5 && m_pos.y >= 260 * 1.5) & (m_pos.x >= 10 * 1.5 && m_pos.y <= 260 * 1.5 + 60) & (m_pos.x <= 180 * 1.5 && m_pos.y >= 260 * 1.5) & (m_pos.x <= 180 * 1.5 && m_pos.y <= 260 * 1.5 + 60)) == 1)
			{
				card->Draw();
				PlaySound("data/sound/SE/draw.wav", DX_PLAYTYPE_BACK);
				PlaySound("data/sound/SE/draw.wav", DX_PLAYTYPE_BACK);
				PlaySound("data/sound/SE/draw.wav", DX_PLAYTYPE_BACK);
				PlaySound("data/sound/SE/draw.wav", DX_PLAYTYPE_BACK);
				PlaySound("data/sound/SE/draw.wav", DX_PLAYTYPE_BACK);

				/*for (auto itr : obj)
				{
					if (itr->GetObjType() == TYPE_PLAYER)
					{
						itr->Reset();
					}
				}*/

				turn++;
				drawF = true;
				
			}
		}
	}
	else {
		click_flag = false;
	}
	if (drawF)
	{
		if (!lpSoundMng.CheckSound("data/sound/SE/draw.wav"))
		{
			now_phases = PHASES_STNBY;
			drawF = false;
		}
		
	}
}


