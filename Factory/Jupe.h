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
	const int REFINING_TIME = 180;	//seconds
};

