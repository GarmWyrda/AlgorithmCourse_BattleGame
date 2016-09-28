#include "stdafx.h"
#include "Jupe.h"
#include <thread>


Jupe::Jupe()
{
}


Jupe::~Jupe()
{
}

void Jupe::refine()
{
	std::this_thread::sleep_for(std::chrono::seconds(this->REFINING_TIME));
	this->isRefined = true;
	std::cout << *this << std::endl;
}

void Jupe::print(ostream & stream) const
{
	stream << "Jupe, refined ? " << this->isRefined;
}
