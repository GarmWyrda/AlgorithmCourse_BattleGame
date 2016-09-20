#include "stdafx.h"
#include "Jupe.h"


Jupe::Jupe()
{
}


Jupe::~Jupe()
{
}

void Jupe::refine()
{
}

void Jupe::print(ostream & stream) const
{
	stream << "is this part Refined ? (jupe) : " << this->isRefined;
}
