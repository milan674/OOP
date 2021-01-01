#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Termek
{
	string name;
	int price;
public:
	Termek(string name, int price) : name(name), price(price) {};
	int getPrice() const { return price; }
	string getName() const { return name; }
	virtual void print() = 0;
};

class Mobil : public Termek {
	string imei;
public:
	Mobil(string name, int price, string imei) : Termek(name, price), imei(imei) {};
	void print() override {};
};

class Laptop : public Termek {
public:
	Laptop(string name, int price) : Termek(name, price) {};
	void print() override {};
};


bool operator==(Termek& t1, Termek& t2);

class OutOfKeszletError : public exception {
	string msg;
public:
	OutOfKeszletError(string msg) : msg(msg) {};
	string getMsg() const { return msg; }
};

class Keszlet { //singleton osztaly, egyszer lehet peldanyositani, static kell hogy legyen
	Keszlet() {};
	Keszlet(const Keszlet& other) = delete;
	Keszlet& operator= (const Keszlet&) = delete;
	static Keszlet* instance;
	std::vector <std::pair<Termek*, int>> termekek;
public:
	static Keszlet* GetInstance();
	void addTermek(Termek* termek, int db);
	int getQuantity(Termek* termek)  ;
	void  rendel(Termek* termek, int db);
	void checkedRendel(Termek* termek, int db);
	void addTermekChecked(Termek* termek, int db);

};

