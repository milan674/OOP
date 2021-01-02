#pragma once
#include "Konyv.h"
#include "Kotet.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* K�sz�tsen egy Konyvtar oszt�lyt, ami Konyv �s Kotet objektumokat k�pes t�rolni.
 Legyen k�pes el�re ismeretlen sz�m� k�nyvet �s sorozatot elt�rolni.
 A Konyvtar oszt�lynak legyen egy add() f�ggv�nye, ami egy Konyv pointert v�r, �s beilleszti a list�ba.
 A Konyvtar destruktora szabad�tsa fel a k�nyveknek �s sorozatoknak lefoglalt mem�ri�t.

 A Konyvtar-nak legyen egy print f�ggv�nye, mely kilist�zza az �sszes k�nyvet, k�tetet.
 A Konyv adatai a k�vetkez� form�ban jelenjenek meg: "[Szerz�] - [C�m] ([�v])", 
 
 A Konyvtar-nak legyen egy db(string szerzo, string cim) f�ggv�nye, mely megadja,
 hogy egy adott szerz�t�l egy adott c�m� k�nyv/k�tet h�nyszor van meg. (A kiad�s �ve irrelev�ns.)
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

