#pragma once
#include "Konyv.h"
#include "Kotet.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* Készítsen egy Konyvtar osztályt, ami Konyv és Kotet objektumokat képes tárolni.
 Legyen képes elõre ismeretlen számú könyvet és sorozatot eltárolni.
 A Konyvtar osztálynak legyen egy add() függvénye, ami egy Konyv pointert vár, és beilleszti a listába.
 A Konyvtar destruktora szabadítsa fel a könyveknek és sorozatoknak lefoglalt memóriát.

 A Konyvtar-nak legyen egy print függvénye, mely kilistázza az összes könyvet, kötetet.
 A Konyv adatai a következõ formában jelenjenek meg: "[Szerzõ] - [Cím] ([Év])", 
 
 A Konyvtar-nak legyen egy db(string szerzo, string cim) függvénye, mely megadja,
 hogy egy adott szerzõtõl egy adott címû könyv/kötet hányszor van meg. (A kiadás éve irreleváns.)
 */

class Konyvtar
{
	std::vector<Konyv*> konyvek;
public:
	~Konyvtar() {
		for (auto& k : konyvek)
			delete k;
	}
	void add(Konyv* k) { konyvek.push_back(k); }
	void print() const {
		for (auto& k : konyvek)
			std::cout << k->toString() << std::endl;
	}

	/* Plusz pontokert */
	unsigned int db(std::string szerzo, std::string cim) const;
	const Konyv* operator[](unsigned int idx) const;
	void rendez();
	vector<const Konyv*> operator[](std::string sorozatnev) const;
};

