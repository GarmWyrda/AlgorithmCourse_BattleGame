#pragma once
#include "PartPiston.h"
class Axe: public PartPiston
{
public:
	Axe();
	~Axe();
	void refine();
	void print(ostream&) const;

private:
	const float REFINING_TIME = 2.5;
};

