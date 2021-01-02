#pragma once
#include "Konyv.h"

/*K�sz�tsen egy Kotet oszt�lyt, ami a Konyv oszt�lyb�l sz�rmazik, �s hozz�f�r annak adattagjaihoz,
valamint k�t tov�bbi adattagja van : sorozat neve, �s k�tetsz�m.
A Konyv �s Kotet oszt�lyoknak ne legyen param�ter n�lk�li konstruktora,
csak az �sszes adattag inicializ�l�s�val lehessen �ket l�trehozni.*/

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

