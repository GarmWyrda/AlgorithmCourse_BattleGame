#pragma once
#include "PartPiston.h"

class Tete : public PartPiston
{
public:
	Tete();
	~Tete();
	void refine();
	void print(ostream&) const;

private:
	const int REFINING_TIME = 120;	//seconds
};
