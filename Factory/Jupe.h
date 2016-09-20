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
	const float REFINING_TIME = 3;
};

