#pragma once
#include <vector>
#include <string>
class PhasesBase
{
public:
	PhasesBase(std::string image_name);
	~PhasesBase();
	virtual bool Init()=0;
	virtual void Updata(std::vector<PhasesBase*> &ph_vec)=0;
	virtual void Draw(std::vector<PhasesBase*> &ph_vec)=0;
private:
protected:
	std::string image_name;
};

