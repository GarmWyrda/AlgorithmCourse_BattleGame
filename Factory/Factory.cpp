// Factory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <string>
#include <time.h>
#include "PartPiston.h"
#include "Tete.h"
#include "Jupe.h"
#include "Axe.h"
#include "Machine.h"
#include "File.h"

#define NB_PISTONS 3
#define RANDOM_PARTS_SPAWNING_RATE 5

void simulatingBoxOfPistonParts(bool* keepGoing, PartPiston** newPistonPart, bool* newPartFromBox) {
	while (*keepGoing) {

		//std::cout << "test" << std::endl;
		int newPartOfPiston = rand() % 3 + 1;
		//std::cout << newPartOfPiston << std::endl;
		/*switch (newPartOfPiston) {
		case 1:
			*newPistonPart = new Tete();

			std::cout << "testTete" << std::endl;
			break;

		case 2:
			*newPistonPart = new Jupe();
			std::cout << "testJupe" << std::endl;
			break;

		case 3:
			*newPistonPart = new Axe();
			std::cout << "testAxe" << std::endl;
			break;

		default:
			throw std::logic_error("random is not working ?");
			break;
		}*/
		if (newPartOfPiston == 1) {
			*newPistonPart = new Tete();
		}
		else if (newPartOfPiston == 2) {
			*newPistonPart = new Jupe();
		}
		else {
			*newPistonPart = new Axe();
		}
		*newPartFromBox = true;

		//std::cout << "testFin" << std::endl;
		std::cout << "The next Part is : " << **newPistonPart << std::endl;
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
	PartPiston* newPart = NULL;
	bool newPartFromBox = false;
	
	auto start = std::chrono::system_clock::now();	//The simulation starts now

/*
	std::thread t(&Machine<Tete>::refine, &MT);
	t.detach();
	std::thread j(&Machine<Jupe>::refine, &MJ);
	j.detach();
	std::thread a(&Machine<Axe>::refine, &MA);
	a.detach();
	std::thread p(&Machine<Piston>::assemble, &MP);
	p.detach();
*/
	std::cout << "starting Machines" << std::endl;
	MT.startingMachine();
	MJ.startingMachine();
	MA.startingMachine();
	MP.startingMachine();
	std::cout << "Machines started" << std::endl;

	std::thread simulationBox(simulatingBoxOfPistonParts, &keepGoing, &newPart, &newPartFromBox);

	while (MP.getFileSortante().taille() < NB_PISTONS) {
		if (newPartFromBox) {
			newPartFromBox = false;
			Tete* partTete = dynamic_cast<Tete*>(newPart);	//idée du dynamic_cast de Louis Gerard
			if (partTete == NULL) { //if the dynamic_cast is NULL then it's not a "Tete"
				Jupe* partJupe = dynamic_cast<Jupe*>(newPart);
				if (partJupe == NULL) { //if the dynamic_cast is NULL then it's not a "Jupe"
					Axe* partAxe = dynamic_cast<Axe*>(newPart);
					if (partAxe == NULL) { throw std::bad_cast(); }
					else { 
						//std::cout << "test Axe received" << std::endl;
						MA.receivePartPiston(*partAxe);
					}
				}
				else {//The part is a skirt
					//std::cout << "test Jupe received" << std::endl;
					MJ.receivePartPiston(*partJupe);
				}
			}
			else { //The part is a Head
				MT.receivePartPiston(*partTete);
			}
			//std::cout << "freeNewPistonpart" << std::endl;
			//free(newPart);
			if (MA.getFileSortante().taille() > 0) {
				MP.receivePartPiston(MA.getFileSortante().defiler());
			}
			if (MJ.getFileSortante().taille() > 0) {
				MP.receivePartPiston(MJ.getFileSortante().defiler());
			}
			if (MT.getFileSortante().taille() > 0) {
				MP.receivePartPiston(MT.getFileSortante().defiler());
			}
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

