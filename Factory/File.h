#pragma once
#include <list>
using std::list;

template<typename T>
class File
{
public: // constructeurs et destructeurs:
	File();
	File(const File &);
	~File();
	// modificateurs
	void enfiler(const T&);
	T defiler();
	// sélecteurs 
	int taille() const;
	bool estVide() const;
	bool estPleine() const;
	const T& premier() const; // tête de la file
	const T& dernier() const; // queue de la file // surcharges d'opérateurs
	const File<T>& operator = (const File<T>&) throw (bad_alloc); 
	template <typename U> friend std::ostream& operator <<
		(std::ostream& f, const File<U>& q);

private: // ...Modèle d'implantation
	const static int DEFAULT_SIZE = 100;
	list<T> array;
	int max_size;
};

template<typename T> File<T>::File() {
	this->array = list<T>();
	this->max_size = DEFAULT_SIZE;
}

template<typename T> File<T>::File(const File& file) {
	this->array = file.array;
	this->max_size = file.max_size;
}

template<typename T> File<T>::~File() {

}

template<typename T> void File<T>::enfiler(const T& element) throw (std::length_error) {
	if (this->estPleine()) {
		throw std::length_error("Queue is full");
	}
	this->array.push_back(element);
}

template<typename T> T File<T>::defiler() throw (std::length_error) {
	if (this->estVide()) {
		throw std::length_error("Queue is empty");
	}
	T element = this->array.front();
	this->array.pop_front();
	return element;
}

template<typename T> int File<T>::taille() const {
	return this->array.size();
}

template<typename T> bool File<T>::estVide() const{
	return this->array.empty();
}

template<typename T> bool File<T>::estPleine() const {
	return this->array.size >= this->max_size;
}

template<typename T> const T& File::premier() const {
	return this->array.front();
}

template<typename T> const T& File::dernier() const {
	return this->array.back();
}

template<typename T> const File<T>& File::operator=(const File<T>& file) {
	this->array = file.array;
	return *this;
}

template<typename U> std::ostream & operator<<(std::ostream & stream, const File<U>& file)
{
	for (int i = file.size(); i > 0; i--) {
		stream << file.array[i];
	}
	return stream;
}