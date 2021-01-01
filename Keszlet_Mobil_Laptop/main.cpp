
#include <iostream>

#include "Termekek.h"

// K�sz�tsen programot mobiltelefonok �s laptopok lelt�ri nyilv�ntart�s�ra
// az al�bbiak szerint:
//
// A Laptop �s Mobil objektumok egyfajta Termekek
// A Laptop p�ld�nyos�t�sakor meg kell adni a laptop nev�t �s �r�t
// A Mobil p�ld�nyos�t�sakor meg kell adni a mobil nev�t, �r�t �s IMEI sz�m�t
//
// A Keszlet oszt�ly �gynevezett singleton oszt�ly:
// a) konstruktor�t k�v�lr�l nem lehet megh�vni
// b) copy konstruktor �s assignment le van tiltva
// c) kiz�r�lag a GetInstance() nev� statikus met�duson kereszt�l k�rhet� le egy p�ld�nya
//
// A Keszlet oszt�ly addTermek() met�dusa egy Termekre mutat� pointert �s egy darabsz�mot v�r
// -- ami a k�szleten fellelhet� darabok sz�m�t jelenti
// A Keszlet oszt�ly getQuantity() met�dusa egy Termekre mutat� pointert v�r, �s visszaadja, hogy
// az adott Termekb�l h�ny darab lelhet� fel a k�szletben

// 3-as jegy�rt:
// A Keszlet oszt�ly rendel() met�dusa egy Termekre mutat� pointert v�r, illetve egy darabsz�mot,
// �s a k�szleten fellelhet� darabok sz�m�t a megadott sz�mmal cs�kkenti (mintha annyit rendeltek volna)

// 4-es jegy�rt:
// K�sz�tsen a Keszlet oszt�lyhoz egy checkedRendel() met�dust, ami ugyan�gy egy Termekre mutat�
// pointert �s egy darabsz�mot v�r, viszont kiv�telt dob, ha nincs a k�szleten elegend� darab a term�kb�l

// 5-�s jegyz�rt:
// K�sz�tsen a Keszlet oszt�lyhoz egy addTermekChecked() met�dust, ami egy Termekre mutat� pointert v�r
// amennyiben az adott term�kkel azonos term�k m�r szerepel a nyilv�ntart�sban, annak darabsz�m�t n�velje �j
// Termek felv�tele helyett

// a megoldott feladatoknal allitsa 1-re a megfelelo pelda kodreszek bekapcsolasahoz
#define KETTES_SZINT 1
#define HARMAS_SZINT 1
#define NEGYES_SZINT 1
#define OTOS_SZINT 1

int main()
{
#if KETTES_SZINT

	// van ketfele termek: Laptop es Mobil
	// Termek absztrakt ososztaly, uh nem peldanyosithato:
	// Termek t("Gyarto", 2);  //nem mukodik, tehat jo igy
	Termek* laptop = new Laptop("Asus", 1000);
	Termek* mobil1 = new Mobil("Samsung", 80, "15-372612-847221-1");
	Termek* mobil2 = new Mobil("Samsung", 800, "62-882612-847221-1");
	Termek* mobil3 = new Mobil("Apple", 3000, "75-262612-847221-1");

	//Keszlet keszlet; // nem mukodik mert Keszlet singleton
	Keszlet* keszlet = Keszlet::GetInstance(); // GetInstance statikus valtozot hoz letre es ad vissza
	// Keszlet keszlet2 = *keszlet; // nem mukodik mert copy es assignment le van tiltva
	//Keszlet keszlet2(*keszlet); // nem mukodik, mert copy le van tiltva
	Keszlet* keszlet2 = Keszlet::GetInstance(); // mivel statikus valtozot ad vissza, csak 1x hozza letre
	if (keszlet == keszlet2) {
		std::cout << "Eljen eljen: ugyanaz a cim!!" << std::endl;
	}
	keszlet->addTermek(laptop, 15);
	keszlet->addTermek(mobil1, 9);
	keszlet->addTermek(mobil2, 23);

	std::cout << laptop->getName() << " " << keszlet->getQuantity(laptop) << " mennyisegben all rendelkezesre" << std::endl; // 15
	std::cout << mobil3->getName() << " " << keszlet->getQuantity(mobil3) << " mennyisegben all rendelkezesre" << std::endl; // 0


#if HARMAS_SZINT
	std::cout << "done" << std::endl;

	if (keszlet->getQuantity(laptop) > 5) {
		keszlet->rendel(laptop, 5);
		std::cout << laptop->getName() << " mar csak " << keszlet->getQuantity(laptop) << " mennyisegben all rendelkezesre" << std::endl; // 10
	}

#if NEGYES_SZINT
	try {
		keszlet->checkedRendel(laptop, 12);
	}
	catch (OutOfKeszletError e) {
		std::cout << e.getMsg() << std::endl; // kiirja h "nincs tobb a keszleten"
	}

#if OTOS_SZINT
	// u.az mint mobil2
	Termek* mobil4 = new Mobil("Samsung", 800, "62-882612-847221-1");
	// egyszer mar hozzadtunk mobil2-bol 23-at:
	keszlet->addTermekChecked(mobil4, 5); // vajon most 28 van belole?
	// az implementaciohoz operator== fv megvalositasa szukseges
	// + okosabb getQuantity is kell...
	std::cout << mobil4->getName() << " " << keszlet->getQuantity(mobil4) << " mennyisegben all rendelkezesre" << std::endl; // 28

	delete mobil4;
#endif

#endif

#endif

	delete laptop;
	delete mobil1;
	delete mobil2;
	delete mobil3;

#endif
	std::cin.get();
	return 0;
}