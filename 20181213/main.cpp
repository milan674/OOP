/*

 

 ---- elégséges szint határa ----

 Mindegyik osztályt lehessen << operátorral ostream objektumra "küldeni" a fent leírt formai megkötések mellett.
 A Konyvtar osztalynak legyen [int idx] operátora, mely visszaad egy nem módosítható pointert az idx-edik elemre,
 ha az létezik, egyébként nullptr-t.
 A Konyvtar-nak legyen egy rendez() függvénye, mely a könyveket szerzõ, majd cím szerinti ABC sorrendbe rendezi.
 A Konyvtar-nak legyen egy [string sorozatcim] operátora, mely list<const Konyv*> formában
 visszaadja az ahhoz a sorozathoz tartozó könyvek listáját.

*/

#include "Konyvtar.h"
#include "Konyv.h"
#include "Kotet.h"

int main() {

	/* Kettes szint tesztelese */
	Konyvtar sajat;
	sajat.add(new Kotet("J. K. Rowling", "Harry Potter es az azkabani fogoly", 2009, "Harry Potter", 5));
	sajat.add(new Konyv("Fekete Istvan", "Vuk", 1993));
	sajat.add(new Kotet("J. K. Rowling", "Harry Potter es a titkok kamraja", 2003, "Harry Potter", 2));
	sajat.add(new Kotet("J. K. Rowling", "Harry Potter es a bolcsek kove", 2002, "Harry Potter", 1));
	sajat.add(new Konyv("Fekete Istvan", "Vuk", 1993));

	sajat.print();

	/* Tovabbi feladatok tesztelese */
	

	std::cout << "\n\nKonyvtar::db(string)\n";
	std::cout << "--------------------\n";
	std::cout << "A Vuk " << sajat.db("Fekete Istvan", "Vuk") << " peldanyban van meg\n";

	
	std::cout << "\n\nostream& << Konyv/Kotet\n";
	std::cout << "-----------------------\n";
	std::cout << Konyv("J. R. R. Tolkien", "Szilmarillok", 1986) << std::endl;
	std::cout << Kotet("Raymond E. Feist", "Magus a mester", 2003, "Reshaboru", 3) << std::endl;

	
	std::cout << "\n\nKonyvtar::operator[] (unsigned int)\n";
	std::cout << "-----------------------------------\n";
	for (unsigned int i = 0; i < 1000; i++) {
		if (sajat[i] != nullptr)
			std::cout << "Az " << i + 1 << ". konyvem: " << sajat[i]->toString() << std::endl;
		else
			break;
	}

	
	std::cout << "\n\nKonyvtar::rendez()\n";
	std::cout << "------------------\n";
	sajat.rendez();
	sajat.print();

	
	std::cout << "\n\nKonyvtar::operator[](string)\n";
	std::cout << "----------------------------\n";
	std::cout << "A Harry Potter sorozatbol megvan:\n";
	for (auto k : sajat["Harry Potter"])
		std::cout << " - " << *k << std::endl;

	
	return 0;

}