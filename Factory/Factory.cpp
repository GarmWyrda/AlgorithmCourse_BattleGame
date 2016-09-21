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
	
	auto start = std::chrono::system_clock::now();	//The simulation starts now
	std::thread(simulatingBoxOfPistonParts, &keepGoing, &newPistonPart, &newPartFromBox);

	std::thread t(&Machine<Tete>::refine, &MT);
	t.detach();
	std::thread j(&Machine<Jupe>::refine, &MJ);
	j.detach();
	std::thread a(&Machine<Axe>::refine, &MA);
	a.detach();
	std::thread p(&Machine<Piston>::assemble, &MP);
	p.detach();

	while (MP.getFileSortante().taille() < NB_PISTONS) {
		if (newPartFromBox) {
			newPartFromBox = false;
			Tete* partTete = dynamic_cast<Tete*>(newPistonPart);	//idée du dynamic_cast de Louis Gerard
			if (partTete == NULL) { //if the dynamic_cast is NULL then it's not a "Tete"
				Jupe* partJupe = dynamic_cast<Jupe*>(newPistonPart);
				if (partJupe == NULL) { //if the dynamic_cast is NULL then it's not a "Jupe"
					Axe* partAxe = dynamic_cast<Axe*>(newPistonPart);
					if (partAxe == NULL) { throw std::bad_cast(); }
					else { 
						MA.receivePartPiston(*partAxe);
					}
				}
				else {//The part is a skirt
					MJ.receivePartPiston(*partJupe);
				}
			}
			else { //The part is a Head
				MT.receivePartPiston(*partTete);
			}
			free(newPistonPart);
		}
	}

	//The simulation is complete, we have filled the Queue (File) with pistons
	keepGoing = false;
	MT.stoppingMachine();
	MJ.stoppingMachine();
	MA.stoppingMachine();
	MP.stoppingMachine();

	auto end = std::chrono::system_clock::now();	// The simulation ends now
	auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start);
	std::cout << "Simulation is over, it took : " << elapsed.count() << " seconds to complete, in order to build " << NB_PISTONS << " Pistons." << std::endl;
	system("pause");
}

