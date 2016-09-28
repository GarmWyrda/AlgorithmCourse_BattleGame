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
	const int REFINING_TIME = 2;	//seconds originally 150sec
};

