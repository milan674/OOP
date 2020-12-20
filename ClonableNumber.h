#pragma once
#include "Clonable.h"
class ClonableNumber :public Clonable
{
	double d;
public:
	ClonableNumber(double d) : d(d) {}
	double getNumber() const { return d; }
	Clonable* clone() const override;
};

