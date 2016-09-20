#include "stdafx.h"
#include "Tete.h"


Tete::Tete()
{
}


Tete::~Tete()
{
}

void Tete::refine()
{
}

void Tete::print(ostream & stream) const
{
	stream << "is this part Refined ? (tete) : " << this->isRefined;
}
