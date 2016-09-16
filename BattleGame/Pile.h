#pragma once
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

template <typename T>
class Pile
{
public:
	// constructeurs et destructeurs
	Pile(int max = MAX_PILE) throw(bad_alloc); //constructeur
	Pile(const Pile&); //constructeur copie
	~Pile(); //destructeur
			 // Modificateurs
	void empiler(const T&);
	T depiler();
	//Sélecteurs
	bool estVide()const;
	int taille() const;
	constT& sommet() const; // consulte l’élément au sommet
							//surcharge d'opérateurs
	const Pile<T>& operator = (const Pile<T);
	template <typename U> friend std::ostream& operator<<
		(std::ostream&, const Pile<U>&);

private: //Modèle d’implantation
	vector<T>* array;
	int top, maxSize;
	static const int MAX_PILE = 100;
};



template<typename T> Pile<T>::Pile(int max) throw(bad_alloc)
{
	vector<T> array(max);
	top = -1;
	maxSize = max;
}

template<typename T> Pile<T>::Pile(const Pile &)
{
	top = Pile.top;
	maxSize = Pile.maxSize;
	this->array = Pile.array;
}

template<typename T> Pile<T>::~Pile()
{
}

template<typename T> void Pile<T>::empiler(const T& newItem) throw (std::length_error){
	if (top + 1 < maxSize) {
		array.insert(top, newItem);
		top += 1;
	}
	else {
		throw length_error("the stack is full");
	}
}

template<typename T> T Pile<T>::depiler() throw (std::logic_error) {
	if (!estVide()) {
		T element = this->array.back();
		this->array.pop_back();
		top -= 1;
	}
	else {
		throw logic_error("Stack is empty");
	}
}