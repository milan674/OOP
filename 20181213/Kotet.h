#pragma once
#include "Konyv.h"

/*Készítsen egy Kotet osztályt, ami a Konyv osztályból származik, és hozzáfér annak adattagjaihoz,
valamint két további adattagja van : sorozat neve, és kötetszám.
A Konyv és Kotet osztályoknak ne legyen paraméter nélküli konstruktora,
csak az összes adattag inicializálásával lehessen õket létrehozni.*/

class Kotet :public Konyv
{
	std::string sorozatnev;
	int kotetszam;
public:
	Kotet(std::string szerzo, std::string cim, int ev, std::string sorozatnev, int kotetszam) :
		Konyv(szerzo, cim, ev), sorozatnev(sorozatnev), kotetszam(kotetszam) {}
	std::string getSorozatnev() const { return sorozatnev; }
	int getKotetszam() const { return kotetszam; }
	virtual std::string toString() const override { return sorozatnev + "/" + std::to_string(kotetszam) + ": " + Konyv::toString(); }
};

