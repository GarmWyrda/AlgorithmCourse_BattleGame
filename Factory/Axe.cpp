#include "stdafx.h"
#include "Axe.h"


Axe::Axe()
{
}


Axe::~Axe()
{
}

void Axe::refine()
{
}

void Axe::print(ostream & stream) const
{
	stream << "is this part Refined ? (axe) : " << this->isRefined;
}
