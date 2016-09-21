#include "stdafx.h"
#include "Tete.h"
#include <thread>


Tete::Tete()
{
}


Tete::~Tete()
{
}

void Tete::refine()
{
	std::this_thread::sleep_for(std::chrono::seconds(REFINING_TIME));
	this->isRefined = true;
	std::cout << *this << std::endl;
}

void Tete::print(ostream & stream) const
{
	stream << "Tete, refined ? " << this->isRefined;
}
