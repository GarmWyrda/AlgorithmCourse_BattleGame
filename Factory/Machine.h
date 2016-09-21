#pragma once
#include "File.h"
#include "PartPiston.h"
#include "Piston.h"
#include "Axe.h"
#include "Jupe.h"
#include "Tete.h"
#include <thread>

#define WAITING_FOR_NEW_PART 1

template<typename T>
class Machine
{
public:
	Machine();
	~Machine();
	void receivePartPiston(T);
	void refine();
	void stoppingMachine();

private:
	File<T> fileEntrante;
	File<T> fileSortante;
	bool keepGoing = true;
};

template<>
class Machine<Piston> 
{
public:
	Machine();
	~Machine();
	File<Piston>& getFileSortante();
	void receivePartPiston(Tete);
	void receivePartPiston(Jupe);
	void receivePartPiston(Axe);
	void assemble();
	void stoppingMachine();

private:
	File<PartPiston> fileEntrante[3];
	File<Piston> fileSortante;
	bool keepGoing = true;
};

template<typename T> Machine::Machine() {

}

template<typename T> Machine::~Machine() {

}

template<Piston> File<Piston> Machine::getFileSortante() {
	return this->fileSortante;
}

template<typename T> void Machine::receivePartPiston(T partPiston) {
	this->fileEntrante.enfiler(partPiston);
}


template<typename T> void Machine::refine() {
	while (this->keepGoing) {
		if (this->fileEntrante.estVide()) {
			std::this_thread::sleep_for(std::chrono::seconds(WAITING_FOR_NEW_PART));
		}
		else
		{
			T partPiston = this->fileEntrante.depiler();

			int isMachineBroken = rand() % 4;
			if (isMachineBroken == 0)
			{
				int repairTime = (rand() % 6 + 5);
				std::cout << "Attention ! Machine " << typeid(T).name() << " needs reparation. Estimated time before it is functional : " << repairTime << " minutes." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(repairTime * 60 * ;
				std::cout << "Machine " << typeid(T).name() << " is now functional." << std::endl;
			}
			
			partPiston.refine();
			this->fileSortante.enfiler(partPiston);
		}
	}
	
}

template<typename T> void Machine::stoppingMachine() {
	this->keepGoing = false;
}

template<Piston> Machine::Machine() {

}

template<Piston> Machine::~Machine() {

}

template<Piston> void Machine::receivePartPiston(Tete partPiston) {
	this->fileEntrante[0].enfiler(partPiston); 
}

template<Piston> void Machine::receivePartPiston(Jupe partPiston) {
	this->fileEntrante[1].enfiler(partPiston);
}

template<Piston> void Machine::receivePartPiston(Axe partPiston) {
	this->fileEntrante[2].enfiler(partPiston);
}

template<Piston> void Machine::assemble() {
	while (this->keepGoing) {
		if (this->fileEntrante[0].estVide() || this->fileEntrante[1].estVide() || this->fileEntrante[2].estVide()) {
			std::this_thread::sleep_for(std::chrono::seconds(WAITING_FOR_NEW_PART));
		}
		else
		{
			T partPiston1 = this->fileEntrante[0].depiler();
			T partPiston2 = this->fileEntrante[1].depiler();
			T partPiston3 = this->fileEntrante[2].depiler();

			int isMachineBroken = rand() % 4;
			if (isMachineBroken == 0)
			{
				int repairTime = (rand() % 6 + 5);
				std::cout << "Attention ! Machine Piston needs reparation. Estimated time before it is functional : " << repairTime << " minutes." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(repairTime * 60 * ;
				std::cout << "Machine Piston is now functional." << std::endl;
			}

			Piston newPiston;
			this->fileSortante.enfiler(newPiston);
		}
	}
}

template<Piston> void Machine::stoppingMachine() {
	this->keepGoing = false;
}