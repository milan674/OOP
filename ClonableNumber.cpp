#include "ClonableNumber.h"

Clonable* ClonableNumber::clone() const
{
	Clonable* c = new ClonableNumber(d);
	return c;
}
