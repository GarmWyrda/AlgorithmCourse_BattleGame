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
	stream << "Axe, refined ? : " << this->isRefined;
}
