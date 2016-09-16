#pragma once
#include <iostream>
using namespace std;

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
	constT& sommet() const; // consulte l’élément au sommet
							//surcharge d'opérateurs
	const Pile<T>& operator = (const Pile<T);
	template <typename U> friend std::ostream& operator<<
		(std::ostream&, const Pile<U>&);

private: … //Modèle d’implantation
};