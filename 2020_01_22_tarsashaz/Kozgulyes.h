#pragma once
#include <vector>
#include "Tarstulajdonos.h"
#include <numeric>



class SumJelenlevos { //eredeti megoldashoz kell 
public:
	int operator()(int acc, Tarstulajdonos* tp) {
		return acc + tp->getHanyad();
	}
};

class Kozgyules
{
	int year;
	int month;
	int day;
	std::vector <Tarstulajdonos*> jelenlevok;
	//std::vector < Meghatalmazas* > meghatalmazasok;

	
public:
	Kozgyules(int year, int month, int day) : year(year), month(month), day(day) {};
	int getYear() { return year; }
	int getDay() { return day; }
	int getMonth() { return month; }
	void addJelenlevo(Tarstulajdonos* tt) { jelenlevok.push_back(tt); }
	void printJelenlevok();
	void printLetszam();
	void printLetszam2();


};

// - A Kozgyules osztaly:
// ... 2-es szinthez eltarolja int-ekkent a kozgyules evszamat, honapjat es napjat
// ... 2-es szinthez eltarolja STL kontenerben a kozgyules resztvevoinek pointereit
// ... 2-es szinthez megvalositja az addJelenlevo() metodust
// ... 2-es szinthez megvalositja a printJelenlevok() metodust, amely az osszes jelenlevore meghivja sajat print() metodusat