// Factory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "PartPiston.h"
#include "Tete.h"
#include "Jupe.h"
#include "Axe.h"
#include "Machine.h"
#include "File.h"


void simulatingBoxOfPistonParts(PartPiston** newPistonPart) {
	while (true) {
		int newPartOfPiston = rand() % 3 + 1;
		switch (newPartOfPiston) {
		case 1:
			*newPistonPart = new Tete();
			break;

		case 2:
			*newPistonPart = new Jupe();
			break;

		case 3:
			*newPistonPart = new Axe();

		default:
			throw std::logic_error("random is not working ?");

		}
		std::cout << "The next Part is a : " << **newPistonPart << std::endl;


	}
}
int main()
{
    return 0;
}

