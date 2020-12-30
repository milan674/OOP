#pragma once
#include "Tarstulajdonos.h"
class PereskedoTulajdonos :public Tarstulajdonos
{
public:
	PereskedoTulajdonos(std::string name, int hanyad) : Tarstulajdonos(name, hanyad) {};
	void print() override;
};

