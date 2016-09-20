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
	stream << "Jupe, refined ? : " << this->isRefined;
}
