// Factory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include "PartPiston.h"
#include "Tete.h"
#include "Jupe.h"
#include "Axe.h"
#include "Machine.h"
#include "File.h"

#define NB_PISTONS 100
#define RANDOM_PARTS_SPAWNING_RATE 3

void simulatingBoxOfPistonParts(bool* keepGoing, PartPiston** newPistonPart, bool* newPartFromBox) {
	while (*keepGoing) {
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
			break;
		}
		*newPartFromBox = true;
		std::cout << "The next Part is a : " << **newPistonPart << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(RANDOM_PARTS_SPAWNING_RATE));

	}
}
int main()
{
	srand(time(NULL)); // initializes random seed
    
	Machine<Tete> MT;
	Machine<Jupe> MJ;
	Machine<Axe> MA;
	Machine<Piston> MP;

	bool keepGoing = true;
	PartPiston* newPistonPart = NULL;
	bool newPartFromBox = false;
	
	std::thread(simulatingBoxOfPistonParts, &keepGoing, &newPistonPart, &newPartFromBox);

	std::thread t(MT.refine);
	t.detach();
	std::thread j(MJ.refine);
	j.detach();
	std::thread a(MA.refine);
	a.detach();
	std::thread p(MP.assemble);
	p.detach();

	while (MP.getFileSortante.taille() < NB_PISTONS) {
		if (newPartFromBox) {
			newPartFromBox = false;
			if (typeid(newPartFromBox).name == "Tete") {
				MT.receivePartPiston(newPistonPart);
			}
			if (typeid(newPartFromBox).name == "Jupe") {

			}
		}
	}
}

