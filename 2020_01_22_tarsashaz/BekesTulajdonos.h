#pragma once
#include "Tarstulajdonos.h"

class BekesTulajdonos : public Tarstulajdonos
{
public:
	BekesTulajdonos(std::string name, int hanyad) : Tarstulajdonos(name, hanyad) {};
	void print();
};

