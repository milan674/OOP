#pragma once
//K�sz�tsen egy Konyv oszt�lyt egy k�nyv adatainak t�rol�s�ra : c�m, szerz�, kiad�s �ve.
//Az adatokat ne lehessen az oszt�lyon k�v�lr�l m�dos�tani, csak getter f�ggv�nyekkel lek�rdezni.
#include <string>
using namespace std;
#include <iostream>
class Konyv
{
protected:
	std::string szerzo;
	std::string cim;
	int ev;
public:
	Konyv(std::string szerzo, std::string cim, int ev)
		:szerzo(szerzo), cim(cim), ev(ev) {}
	virtual ~Konyv() {}
	std::string getSzerzo() const { return szerzo; }
	std::string getCim() const { return cim; }
	int getEv() const { return ev; }
	virtual std::string toString() const { return szerzo + " - " + cim + " (" + std::to_string(ev) + ")"; }
	friend ostream& operator << (ostream& s, const Konyv& k);
	bool operator<(const Konyv& other) const;
};

ostream& operator << (ostream& s, const Konyv& k);