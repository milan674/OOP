#include "Termekek.h"
Keszlet* Keszlet::instance = 0;
Keszlet* Keszlet::GetInstance()
{
	if (instance == 0) {
		instance = new Keszlet();
	}
	return instance;
}

void Keszlet::addTermek(Termek* termek, int db)
{
	termekek.push_back(std::make_pair(termek, db));
}
/* kettes szint
int Keszlet::getQuantity(Termek* termek) const
{
	for (auto a : termekek) {
		if (a.first == termek) return a.second;
	}
	return 0;
}*/

// 5-os szinthez ez kell:
int Keszlet::getQuantity(Termek* t) {
	for (auto it =termekek.begin(); it != termekek.end(); ++it) {
		if (*((*it).first) == *t) {
			return (*it).second;
		}
	}
	return 0;
}

void Keszlet::rendel(Termek* termek,int db)
{
	int pos = 0;
	for (auto a : termekek) {
		if (a.first == termek) {
			a.second -= db;
			termekek[pos].second = a.second;
		}
		pos++;
	}
	return;
}

bool operator==(Termek& t1, Termek& t2)
{
	return t1.getName() == t2.getName() && t1.getPrice() == t2.getPrice();
}

void Keszlet::checkedRendel(Termek* termek, int db)
{
	int pos = 0;
	for (auto a : termekek) {
		if (a.first == termek) {
			if (a.second - db >= 0) {
				a.second -= db;
				termekek[pos].second = a.second;
			}
			else throw OutOfKeszletError("nincs tobb a keszleten!");
		}
		pos++;
	}
	return;
}


void Keszlet::addTermekChecked(Termek* t, int mennyiseg) {
	for (auto it = termekek.begin(); it != termekek.end(); ++it) {
		if (*(*it).first == *t) {
			(*it).second += mennyiseg;
			return;
		}
	}
	termekek.push_back(std::make_pair(t, mennyiseg));
}
