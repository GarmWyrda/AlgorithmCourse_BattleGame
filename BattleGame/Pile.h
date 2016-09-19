#pragma once
#include <iostream>
#include <vector>
using std::vector;

template <typename T>
class Pile
{
public:
	// constructeurs et destructeurs
	Pile(int max = MAX_PILE); //constructeur
	Pile(const Pile&); //constructeur copie
	~Pile(); //destructeur

	// Modificateurs
	void empiler(const T&);
	T depiler();

	//Sélecteurs
	bool estVide()const;
	int taille() const;
	const T& sommet() const; // consulte l’élément au sommet

	//surcharge d'opérateurs
	const Pile<T>& operator = (const Pile<T>);
	template <typename U> friend std::ostream& operator<<(std::ostream&, const Pile<U>);

private: //Modèle d’implantation
	vector<T> array;
	const static int MAX_PILE = 1000;
};



template<typename T> Pile<T>::Pile(int max)
{
	if (max <1 || max > MAX_PILE) {
		throw std::invalid_argument("Stack size incorrect");
	}
	this->array = vector<T>();
	this->array.reserve(max);
	
}

template<typename T> Pile<T>::Pile(const Pile & pile)
{
	this->array = pile.array;
}

template<typename T> Pile<T>::~Pile()
{
}

template<typename T> void Pile<T>::empiler(const T& newItem) throw (std::length_error){
	if (this->array.size() >= MAX_PILE) {
		throw std::length_error("the stack is full");
	}
	this->array.push_back(newItem);
}

template<typename T> T Pile<T>::depiler() throw (std::logic_error) {
	if (this->array.empty()) {
		throw std::logic_error("Stack is empty");
	}
		T element = this->array.back();
		this->array.pop_back();
		return element;
}

template<typename T> bool Pile<T>::estVide() const {
	return this->array.empty();
}

template<typename T> int Pile<T>::taille() const {
	return this->array.size();
}

template<typename T> const T& Pile<T>::sommet() const throw (std::length_error) {
	if (this->array.empty()) {
		throw std::length_error("Stack is empty");
	}
	return this->array.back();
}

template<typename T> const Pile<T>& Pile<T>::operator=(const Pile<T> newPile) {
	this->array = newPile.array;
	return *this;
}

template<typename U> std::ostream & operator<<(std::ostream & stream, const Pile<U> pile) {
	for (int i = pile.taille() - 1; i >= 0; i--) {
		stream << pile.array[i];
	}
	return stream;
}