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
	const float REFINING_TIME = 2;
};
