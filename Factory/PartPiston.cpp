#include "stdafx.h"
#include "PartPiston.h"


PartPiston::PartPiston()
{
}


PartPiston::~PartPiston()
{
}

void PartPiston::refine()
{
	this->isRefined = true;
}

void PartPiston::print(ostream & stream) const
{
	stream << "is this part refined ? : " << this->isRefined;
}

std::ostream & operator<<(ostream& stream, const PartPiston &partPiston)
{
	partPiston.print(stream);
	return stream;
}
