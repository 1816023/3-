#pragma once
#include <vector>
#include <string>
#include <DxLib.h>
#include "ImageMng.h"
#include "PhasesMng.h"

class PhasesBase
{
public:
	PhasesBase(std::string image_name);
	~PhasesBase();
	virtual bool Init()=0;
	virtual void Updata(std::vector<PhasesBase*> &ph_vec, PHASESTYPE& now_phases)=0;
	virtual void Draw(std::vector<PhasesBase*> &ph_vec, PHASESTYPE& now_phases);
private:
protected:
	std::string image_name;
};

