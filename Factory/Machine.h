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
	File<T>& getFileSortante();
	void receivePartPiston(T);
	void refine();
	void startingMachine();
	void stoppingMachine();

private:
	File<T> fileEntrante;
	File<T> fileSortante;
	bool keepGoing = true;
};


template<typename T> Machine<T>::Machine() {

}

template<typename T> Machine<T>::~Machine() {

}

template<typename T> File<T>& Machine<T>::getFileSortante()
{
	return this->fileSortante;
}

template<typename T> void Machine<T>::receivePartPiston(T partPiston) {
	this->fileEntrante.enfiler(partPiston);
	std::cout << "test : new Piece " << typeid(partPiston).name() << "in queue" << std::endl;
}

template<typename T> void Machine<T>::refine() {
	while (this->keepGoing) {
		if (this->fileEntrante.estVide()) {
			std::this_thread::sleep_for(std::chrono::seconds(WAITING_FOR_NEW_PART));
		}
		else
		{
			T partPiston = this->fileEntrante.defiler();

			int isMachineBroken = rand() % 4;
			if (isMachineBroken == 0)
			{
				int repairTime = (rand() % 6 + 5);
				std::cout << "Attention ! Machine " << typeid(T).name() << " needs reparation. Estimated time before it is functional : " << repairTime << " seconds." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(repairTime )) ; // add "* 60" to make breaks last minutes and not seconds
				std::cout << "Machine " << typeid(T).name() << " is now functional." << std::endl;
			}
			
			partPiston.refine();
			this->fileSortante.enfiler(partPiston);
			std::cout << "test : new Refined Piece " << typeid(partPiston).name() << "in queue (machine non P)" << std::endl;
		}
	}
	
}

template<typename T> void Machine<T>::startingMachine() {
	std::thread t(&Machine<T>::refine, this);
	t.detach();
}

template<typename T> void Machine<T>::stoppingMachine() {
	this->keepGoing = false;
}

//-------------Specialized Template-----------//

template<>
class Machine<Piston>
{
public:
	Machine() {};
	~Machine() {};
	File<Piston>& getFileSortante() { return this->fileSortante; };
	void receivePartPiston(Tete partPiston) { this->fileEntrante[0].enfiler(partPiston); };
	void receivePartPiston(Jupe partPiston) { this->fileEntrante[1].enfiler(partPiston); };
	void receivePartPiston(Axe partPiston) { this->fileEntrante[2].enfiler(partPiston); };

	void assemble() {
		while (this->keepGoing) {
			if (this->fileEntrante[0].estVide() || this->fileEntrante[1].estVide() || this->fileEntrante[2].estVide()) {
				std::this_thread::sleep_for(std::chrono::seconds(WAITING_FOR_NEW_PART));
			}
			else
			{
				PartPiston partPiston1 = this->fileEntrante[0].defiler();
				PartPiston partPiston2 = this->fileEntrante[1].defiler();
				PartPiston partPiston3 = this->fileEntrante[2].defiler();

				int isMachineBroken = rand() % 4;
				if (isMachineBroken == 0)
				{
					int repairTime = (rand() % 6 + 5);
					std::cout << "Attention ! Machine Piston needs reparation. Estimated time before it is functional : " << repairTime << " minutes." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(repairTime * 60));
					std::cout << "Machine Piston is now functional." << std::endl;
				}

				Piston newPiston;
				this->fileSortante.enfiler(newPiston);
			}
		}
	};

	void startingMachine() {
		std::thread t(&Machine<Piston>::assemble, this);
		t.detach();
	};

	void stoppingMachine() { this->keepGoing = false; };

private:
	File<PartPiston> fileEntrante[3];
	File<Piston> fileSortante;
	bool keepGoing = true;
};