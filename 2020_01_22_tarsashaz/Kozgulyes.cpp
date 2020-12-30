#include "Kozgulyes.h"

void Kozgyules::printJelenlevok()
{
	for (auto a : jelenlevok) {
		a->print();
	}
}

void Kozgyules::printLetszam()
{
	int total = 0;
	for (auto a : jelenlevok) {
		
		total += a->getHanyad();
	}
	std::cout << "Letszam: " << total << std::endl;
}

void Kozgyules::printLetszam2()
{ //eredeti megoldas accumulatetal
	int total = std::accumulate(jelenlevok.begin(), jelenlevok.end(), 0, SumJelenlevos());
	std::cout << "Letszam: " << total << std::endl;
}


/*
void Kozgyules::submitMeghatalmazas(Meghatalmazas* megh)
{
	meghatalmazasok.push_back(megh);
}

void Kozgyules::printJelenlevokWithProxies() {
	int total = 0;
	for (Tarstulajdonos* tp : jelenlevok) {
		int total = std::accumulate(meghatalmazasok.begin(), meghatalmazasok.end(), tp->getHanyad(), SumMeghatis(tp));
		std::cout << total;
	}
}*/