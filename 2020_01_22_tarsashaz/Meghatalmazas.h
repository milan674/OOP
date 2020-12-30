#pragma once
#include "lakokozosseg.h"
class Meghatalmazas
{
	Tarstulajdonos* meghatalmazo;
	Tarstulajdonos* meghatalmazott;

public:
	Meghatalmazas(Tarstulajdonos* t1, Tarstulajdonos* t2) : meghatalmazo(t1), meghatalmazott(t2) {} 
	Tarstulajdonos* getMeghatalmazo() const { return meghatalmazo; }
	Tarstulajdonos* getMeghatalmazott() const { return meghatalmazott; }

};

