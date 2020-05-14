#pragma once
#include <vector>

enum PHASESTYPE {
	PHASES_DRAW,
	PHASES_STNBY,
	PHASES_ATTACK,
	PHASES_END,
	ENEMY_TURN,
	PHASES_MAX
};
class PhasesBase;
class DeckMng;
class PhasesMng
{
public:
	PhasesMng();
	~PhasesMng();
	bool Init();
	void updata();
	void Draw();
	void Dehtroy();
	PHASESTYPE GetNowPhases() { return now_phases; }
	void ChangePhases(PHASESTYPE phases);
private:
	PHASESTYPE now_phases;
	std::vector<PhasesBase*> ph_vec;
	DeckMng* card;

};

