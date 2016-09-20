#pragma once
#include <string>
#include <iostream>
using std::string;
using std::ostream;

class PartPiston
{
public:
	bool isRefined = false;
	PartPiston();
	virtual ~PartPiston();
	virtual void refine();
	virtual void print(ostream&) const;
	friend std::ostream& operator<< (ostream&, const PartPiston&);
};

