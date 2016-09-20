#pragma once

template<typename T>
class Machine
{
private:
	File<T> fileEntrante[1];
	File<T> fileSortante[1];
public:
	Machine() {};
	~Machine() {};
};
