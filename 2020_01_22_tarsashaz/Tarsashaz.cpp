#include "Tarsashaz.h"

void Tarsashaz::addTulajdonos(Tarstulajdonos* tt)
{
	tulajok.push_back(tt);
}

void Tarsashaz::holdKozgyules(Kozgyules* kgy)
{
	int bekes = 0;
	int bekesmax =3;
	int peresmax = 2;
	int peres = 0;
	for (Tarstulajdonos* t : tulajok) {
		if (BekesTulajdonos * btp = dynamic_cast<BekesTulajdonos*>(t)) {
			bekes++;
			if (bekes == bekesmax) {
				kgy->addJelenlevo(t);
				bekes = 0; 
			}
		}
		if (PereskedoTulajdonos * ptp=dynamic_cast<PereskedoTulajdonos*>(t) ) {
			peres++;
			if (peres == peresmax) { 
				kgy->addJelenlevo(t);
				peres = 0; 
			}
		}
	}
}

