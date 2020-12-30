#pragma once
#include <string>
#include <iostream>
/*- A Tarstulajdonos osztaly:
// ... tarolja a tulajdonos nevet es tulajdoni hanyadat (egesz szam, tizezredek szama).
// ... van meg egy print() metodusa, ami nincs implementalva
// ... absztrakt osztaly, ezert nem peldanyosithato*/
class Tarstulajdonos
{
protected:
	std::string name;
	int hanyad;
public:
	virtual void print() = 0;
	Tarstulajdonos(std::string name, int hanyad) : name(name), hanyad(hanyad) {}
	std::string getName() const{ return name; }
	int getHanyad() const  { return hanyad; }
};

