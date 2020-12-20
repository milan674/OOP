#include "ClonableString.h"

Clonable* ClonableString::clone() const 
{
	Clonable* c = new ClonableString(s);
	return c; 
}
