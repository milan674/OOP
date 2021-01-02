#pragma once
//Készítsen egy Konyv osztályt egy könyv adatainak tárolására : cím, szerzõ, kiadás éve.
//Az adatokat ne lehessen az osztályon kívülrõl módosítani, csak getter függvényekkel lekérdezni.
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