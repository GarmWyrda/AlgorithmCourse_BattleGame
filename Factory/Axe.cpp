#include "stdafx.h"
#include "Axe.h"
#include <thread>


Axe::Axe()
{
}


Axe::~Axe()
{
}

void Axe::refine()
{
	std::this_thread::sleep_for(std::chrono::seconds(this->REFINING_TIME));
	this->isRefined = true;
	std::cout << *this << std::endl;
}

void Axe::print(ostream & stream) const
{
	stream << "Axe, refined ? " << this->isRefined;
}
