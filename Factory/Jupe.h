#pragma once
#include "PartPiston.h"

class Jupe: public PartPiston
{
public:
	Jupe();
	~Jupe();
	void refine();
	void print(ostream&) const;

private:
	const int REFINING_TIME = 3;	//seconds originally 180sec
};

