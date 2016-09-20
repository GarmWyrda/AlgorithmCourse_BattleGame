#pragma once
#include "File.h"
#include "PartPiston.h"
#include "Piston.h"
#include "Axe.h"
#include "Jupe.h"
#include "Tete.h"

template<typename T>
class Machine
{
public:
	Machine();
	~Machine();
	void receivePartPiston(T);
	void refine();	//TODO

private:
	File<T> fileEntrante;
	File<T> fileSortante;
};

template<>
class Machine<Piston> 
{
public:
	Machine();
	~Machine();
	void receivePartPiston(Tete);
	void receivePartPiston(Jupe);
	void receivePartPiston(Axe);
	void assemble(); //TODO

private:
	File<PartPiston> fileEntrante[3];
	File<Piston> fileSortante;
};

template<typename T> Machine::Machine() {

}

template<typename T> Machine::~Machine() {

}

template<typename T> void Machine::receivePartPiston(T partPiston) {
	this->fileEntrante.enfiler(partPiston);
}

/*
template<typename T> void Machine::refine() {	//TODO
	
}
*/

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

/*
template<Piston> void Machine::assemble() {	//TODO

}
*/